


object functionParser {
    val headerStr = "#define _GNU_SOURCE\n" +
                    "#include <GLES2/gl2.h>\n" +
                    "#include <dlfcn.h>\n" +
                    "#include <stdio.h>\n"
    val lookupStr = "typedef struct GLlookup {\n  char* Name;\n  void* functionPtr;\n} GLlookup;\n" +
                    "GLlookup lookup[GLMAXCOMMANDS];\n" +
                    "void addlookup(int index, char* name) {\n  lookup[index].Name = name;  lookup[index].functionPtr = dlsym(RTLD_NEXT, name);\n}\n\n"

    var initStr = "__attribute__((constructor)) void init(void) { createmap(); }\n"

    def splitParamType(input : String) : (String, String) = {
        val in = input.trim
        val starIndex = in.lastIndexOf("*")
        if (starIndex != -1) {
            (in.slice(0,starIndex+1), in.slice(starIndex+1, in.length))
        } else {
            val spaceIndex = in.lastIndexOf(" ");
            (in.slice(0,spaceIndex), in.slice(spaceIndex+1, in.length))
        }
    }
    def expandParams(name: String, input: Array[String]) : (String,String,String) = {
        var paramArgs = ""
        var paramValues = ""
        var paramTypes = ""
        for (i <- input) {

            var spl = splitParamType(i.trim)
            var fmt = "%d"
            spl._1 match {
                case "GLuint" => fmt = "%u"
                case "GLfloat" => fmt = "%f"
                case "GLsizei" | "GLenum" | "GLint" | "GLboolean" | "GLbitfield" => fmt = "%d"
                case "const GLchar *" => fmt = "\\\"%s\\\""
                case _ => fmt = "0x%p"
            }

            var webGLFmt = ""
            spl._2 match {
                case "shader" => webGLFmt = "shaders[" + fmt + "]"
                case "program" => webGLFmt = "programs[" + fmt + "]"  
                case "location"| "index" => {
                    if (name.contains("Attrib")) {
                        webGLFmt = "attribs[" + fmt + "]"  
                    } else {
                        webGLFmt = "uniforms[" + fmt + "]"
                    }
                }
                case _ => webGLFmt = fmt
            }

            paramTypes += spl._1 + ","
            paramArgs += webGLFmt + ","
            paramValues += spl._2 + ","
        }
        paramTypes = paramTypes.slice(0, paramTypes.length-1)
        paramArgs = paramArgs.slice(0, paramArgs.length-1)
        paramValues = paramValues.slice(0, paramValues.length-1)
        (paramTypes, paramArgs, paramValues)
    }

    def webGLName(name : String) = name(2).toLower + name.substring(3, name.length)


    def handleReturnType(retType : String) : (String, String) = {
        val rt = retType.trim;
        var preStatement = ""
        var postStatement = ""
        if (retType.trim != "void") {
            preStatement = rt + " res = "
            postStatement = "return res;\n"
        }
        (preStatement, postStatement)
    }

    def fnShaderSource() : String = {
        "printf(\"var ss = `%s`;\\n\", string[0]);\n" + 
        "printf(\"gl.shaderSource(shaders[%u], ss);\\n\",shader);\n"
    }

    def fnUniformFloatMatrix(i :String, webGLName : String) = {
        val sz = i.toInt * i.toInt
        var output = "printf(\"val values = {\");\n"
        output += "int i;\n"
        output += "for (i = 0; i< " + sz + "; ++i) { if (i!=0) {printf(\",\");};printf(\"%f\",value[i]); }\n"
        output += "printf(\"};\");"
        output += "printf(\"gl." + webGLName + "(uniforms[%d], transpose, new Float32Array(values) );\", location);\n" 
        output
    }

    def webGLOutput(fnName : String, retType : String, webGLParamFormatString : String, paramValueString: String, addComma : String) : String = {
        var output : String = ""
        val wglName = webGLName(fnName)

        val uniformFloatMatrixPattern  = "glUniformMatrix(.)fv".r
        fnName match {
            case "glShaderSource" => fnShaderSource()
            case uniformFloatMatrixPattern(p) => fnUniformFloatMatrix(p, wglName)

            case _ => {

                var preStatement : String = ""
                var postStatement : String = ""

                retType.trim match {
                    case "void" => {}
                    case "GLuint" => {
                        preStatement = "id = "
                        fnName match {
                            case "glCreateShader" => postStatement = "shaders[%d] = id;"
                            case "glCreateProgram" => postStatement = "programs[%d] = id;"
                            case _ => {}
                        }

                    }
                    case "GLint" => {
                        preStatement = "location = "
                        fnName match {
                            case "glGetAttribLocation" => postStatement = "attribs[%d] = location;"
                            case "glGetUniformLocation" => postStatement = "uniforms[%d] = location;"
                            case _ => {}
                        }

                    }

                    case _ =>
                }
                val mainStatement : String = "printf(\"" + preStatement + " gl."+ wglName + "(" + webGLParamFormatString + ");\\n\"" + addComma + paramValueString + ");\n"

                output += mainStatement
                if (postStatement.length > 0) {
                    postStatement = "printf(\"" + postStatement + "\");\n"
                }
                output += postStatement
                output
            }
        }
    }

    def parseFunction(inString : String) : (String, String, String) = {
        var inputorig = inString.replace(";","")
        var input = inputorig.replace("GL_APICALL","")
        input = input.replace("GL_APIENTRY","")
        var s = input.split("\\(|\\)|;")
        var t = splitParamType(s(0))
        val retType = t._1.trim
        val name = t._2.trim

        

        val upperName = name.toUpperCase
        var p = s(1)
        var q = p.split(",")
        var output = inputorig+"\n"
        output += "{\n"

        var webGLParamFormatString = ""
        var paramValueString = ""
        var glParamFormatString  = ""
        var addComma = ""
        if (! (q.length==1 && q(0).trim == "void" )) 
        {
            var expandedParams = expandParams(name, q)
            glParamFormatString = expandedParams._1
            webGLParamFormatString = expandedParams._2
            paramValueString = expandedParams._3
            addComma = ","
        }
        output += "  "
        val pl = handleReturnType(retType)
        output += pl._1
        output += "(("+retType+"(*)(" + glParamFormatString + "))lookup["+upperName+"].functionPtr)("+ paramValueString +");\n"       
        
        output += "  " + webGLOutput(name, retType, webGLParamFormatString, paramValueString, addComma)

        output += "\n"+ "  " + pl._2

        output += "}\n"
        (upperName, name, output)
    }

    def main(args: Array[String]) {
        var enumdefs = "enum GLCommands {\n";
        var createMap = "void createmap(){\n";
        var fndefs = ""
        for (ln <- io.Source.stdin.getLines) {
            var res = parseFunction(ln)
            enumdefs += "  " + res._1 + ",\n"
            createMap += "  addlookup("+res._1+",\""+res._2+"\");\n"
            fndefs += res._3
        }
        enumdefs += "  GLMAXCOMMANDS\n};\n"
        createMap += "}\n"
        print(headerStr)
        print(enumdefs)
        print("\n")
        print(lookupStr)
        print(createMap)
        print("\n")
        print(fndefs)
        print("\n")
        print(initStr)
    }
}

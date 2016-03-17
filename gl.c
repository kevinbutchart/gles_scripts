#define _GNU_SOURCE
#include <GLES2/gl2.h>
#include <dlfcn.h>
#include <stdio.h>
enum GLCommands {
  GLACTIVETEXTURE,
  GLATTACHSHADER,
  GLBINDATTRIBLOCATION,
  GLBINDBUFFER,
  GLBINDFRAMEBUFFER,
  GLBINDRENDERBUFFER,
  GLBINDTEXTURE,
  GLBLENDCOLOR,
  GLBLENDEQUATION,
  GLBLENDEQUATIONSEPARATE,
  GLBLENDFUNC,
  GLBLENDFUNCSEPARATE,
  GLBUFFERDATA,
  GLBUFFERSUBDATA,
  GLCHECKFRAMEBUFFERSTATUS,
  GLCLEAR,
  GLCLEARCOLOR,
  GLCLEARDEPTHF,
  GLCLEARSTENCIL,
  GLCOLORMASK,
  GLCOMPILESHADER,
  GLCOMPRESSEDTEXIMAGE2D,
  GLCOMPRESSEDTEXSUBIMAGE2D,
  GLCOPYTEXIMAGE2D,
  GLCOPYTEXSUBIMAGE2D,
  GLCREATEPROGRAM,
  GLCREATESHADER,
  GLCULLFACE,
  GLDELETEBUFFERS,
  GLDELETEFRAMEBUFFERS,
  GLDELETEPROGRAM,
  GLDELETERENDERBUFFERS,
  GLDELETESHADER,
  GLDELETETEXTURES,
  GLDEPTHFUNC,
  GLDEPTHMASK,
  GLDEPTHRANGEF,
  GLDETACHSHADER,
  GLDISABLE,
  GLDISABLEVERTEXATTRIBARRAY,
  GLDRAWARRAYS,
  GLDRAWELEMENTS,
  GLENABLE,
  GLENABLEVERTEXATTRIBARRAY,
  GLFINISH,
  GLFLUSH,
  GLFRAMEBUFFERRENDERBUFFER,
  GLFRAMEBUFFERTEXTURE2D,
  GLFRONTFACE,
  GLGENBUFFERS,
  GLGENERATEMIPMAP,
  GLGENFRAMEBUFFERS,
  GLGENRENDERBUFFERS,
  GLGENTEXTURES,
  GLGETACTIVEATTRIB,
  GLGETACTIVEUNIFORM,
  GLGETATTACHEDSHADERS,
  GLGETATTRIBLOCATION,
  GLGETBOOLEANV,
  GLGETBUFFERPARAMETERIV,
  GLGETERROR,
  GLGETFLOATV,
  GLGETFRAMEBUFFERATTACHMENTPARAMETERIV,
  GLGETINTEGERV,
  GLGETPROGRAMIV,
  GLGETPROGRAMINFOLOG,
  GLGETRENDERBUFFERPARAMETERIV,
  GLGETSHADERIV,
  GLGETSHADERINFOLOG,
  GLGETSHADERPRECISIONFORMAT,
  GLGETSHADERSOURCE,
  GLGETSTRING,
  GLGETTEXPARAMETERFV,
  GLGETTEXPARAMETERIV,
  GLGETUNIFORMFV,
  GLGETUNIFORMIV,
  GLGETUNIFORMLOCATION,
  GLGETVERTEXATTRIBFV,
  GLGETVERTEXATTRIBIV,
  GLGETVERTEXATTRIBPOINTERV,
  GLHINT,
  GLISBUFFER,
  GLISENABLED,
  GLISFRAMEBUFFER,
  GLISPROGRAM,
  GLISRENDERBUFFER,
  GLISSHADER,
  GLISTEXTURE,
  GLLINEWIDTH,
  GLLINKPROGRAM,
  GLPIXELSTOREI,
  GLPOLYGONOFFSET,
  GLREADPIXELS,
  GLRELEASESHADERCOMPILER,
  GLRENDERBUFFERSTORAGE,
  GLSAMPLECOVERAGE,
  GLSCISSOR,
  GLSHADERBINARY,
  GLSHADERSOURCE,
  GLSTENCILFUNC,
  GLSTENCILFUNCSEPARATE,
  GLSTENCILMASK,
  GLSTENCILMASKSEPARATE,
  GLSTENCILOP,
  GLSTENCILOPSEPARATE,
  GLTEXIMAGE2D,
  GLTEXPARAMETERF,
  GLTEXPARAMETERFV,
  GLTEXPARAMETERI,
  GLTEXPARAMETERIV,
  GLTEXSUBIMAGE2D,
  GLUNIFORM1F,
  GLUNIFORM1FV,
  GLUNIFORM1I,
  GLUNIFORM1IV,
  GLUNIFORM2F,
  GLUNIFORM2FV,
  GLUNIFORM2I,
  GLUNIFORM2IV,
  GLUNIFORM3F,
  GLUNIFORM3FV,
  GLUNIFORM3I,
  GLUNIFORM3IV,
  GLUNIFORM4F,
  GLUNIFORM4FV,
  GLUNIFORM4I,
  GLUNIFORM4IV,
  GLUNIFORMMATRIX2FV,
  GLUNIFORMMATRIX3FV,
  GLUNIFORMMATRIX4FV,
  GLUSEPROGRAM,
  GLVALIDATEPROGRAM,
  GLVERTEXATTRIB1F,
  GLVERTEXATTRIB1FV,
  GLVERTEXATTRIB2F,
  GLVERTEXATTRIB2FV,
  GLVERTEXATTRIB3F,
  GLVERTEXATTRIB3FV,
  GLVERTEXATTRIB4F,
  GLVERTEXATTRIB4FV,
  GLVERTEXATTRIBPOINTER,
  GLVIEWPORT,
  GLMAXCOMMANDS
};

typedef struct GLlookup {
  char* Name;
  void* functionPtr;
} GLlookup;
GLlookup lookup[GLMAXCOMMANDS];
void addlookup(int index, char* name) {
  lookup[index].Name = name;  lookup[index].functionPtr = dlsym(RTLD_NEXT, name);
}

void createmap(){
  addlookup(GLACTIVETEXTURE,"glActiveTexture");
  addlookup(GLATTACHSHADER,"glAttachShader");
  addlookup(GLBINDATTRIBLOCATION,"glBindAttribLocation");
  addlookup(GLBINDBUFFER,"glBindBuffer");
  addlookup(GLBINDFRAMEBUFFER,"glBindFramebuffer");
  addlookup(GLBINDRENDERBUFFER,"glBindRenderbuffer");
  addlookup(GLBINDTEXTURE,"glBindTexture");
  addlookup(GLBLENDCOLOR,"glBlendColor");
  addlookup(GLBLENDEQUATION,"glBlendEquation");
  addlookup(GLBLENDEQUATIONSEPARATE,"glBlendEquationSeparate");
  addlookup(GLBLENDFUNC,"glBlendFunc");
  addlookup(GLBLENDFUNCSEPARATE,"glBlendFuncSeparate");
  addlookup(GLBUFFERDATA,"glBufferData");
  addlookup(GLBUFFERSUBDATA,"glBufferSubData");
  addlookup(GLCHECKFRAMEBUFFERSTATUS,"glCheckFramebufferStatus");
  addlookup(GLCLEAR,"glClear");
  addlookup(GLCLEARCOLOR,"glClearColor");
  addlookup(GLCLEARDEPTHF,"glClearDepthf");
  addlookup(GLCLEARSTENCIL,"glClearStencil");
  addlookup(GLCOLORMASK,"glColorMask");
  addlookup(GLCOMPILESHADER,"glCompileShader");
  addlookup(GLCOMPRESSEDTEXIMAGE2D,"glCompressedTexImage2D");
  addlookup(GLCOMPRESSEDTEXSUBIMAGE2D,"glCompressedTexSubImage2D");
  addlookup(GLCOPYTEXIMAGE2D,"glCopyTexImage2D");
  addlookup(GLCOPYTEXSUBIMAGE2D,"glCopyTexSubImage2D");
  addlookup(GLCREATEPROGRAM,"glCreateProgram");
  addlookup(GLCREATESHADER,"glCreateShader");
  addlookup(GLCULLFACE,"glCullFace");
  addlookup(GLDELETEBUFFERS,"glDeleteBuffers");
  addlookup(GLDELETEFRAMEBUFFERS,"glDeleteFramebuffers");
  addlookup(GLDELETEPROGRAM,"glDeleteProgram");
  addlookup(GLDELETERENDERBUFFERS,"glDeleteRenderbuffers");
  addlookup(GLDELETESHADER,"glDeleteShader");
  addlookup(GLDELETETEXTURES,"glDeleteTextures");
  addlookup(GLDEPTHFUNC,"glDepthFunc");
  addlookup(GLDEPTHMASK,"glDepthMask");
  addlookup(GLDEPTHRANGEF,"glDepthRangef");
  addlookup(GLDETACHSHADER,"glDetachShader");
  addlookup(GLDISABLE,"glDisable");
  addlookup(GLDISABLEVERTEXATTRIBARRAY,"glDisableVertexAttribArray");
  addlookup(GLDRAWARRAYS,"glDrawArrays");
  addlookup(GLDRAWELEMENTS,"glDrawElements");
  addlookup(GLENABLE,"glEnable");
  addlookup(GLENABLEVERTEXATTRIBARRAY,"glEnableVertexAttribArray");
  addlookup(GLFINISH,"glFinish");
  addlookup(GLFLUSH,"glFlush");
  addlookup(GLFRAMEBUFFERRENDERBUFFER,"glFramebufferRenderbuffer");
  addlookup(GLFRAMEBUFFERTEXTURE2D,"glFramebufferTexture2D");
  addlookup(GLFRONTFACE,"glFrontFace");
  addlookup(GLGENBUFFERS,"glGenBuffers");
  addlookup(GLGENERATEMIPMAP,"glGenerateMipmap");
  addlookup(GLGENFRAMEBUFFERS,"glGenFramebuffers");
  addlookup(GLGENRENDERBUFFERS,"glGenRenderbuffers");
  addlookup(GLGENTEXTURES,"glGenTextures");
  addlookup(GLGETACTIVEATTRIB,"glGetActiveAttrib");
  addlookup(GLGETACTIVEUNIFORM,"glGetActiveUniform");
  addlookup(GLGETATTACHEDSHADERS,"glGetAttachedShaders");
  addlookup(GLGETATTRIBLOCATION,"glGetAttribLocation");
  addlookup(GLGETBOOLEANV,"glGetBooleanv");
  addlookup(GLGETBUFFERPARAMETERIV,"glGetBufferParameteriv");
  addlookup(GLGETERROR,"glGetError");
  addlookup(GLGETFLOATV,"glGetFloatv");
  addlookup(GLGETFRAMEBUFFERATTACHMENTPARAMETERIV,"glGetFramebufferAttachmentParameteriv");
  addlookup(GLGETINTEGERV,"glGetIntegerv");
  addlookup(GLGETPROGRAMIV,"glGetProgramiv");
  addlookup(GLGETPROGRAMINFOLOG,"glGetProgramInfoLog");
  addlookup(GLGETRENDERBUFFERPARAMETERIV,"glGetRenderbufferParameteriv");
  addlookup(GLGETSHADERIV,"glGetShaderiv");
  addlookup(GLGETSHADERINFOLOG,"glGetShaderInfoLog");
  addlookup(GLGETSHADERPRECISIONFORMAT,"glGetShaderPrecisionFormat");
  addlookup(GLGETSHADERSOURCE,"glGetShaderSource");
  addlookup(GLGETSTRING,"glGetString");
  addlookup(GLGETTEXPARAMETERFV,"glGetTexParameterfv");
  addlookup(GLGETTEXPARAMETERIV,"glGetTexParameteriv");
  addlookup(GLGETUNIFORMFV,"glGetUniformfv");
  addlookup(GLGETUNIFORMIV,"glGetUniformiv");
  addlookup(GLGETUNIFORMLOCATION,"glGetUniformLocation");
  addlookup(GLGETVERTEXATTRIBFV,"glGetVertexAttribfv");
  addlookup(GLGETVERTEXATTRIBIV,"glGetVertexAttribiv");
  addlookup(GLGETVERTEXATTRIBPOINTERV,"glGetVertexAttribPointerv");
  addlookup(GLHINT,"glHint");
  addlookup(GLISBUFFER,"glIsBuffer");
  addlookup(GLISENABLED,"glIsEnabled");
  addlookup(GLISFRAMEBUFFER,"glIsFramebuffer");
  addlookup(GLISPROGRAM,"glIsProgram");
  addlookup(GLISRENDERBUFFER,"glIsRenderbuffer");
  addlookup(GLISSHADER,"glIsShader");
  addlookup(GLISTEXTURE,"glIsTexture");
  addlookup(GLLINEWIDTH,"glLineWidth");
  addlookup(GLLINKPROGRAM,"glLinkProgram");
  addlookup(GLPIXELSTOREI,"glPixelStorei");
  addlookup(GLPOLYGONOFFSET,"glPolygonOffset");
  addlookup(GLREADPIXELS,"glReadPixels");
  addlookup(GLRELEASESHADERCOMPILER,"glReleaseShaderCompiler");
  addlookup(GLRENDERBUFFERSTORAGE,"glRenderbufferStorage");
  addlookup(GLSAMPLECOVERAGE,"glSampleCoverage");
  addlookup(GLSCISSOR,"glScissor");
  addlookup(GLSHADERBINARY,"glShaderBinary");
  addlookup(GLSHADERSOURCE,"glShaderSource");
  addlookup(GLSTENCILFUNC,"glStencilFunc");
  addlookup(GLSTENCILFUNCSEPARATE,"glStencilFuncSeparate");
  addlookup(GLSTENCILMASK,"glStencilMask");
  addlookup(GLSTENCILMASKSEPARATE,"glStencilMaskSeparate");
  addlookup(GLSTENCILOP,"glStencilOp");
  addlookup(GLSTENCILOPSEPARATE,"glStencilOpSeparate");
  addlookup(GLTEXIMAGE2D,"glTexImage2D");
  addlookup(GLTEXPARAMETERF,"glTexParameterf");
  addlookup(GLTEXPARAMETERFV,"glTexParameterfv");
  addlookup(GLTEXPARAMETERI,"glTexParameteri");
  addlookup(GLTEXPARAMETERIV,"glTexParameteriv");
  addlookup(GLTEXSUBIMAGE2D,"glTexSubImage2D");
  addlookup(GLUNIFORM1F,"glUniform1f");
  addlookup(GLUNIFORM1FV,"glUniform1fv");
  addlookup(GLUNIFORM1I,"glUniform1i");
  addlookup(GLUNIFORM1IV,"glUniform1iv");
  addlookup(GLUNIFORM2F,"glUniform2f");
  addlookup(GLUNIFORM2FV,"glUniform2fv");
  addlookup(GLUNIFORM2I,"glUniform2i");
  addlookup(GLUNIFORM2IV,"glUniform2iv");
  addlookup(GLUNIFORM3F,"glUniform3f");
  addlookup(GLUNIFORM3FV,"glUniform3fv");
  addlookup(GLUNIFORM3I,"glUniform3i");
  addlookup(GLUNIFORM3IV,"glUniform3iv");
  addlookup(GLUNIFORM4F,"glUniform4f");
  addlookup(GLUNIFORM4FV,"glUniform4fv");
  addlookup(GLUNIFORM4I,"glUniform4i");
  addlookup(GLUNIFORM4IV,"glUniform4iv");
  addlookup(GLUNIFORMMATRIX2FV,"glUniformMatrix2fv");
  addlookup(GLUNIFORMMATRIX3FV,"glUniformMatrix3fv");
  addlookup(GLUNIFORMMATRIX4FV,"glUniformMatrix4fv");
  addlookup(GLUSEPROGRAM,"glUseProgram");
  addlookup(GLVALIDATEPROGRAM,"glValidateProgram");
  addlookup(GLVERTEXATTRIB1F,"glVertexAttrib1f");
  addlookup(GLVERTEXATTRIB1FV,"glVertexAttrib1fv");
  addlookup(GLVERTEXATTRIB2F,"glVertexAttrib2f");
  addlookup(GLVERTEXATTRIB2FV,"glVertexAttrib2fv");
  addlookup(GLVERTEXATTRIB3F,"glVertexAttrib3f");
  addlookup(GLVERTEXATTRIB3FV,"glVertexAttrib3fv");
  addlookup(GLVERTEXATTRIB4F,"glVertexAttrib4f");
  addlookup(GLVERTEXATTRIB4FV,"glVertexAttrib4fv");
  addlookup(GLVERTEXATTRIBPOINTER,"glVertexAttribPointer");
  addlookup(GLVIEWPORT,"glViewport");
}

GL_APICALL void GL_APIENTRY glActiveTexture (GLenum texture)
{
  ((void(*)(GLenum))lookup[GLACTIVETEXTURE].functionPtr)(texture);
  printf(" gl.activeTexture(%d);\n",texture);

  }
GL_APICALL void GL_APIENTRY glAttachShader (GLuint program, GLuint shader)
{
  ((void(*)(GLuint,GLuint))lookup[GLATTACHSHADER].functionPtr)(program,shader);
  printf(" gl.attachShader(programs[%u],shaders[%u]);\n",program,shader);

  }
GL_APICALL void GL_APIENTRY glBindAttribLocation (GLuint program, GLuint index, const GLchar *name)
{
  ((void(*)(GLuint,GLuint,const GLchar *))lookup[GLBINDATTRIBLOCATION].functionPtr)(program,index,name);
  printf(" gl.bindAttribLocation(programs[%u],attribs[%u],\"%s\");\n",program,index,name);

  }
GL_APICALL void GL_APIENTRY glBindBuffer (GLenum target, GLuint buffer)
{
  ((void(*)(GLenum,GLuint))lookup[GLBINDBUFFER].functionPtr)(target,buffer);
  printf(" gl.bindBuffer(%d,%u);\n",target,buffer);

  }
GL_APICALL void GL_APIENTRY glBindFramebuffer (GLenum target, GLuint framebuffer)
{
  ((void(*)(GLenum,GLuint))lookup[GLBINDFRAMEBUFFER].functionPtr)(target,framebuffer);
  printf(" gl.bindFramebuffer(%d,%u);\n",target,framebuffer);

  }
GL_APICALL void GL_APIENTRY glBindRenderbuffer (GLenum target, GLuint renderbuffer)
{
  ((void(*)(GLenum,GLuint))lookup[GLBINDRENDERBUFFER].functionPtr)(target,renderbuffer);
  printf(" gl.bindRenderbuffer(%d,%u);\n",target,renderbuffer);

  }
GL_APICALL void GL_APIENTRY glBindTexture (GLenum target, GLuint texture)
{
  ((void(*)(GLenum,GLuint))lookup[GLBINDTEXTURE].functionPtr)(target,texture);
  printf(" gl.bindTexture(%d,%u);\n",target,texture);

  }
GL_APICALL void GL_APIENTRY glBlendColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  ((void(*)(GLfloat,GLfloat,GLfloat,GLfloat))lookup[GLBLENDCOLOR].functionPtr)(red,green,blue,alpha);
  printf(" gl.blendColor(%f,%f,%f,%f);\n",red,green,blue,alpha);

  }
GL_APICALL void GL_APIENTRY glBlendEquation (GLenum mode)
{
  ((void(*)(GLenum))lookup[GLBLENDEQUATION].functionPtr)(mode);
  printf(" gl.blendEquation(%d);\n",mode);

  }
GL_APICALL void GL_APIENTRY glBlendEquationSeparate (GLenum modeRGB, GLenum modeAlpha)
{
  ((void(*)(GLenum,GLenum))lookup[GLBLENDEQUATIONSEPARATE].functionPtr)(modeRGB,modeAlpha);
  printf(" gl.blendEquationSeparate(%d,%d);\n",modeRGB,modeAlpha);

  }
GL_APICALL void GL_APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor)
{
  ((void(*)(GLenum,GLenum))lookup[GLBLENDFUNC].functionPtr)(sfactor,dfactor);
  printf(" gl.blendFunc(%d,%d);\n",sfactor,dfactor);

  }
GL_APICALL void GL_APIENTRY glBlendFuncSeparate (GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha)
{
  ((void(*)(GLenum,GLenum,GLenum,GLenum))lookup[GLBLENDFUNCSEPARATE].functionPtr)(sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);
  printf(" gl.blendFuncSeparate(%d,%d,%d,%d);\n",sfactorRGB,dfactorRGB,sfactorAlpha,dfactorAlpha);

  }
GL_APICALL void GL_APIENTRY glBufferData (GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
  ((void(*)(GLenum,GLsizeiptr,const void *,GLenum))lookup[GLBUFFERDATA].functionPtr)(target,size,data,usage);
  printf(" gl.bufferData(%d,0x%p,0x%p,%d);\n",target,size,data,usage);

  }
GL_APICALL void GL_APIENTRY glBufferSubData (GLenum target, GLintptr offset, GLsizeiptr size, const void *data)
{
  ((void(*)(GLenum,GLintptr,GLsizeiptr,const void *))lookup[GLBUFFERSUBDATA].functionPtr)(target,offset,size,data);
  printf(" gl.bufferSubData(%d,0x%p,0x%p,0x%p);\n",target,offset,size,data);

  }
GL_APICALL GLenum GL_APIENTRY glCheckFramebufferStatus (GLenum target)
{
  GLenum res = ((GLenum(*)(GLenum))lookup[GLCHECKFRAMEBUFFERSTATUS].functionPtr)(target);
  printf(" gl.checkFramebufferStatus(%d);\n",target);

  return res;
}
GL_APICALL void GL_APIENTRY glClear (GLbitfield mask)
{
  ((void(*)(GLbitfield))lookup[GLCLEAR].functionPtr)(mask);
  printf(" gl.clear(%d);\n",mask);

  }
GL_APICALL void GL_APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
  ((void(*)(GLfloat,GLfloat,GLfloat,GLfloat))lookup[GLCLEARCOLOR].functionPtr)(red,green,blue,alpha);
  printf(" gl.clearColor(%f,%f,%f,%f);\n",red,green,blue,alpha);

  }
GL_APICALL void GL_APIENTRY glClearDepthf (GLfloat d)
{
  ((void(*)(GLfloat))lookup[GLCLEARDEPTHF].functionPtr)(d);
  printf(" gl.clearDepthf(%f);\n",d);

  }
GL_APICALL void GL_APIENTRY glClearStencil (GLint s)
{
  ((void(*)(GLint))lookup[GLCLEARSTENCIL].functionPtr)(s);
  printf(" gl.clearStencil(%d);\n",s);

  }
GL_APICALL void GL_APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha)
{
  ((void(*)(GLboolean,GLboolean,GLboolean,GLboolean))lookup[GLCOLORMASK].functionPtr)(red,green,blue,alpha);
  printf(" gl.colorMask(%d,%d,%d,%d);\n",red,green,blue,alpha);

  }
GL_APICALL void GL_APIENTRY glCompileShader (GLuint shader)
{
  ((void(*)(GLuint))lookup[GLCOMPILESHADER].functionPtr)(shader);
  printf(" gl.compileShader(shaders[%u]);\n",shader);

  }
GL_APICALL void GL_APIENTRY glCompressedTexImage2D (GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
  ((void(*)(GLenum,GLint,GLenum,GLsizei,GLsizei,GLint,GLsizei,const void *))lookup[GLCOMPRESSEDTEXIMAGE2D].functionPtr)(target,level,internalformat,width,height,border,imageSize,data);
  printf(" gl.compressedTexImage2D(%d,%d,%d,%d,%d,%d,%d,0x%p);\n",target,level,internalformat,width,height,border,imageSize,data);

  }
GL_APICALL void GL_APIENTRY glCompressedTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
  ((void(*)(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLsizei,const void *))lookup[GLCOMPRESSEDTEXSUBIMAGE2D].functionPtr)(target,level,xoffset,yoffset,width,height,format,imageSize,data);
  printf(" gl.compressedTexSubImage2D(%d,%d,%d,%d,%d,%d,%d,%d,0x%p);\n",target,level,xoffset,yoffset,width,height,format,imageSize,data);

  }
GL_APICALL void GL_APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border)
{
  ((void(*)(GLenum,GLint,GLenum,GLint,GLint,GLsizei,GLsizei,GLint))lookup[GLCOPYTEXIMAGE2D].functionPtr)(target,level,internalformat,x,y,width,height,border);
  printf(" gl.copyTexImage2D(%d,%d,%d,%d,%d,%d,%d,%d);\n",target,level,internalformat,x,y,width,height,border);

  }
GL_APICALL void GL_APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height)
{
  ((void(*)(GLenum,GLint,GLint,GLint,GLint,GLint,GLsizei,GLsizei))lookup[GLCOPYTEXSUBIMAGE2D].functionPtr)(target,level,xoffset,yoffset,x,y,width,height);
  printf(" gl.copyTexSubImage2D(%d,%d,%d,%d,%d,%d,%d,%d);\n",target,level,xoffset,yoffset,x,y,width,height);

  }
GL_APICALL GLuint GL_APIENTRY glCreateProgram (void)
{
  GLuint res = ((GLuint(*)())lookup[GLCREATEPROGRAM].functionPtr)();
  printf("id =  gl.createProgram();\n");
printf("programs[%d] = id;");

  return res;
}
GL_APICALL GLuint GL_APIENTRY glCreateShader (GLenum type)
{
  GLuint res = ((GLuint(*)(GLenum))lookup[GLCREATESHADER].functionPtr)(type);
  printf("id =  gl.createShader(%d);\n",type);
printf("shaders[%d] = id;");

  return res;
}
GL_APICALL void GL_APIENTRY glCullFace (GLenum mode)
{
  ((void(*)(GLenum))lookup[GLCULLFACE].functionPtr)(mode);
  printf(" gl.cullFace(%d);\n",mode);

  }
GL_APICALL void GL_APIENTRY glDeleteBuffers (GLsizei n, const GLuint *buffers)
{
  ((void(*)(GLsizei,const GLuint *))lookup[GLDELETEBUFFERS].functionPtr)(n,buffers);
  printf(" gl.deleteBuffers(%d,0x%p);\n",n,buffers);

  }
GL_APICALL void GL_APIENTRY glDeleteFramebuffers (GLsizei n, const GLuint *framebuffers)
{
  ((void(*)(GLsizei,const GLuint *))lookup[GLDELETEFRAMEBUFFERS].functionPtr)(n,framebuffers);
  printf(" gl.deleteFramebuffers(%d,0x%p);\n",n,framebuffers);

  }
GL_APICALL void GL_APIENTRY glDeleteProgram (GLuint program)
{
  ((void(*)(GLuint))lookup[GLDELETEPROGRAM].functionPtr)(program);
  printf(" gl.deleteProgram(programs[%u]);\n",program);

  }
GL_APICALL void GL_APIENTRY glDeleteRenderbuffers (GLsizei n, const GLuint *renderbuffers)
{
  ((void(*)(GLsizei,const GLuint *))lookup[GLDELETERENDERBUFFERS].functionPtr)(n,renderbuffers);
  printf(" gl.deleteRenderbuffers(%d,0x%p);\n",n,renderbuffers);

  }
GL_APICALL void GL_APIENTRY glDeleteShader (GLuint shader)
{
  ((void(*)(GLuint))lookup[GLDELETESHADER].functionPtr)(shader);
  printf(" gl.deleteShader(shaders[%u]);\n",shader);

  }
GL_APICALL void GL_APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures)
{
  ((void(*)(GLsizei,const GLuint *))lookup[GLDELETETEXTURES].functionPtr)(n,textures);
  printf(" gl.deleteTextures(%d,0x%p);\n",n,textures);

  }
GL_APICALL void GL_APIENTRY glDepthFunc (GLenum func)
{
  ((void(*)(GLenum))lookup[GLDEPTHFUNC].functionPtr)(func);
  printf(" gl.depthFunc(%d);\n",func);

  }
GL_APICALL void GL_APIENTRY glDepthMask (GLboolean flag)
{
  ((void(*)(GLboolean))lookup[GLDEPTHMASK].functionPtr)(flag);
  printf(" gl.depthMask(%d);\n",flag);

  }
GL_APICALL void GL_APIENTRY glDepthRangef (GLfloat n, GLfloat f)
{
  ((void(*)(GLfloat,GLfloat))lookup[GLDEPTHRANGEF].functionPtr)(n,f);
  printf(" gl.depthRangef(%f,%f);\n",n,f);

  }
GL_APICALL void GL_APIENTRY glDetachShader (GLuint program, GLuint shader)
{
  ((void(*)(GLuint,GLuint))lookup[GLDETACHSHADER].functionPtr)(program,shader);
  printf(" gl.detachShader(programs[%u],shaders[%u]);\n",program,shader);

  }
GL_APICALL void GL_APIENTRY glDisable (GLenum cap)
{
  ((void(*)(GLenum))lookup[GLDISABLE].functionPtr)(cap);
  printf(" gl.disable(%d);\n",cap);

  }
GL_APICALL void GL_APIENTRY glDisableVertexAttribArray (GLuint index)
{
  ((void(*)(GLuint))lookup[GLDISABLEVERTEXATTRIBARRAY].functionPtr)(index);
  printf(" gl.disableVertexAttribArray(attribs[%u]);\n",index);

  }
GL_APICALL void GL_APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count)
{
  ((void(*)(GLenum,GLint,GLsizei))lookup[GLDRAWARRAYS].functionPtr)(mode,first,count);
  printf(" gl.drawArrays(%d,%d,%d);\n",mode,first,count);

  }
GL_APICALL void GL_APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices)
{
  ((void(*)(GLenum,GLsizei,GLenum,const void *))lookup[GLDRAWELEMENTS].functionPtr)(mode,count,type,indices);
  printf(" gl.drawElements(%d,%d,%d,0x%p);\n",mode,count,type,indices);

  }
GL_APICALL void GL_APIENTRY glEnable (GLenum cap)
{
  ((void(*)(GLenum))lookup[GLENABLE].functionPtr)(cap);
  printf(" gl.enable(%d);\n",cap);

  }
GL_APICALL void GL_APIENTRY glEnableVertexAttribArray (GLuint index)
{
  ((void(*)(GLuint))lookup[GLENABLEVERTEXATTRIBARRAY].functionPtr)(index);
  printf(" gl.enableVertexAttribArray(attribs[%u]);\n",index);

  }
GL_APICALL void GL_APIENTRY glFinish (void)
{
  ((void(*)())lookup[GLFINISH].functionPtr)();
  printf(" gl.finish();\n");

  }
GL_APICALL void GL_APIENTRY glFlush (void)
{
  ((void(*)())lookup[GLFLUSH].functionPtr)();
  printf(" gl.flush();\n");

  }
GL_APICALL void GL_APIENTRY glFramebufferRenderbuffer (GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
  ((void(*)(GLenum,GLenum,GLenum,GLuint))lookup[GLFRAMEBUFFERRENDERBUFFER].functionPtr)(target,attachment,renderbuffertarget,renderbuffer);
  printf(" gl.framebufferRenderbuffer(%d,%d,%d,%u);\n",target,attachment,renderbuffertarget,renderbuffer);

  }
GL_APICALL void GL_APIENTRY glFramebufferTexture2D (GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
  ((void(*)(GLenum,GLenum,GLenum,GLuint,GLint))lookup[GLFRAMEBUFFERTEXTURE2D].functionPtr)(target,attachment,textarget,texture,level);
  printf(" gl.framebufferTexture2D(%d,%d,%d,%u,%d);\n",target,attachment,textarget,texture,level);

  }
GL_APICALL void GL_APIENTRY glFrontFace (GLenum mode)
{
  ((void(*)(GLenum))lookup[GLFRONTFACE].functionPtr)(mode);
  printf(" gl.frontFace(%d);\n",mode);

  }
GL_APICALL void GL_APIENTRY glGenBuffers (GLsizei n, GLuint *buffers)
{
  ((void(*)(GLsizei,GLuint *))lookup[GLGENBUFFERS].functionPtr)(n,buffers);
  printf(" gl.genBuffers(%d,0x%p);\n",n,buffers);

  }
GL_APICALL void GL_APIENTRY glGenerateMipmap (GLenum target)
{
  ((void(*)(GLenum))lookup[GLGENERATEMIPMAP].functionPtr)(target);
  printf(" gl.generateMipmap(%d);\n",target);

  }
GL_APICALL void GL_APIENTRY glGenFramebuffers (GLsizei n, GLuint *framebuffers)
{
  ((void(*)(GLsizei,GLuint *))lookup[GLGENFRAMEBUFFERS].functionPtr)(n,framebuffers);
  printf(" gl.genFramebuffers(%d,0x%p);\n",n,framebuffers);

  }
GL_APICALL void GL_APIENTRY glGenRenderbuffers (GLsizei n, GLuint *renderbuffers)
{
  ((void(*)(GLsizei,GLuint *))lookup[GLGENRENDERBUFFERS].functionPtr)(n,renderbuffers);
  printf(" gl.genRenderbuffers(%d,0x%p);\n",n,renderbuffers);

  }
GL_APICALL void GL_APIENTRY glGenTextures (GLsizei n, GLuint *textures)
{
  ((void(*)(GLsizei,GLuint *))lookup[GLGENTEXTURES].functionPtr)(n,textures);
  printf(" gl.genTextures(%d,0x%p);\n",n,textures);

  }
GL_APICALL void GL_APIENTRY glGetActiveAttrib (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
  ((void(*)(GLuint,GLuint,GLsizei,GLsizei *,GLint *,GLenum *,GLchar *))lookup[GLGETACTIVEATTRIB].functionPtr)(program,index,bufSize,length,size,type,name);
  printf(" gl.getActiveAttrib(programs[%u],attribs[%u],%d,0x%p,0x%p,0x%p,0x%p);\n",program,index,bufSize,length,size,type,name);

  }
GL_APICALL void GL_APIENTRY glGetActiveUniform (GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name)
{
  ((void(*)(GLuint,GLuint,GLsizei,GLsizei *,GLint *,GLenum *,GLchar *))lookup[GLGETACTIVEUNIFORM].functionPtr)(program,index,bufSize,length,size,type,name);
  printf(" gl.getActiveUniform(programs[%u],uniforms[%u],%d,0x%p,0x%p,0x%p,0x%p);\n",program,index,bufSize,length,size,type,name);

  }
GL_APICALL void GL_APIENTRY glGetAttachedShaders (GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders)
{
  ((void(*)(GLuint,GLsizei,GLsizei *,GLuint *))lookup[GLGETATTACHEDSHADERS].functionPtr)(program,maxCount,count,shaders);
  printf(" gl.getAttachedShaders(programs[%u],%d,0x%p,0x%p);\n",program,maxCount,count,shaders);

  }
GL_APICALL GLint GL_APIENTRY glGetAttribLocation (GLuint program, const GLchar *name)
{
  GLint res = ((GLint(*)(GLuint,const GLchar *))lookup[GLGETATTRIBLOCATION].functionPtr)(program,name);
  printf("location =  gl.getAttribLocation(programs[%u],\"%s\");\n",program,name);
printf("attribs[%d] = location;");

  return res;
}
GL_APICALL void GL_APIENTRY glGetBooleanv (GLenum pname, GLboolean *data)
{
  ((void(*)(GLenum,GLboolean *))lookup[GLGETBOOLEANV].functionPtr)(pname,data);
  printf(" gl.getBooleanv(%d,0x%p);\n",pname,data);

  }
GL_APICALL void GL_APIENTRY glGetBufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
  ((void(*)(GLenum,GLenum,GLint *))lookup[GLGETBUFFERPARAMETERIV].functionPtr)(target,pname,params);
  printf(" gl.getBufferParameteriv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL GLenum GL_APIENTRY glGetError (void)
{
  GLenum res = ((GLenum(*)())lookup[GLGETERROR].functionPtr)();
  printf(" gl.getError();\n");

  return res;
}
GL_APICALL void GL_APIENTRY glGetFloatv (GLenum pname, GLfloat *data)
{
  ((void(*)(GLenum,GLfloat *))lookup[GLGETFLOATV].functionPtr)(pname,data);
  printf(" gl.getFloatv(%d,0x%p);\n",pname,data);

  }
GL_APICALL void GL_APIENTRY glGetFramebufferAttachmentParameteriv (GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
  ((void(*)(GLenum,GLenum,GLenum,GLint *))lookup[GLGETFRAMEBUFFERATTACHMENTPARAMETERIV].functionPtr)(target,attachment,pname,params);
  printf(" gl.getFramebufferAttachmentParameteriv(%d,%d,%d,0x%p);\n",target,attachment,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetIntegerv (GLenum pname, GLint *data)
{
  ((void(*)(GLenum,GLint *))lookup[GLGETINTEGERV].functionPtr)(pname,data);
  printf(" gl.getIntegerv(%d,0x%p);\n",pname,data);

  }
GL_APICALL void GL_APIENTRY glGetProgramiv (GLuint program, GLenum pname, GLint *params)
{
  ((void(*)(GLuint,GLenum,GLint *))lookup[GLGETPROGRAMIV].functionPtr)(program,pname,params);
  printf(" gl.getProgramiv(programs[%u],%d,0x%p);\n",program,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetProgramInfoLog (GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
  ((void(*)(GLuint,GLsizei,GLsizei *,GLchar *))lookup[GLGETPROGRAMINFOLOG].functionPtr)(program,bufSize,length,infoLog);
  printf(" gl.getProgramInfoLog(programs[%u],%d,0x%p,0x%p);\n",program,bufSize,length,infoLog);

  }
GL_APICALL void GL_APIENTRY glGetRenderbufferParameteriv (GLenum target, GLenum pname, GLint *params)
{
  ((void(*)(GLenum,GLenum,GLint *))lookup[GLGETRENDERBUFFERPARAMETERIV].functionPtr)(target,pname,params);
  printf(" gl.getRenderbufferParameteriv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetShaderiv (GLuint shader, GLenum pname, GLint *params)
{
  ((void(*)(GLuint,GLenum,GLint *))lookup[GLGETSHADERIV].functionPtr)(shader,pname,params);
  printf(" gl.getShaderiv(shaders[%u],%d,0x%p);\n",shader,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetShaderInfoLog (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)
{
  ((void(*)(GLuint,GLsizei,GLsizei *,GLchar *))lookup[GLGETSHADERINFOLOG].functionPtr)(shader,bufSize,length,infoLog);
  printf(" gl.getShaderInfoLog(shaders[%u],%d,0x%p,0x%p);\n",shader,bufSize,length,infoLog);

  }
GL_APICALL void GL_APIENTRY glGetShaderPrecisionFormat (GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
  ((void(*)(GLenum,GLenum,GLint *,GLint *))lookup[GLGETSHADERPRECISIONFORMAT].functionPtr)(shadertype,precisiontype,range,precision);
  printf(" gl.getShaderPrecisionFormat(%d,%d,0x%p,0x%p);\n",shadertype,precisiontype,range,precision);

  }
GL_APICALL void GL_APIENTRY glGetShaderSource (GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source)
{
  ((void(*)(GLuint,GLsizei,GLsizei *,GLchar *))lookup[GLGETSHADERSOURCE].functionPtr)(shader,bufSize,length,source);
  printf(" gl.getShaderSource(shaders[%u],%d,0x%p,0x%p);\n",shader,bufSize,length,source);

  }
GL_APICALL const GLubyte *GL_APIENTRY glGetString (GLenum name)
{
  const GLubyte * res = ((const GLubyte *(*)(GLenum))lookup[GLGETSTRING].functionPtr)(name);
  printf(" gl.getString(%d);\n",name);

  return res;
}
GL_APICALL void GL_APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params)
{
  ((void(*)(GLenum,GLenum,GLfloat *))lookup[GLGETTEXPARAMETERFV].functionPtr)(target,pname,params);
  printf(" gl.getTexParameterfv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params)
{
  ((void(*)(GLenum,GLenum,GLint *))lookup[GLGETTEXPARAMETERIV].functionPtr)(target,pname,params);
  printf(" gl.getTexParameteriv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetUniformfv (GLuint program, GLint location, GLfloat *params)
{
  ((void(*)(GLuint,GLint,GLfloat *))lookup[GLGETUNIFORMFV].functionPtr)(program,location,params);
  printf(" gl.getUniformfv(programs[%u],uniforms[%d],0x%p);\n",program,location,params);

  }
GL_APICALL void GL_APIENTRY glGetUniformiv (GLuint program, GLint location, GLint *params)
{
  ((void(*)(GLuint,GLint,GLint *))lookup[GLGETUNIFORMIV].functionPtr)(program,location,params);
  printf(" gl.getUniformiv(programs[%u],uniforms[%d],0x%p);\n",program,location,params);

  }
GL_APICALL GLint GL_APIENTRY glGetUniformLocation (GLuint program, const GLchar *name)
{
  GLint res = ((GLint(*)(GLuint,const GLchar *))lookup[GLGETUNIFORMLOCATION].functionPtr)(program,name);
  printf("location =  gl.getUniformLocation(programs[%u],\"%s\");\n",program,name);
printf("uniforms[%d] = location;");

  return res;
}
GL_APICALL void GL_APIENTRY glGetVertexAttribfv (GLuint index, GLenum pname, GLfloat *params)
{
  ((void(*)(GLuint,GLenum,GLfloat *))lookup[GLGETVERTEXATTRIBFV].functionPtr)(index,pname,params);
  printf(" gl.getVertexAttribfv(attribs[%u],%d,0x%p);\n",index,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetVertexAttribiv (GLuint index, GLenum pname, GLint *params)
{
  ((void(*)(GLuint,GLenum,GLint *))lookup[GLGETVERTEXATTRIBIV].functionPtr)(index,pname,params);
  printf(" gl.getVertexAttribiv(attribs[%u],%d,0x%p);\n",index,pname,params);

  }
GL_APICALL void GL_APIENTRY glGetVertexAttribPointerv (GLuint index, GLenum pname, void **pointer)
{
  ((void(*)(GLuint,GLenum,void **))lookup[GLGETVERTEXATTRIBPOINTERV].functionPtr)(index,pname,pointer);
  printf(" gl.getVertexAttribPointerv(attribs[%u],%d,0x%p);\n",index,pname,pointer);

  }
GL_APICALL void GL_APIENTRY glHint (GLenum target, GLenum mode)
{
  ((void(*)(GLenum,GLenum))lookup[GLHINT].functionPtr)(target,mode);
  printf(" gl.hint(%d,%d);\n",target,mode);

  }
GL_APICALL GLboolean GL_APIENTRY glIsBuffer (GLuint buffer)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISBUFFER].functionPtr)(buffer);
  printf(" gl.isBuffer(%u);\n",buffer);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsEnabled (GLenum cap)
{
  GLboolean res = ((GLboolean(*)(GLenum))lookup[GLISENABLED].functionPtr)(cap);
  printf(" gl.isEnabled(%d);\n",cap);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsFramebuffer (GLuint framebuffer)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISFRAMEBUFFER].functionPtr)(framebuffer);
  printf(" gl.isFramebuffer(%u);\n",framebuffer);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsProgram (GLuint program)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISPROGRAM].functionPtr)(program);
  printf(" gl.isProgram(programs[%u]);\n",program);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsRenderbuffer (GLuint renderbuffer)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISRENDERBUFFER].functionPtr)(renderbuffer);
  printf(" gl.isRenderbuffer(%u);\n",renderbuffer);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsShader (GLuint shader)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISSHADER].functionPtr)(shader);
  printf(" gl.isShader(shaders[%u]);\n",shader);

  return res;
}
GL_APICALL GLboolean GL_APIENTRY glIsTexture (GLuint texture)
{
  GLboolean res = ((GLboolean(*)(GLuint))lookup[GLISTEXTURE].functionPtr)(texture);
  printf(" gl.isTexture(%u);\n",texture);

  return res;
}
GL_APICALL void GL_APIENTRY glLineWidth (GLfloat width)
{
  ((void(*)(GLfloat))lookup[GLLINEWIDTH].functionPtr)(width);
  printf(" gl.lineWidth(%f);\n",width);

  }
GL_APICALL void GL_APIENTRY glLinkProgram (GLuint program)
{
  ((void(*)(GLuint))lookup[GLLINKPROGRAM].functionPtr)(program);
  printf(" gl.linkProgram(programs[%u]);\n",program);

  }
GL_APICALL void GL_APIENTRY glPixelStorei (GLenum pname, GLint param)
{
  ((void(*)(GLenum,GLint))lookup[GLPIXELSTOREI].functionPtr)(pname,param);
  printf(" gl.pixelStorei(%d,%d);\n",pname,param);

  }
GL_APICALL void GL_APIENTRY glPolygonOffset (GLfloat factor, GLfloat units)
{
  ((void(*)(GLfloat,GLfloat))lookup[GLPOLYGONOFFSET].functionPtr)(factor,units);
  printf(" gl.polygonOffset(%f,%f);\n",factor,units);

  }
GL_APICALL void GL_APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels)
{
  ((void(*)(GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,void *))lookup[GLREADPIXELS].functionPtr)(x,y,width,height,format,type,pixels);
  printf(" gl.readPixels(%d,%d,%d,%d,%d,%d,0x%p);\n",x,y,width,height,format,type,pixels);

  }
GL_APICALL void GL_APIENTRY glReleaseShaderCompiler (void)
{
  ((void(*)())lookup[GLRELEASESHADERCOMPILER].functionPtr)();
  printf(" gl.releaseShaderCompiler();\n");

  }
GL_APICALL void GL_APIENTRY glRenderbufferStorage (GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
  ((void(*)(GLenum,GLenum,GLsizei,GLsizei))lookup[GLRENDERBUFFERSTORAGE].functionPtr)(target,internalformat,width,height);
  printf(" gl.renderbufferStorage(%d,%d,%d,%d);\n",target,internalformat,width,height);

  }
GL_APICALL void GL_APIENTRY glSampleCoverage (GLfloat value, GLboolean invert)
{
  ((void(*)(GLfloat,GLboolean))lookup[GLSAMPLECOVERAGE].functionPtr)(value,invert);
  printf(" gl.sampleCoverage(%f,%d);\n",value,invert);

  }
GL_APICALL void GL_APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height)
{
  ((void(*)(GLint,GLint,GLsizei,GLsizei))lookup[GLSCISSOR].functionPtr)(x,y,width,height);
  printf(" gl.scissor(%d,%d,%d,%d);\n",x,y,width,height);

  }
GL_APICALL void GL_APIENTRY glShaderBinary (GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length)
{
  ((void(*)(GLsizei,const GLuint *,GLenum,const void *,GLsizei))lookup[GLSHADERBINARY].functionPtr)(count,shaders,binaryformat,binary,length);
  printf(" gl.shaderBinary(%d,0x%p,%d,0x%p,%d);\n",count,shaders,binaryformat,binary,length);

  }
GL_APICALL void GL_APIENTRY glShaderSource (GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length)
{
  ((void(*)(GLuint,GLsizei,const GLchar *const*,const GLint *))lookup[GLSHADERSOURCE].functionPtr)(shader,count,string,length);
  printf("var ss = `%s`;\n", string[0]);
printf("gl.shaderSource(shaders[%u], ss);\n",shader);

  }
GL_APICALL void GL_APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask)
{
  ((void(*)(GLenum,GLint,GLuint))lookup[GLSTENCILFUNC].functionPtr)(func,ref,mask);
  printf(" gl.stencilFunc(%d,%d,%u);\n",func,ref,mask);

  }
GL_APICALL void GL_APIENTRY glStencilFuncSeparate (GLenum face, GLenum func, GLint ref, GLuint mask)
{
  ((void(*)(GLenum,GLenum,GLint,GLuint))lookup[GLSTENCILFUNCSEPARATE].functionPtr)(face,func,ref,mask);
  printf(" gl.stencilFuncSeparate(%d,%d,%d,%u);\n",face,func,ref,mask);

  }
GL_APICALL void GL_APIENTRY glStencilMask (GLuint mask)
{
  ((void(*)(GLuint))lookup[GLSTENCILMASK].functionPtr)(mask);
  printf(" gl.stencilMask(%u);\n",mask);

  }
GL_APICALL void GL_APIENTRY glStencilMaskSeparate (GLenum face, GLuint mask)
{
  ((void(*)(GLenum,GLuint))lookup[GLSTENCILMASKSEPARATE].functionPtr)(face,mask);
  printf(" gl.stencilMaskSeparate(%d,%u);\n",face,mask);

  }
GL_APICALL void GL_APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass)
{
  ((void(*)(GLenum,GLenum,GLenum))lookup[GLSTENCILOP].functionPtr)(fail,zfail,zpass);
  printf(" gl.stencilOp(%d,%d,%d);\n",fail,zfail,zpass);

  }
GL_APICALL void GL_APIENTRY glStencilOpSeparate (GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass)
{
  ((void(*)(GLenum,GLenum,GLenum,GLenum))lookup[GLSTENCILOPSEPARATE].functionPtr)(face,sfail,dpfail,dppass);
  printf(" gl.stencilOpSeparate(%d,%d,%d,%d);\n",face,sfail,dpfail,dppass);

  }
GL_APICALL void GL_APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels)
{
  ((void(*)(GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const void *))lookup[GLTEXIMAGE2D].functionPtr)(target,level,internalformat,width,height,border,format,type,pixels);
  printf(" gl.texImage2D(%d,%d,%d,%d,%d,%d,%d,%d,0x%p);\n",target,level,internalformat,width,height,border,format,type,pixels);

  }
GL_APICALL void GL_APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param)
{
  ((void(*)(GLenum,GLenum,GLfloat))lookup[GLTEXPARAMETERF].functionPtr)(target,pname,param);
  printf(" gl.texParameterf(%d,%d,%f);\n",target,pname,param);

  }
GL_APICALL void GL_APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params)
{
  ((void(*)(GLenum,GLenum,const GLfloat *))lookup[GLTEXPARAMETERFV].functionPtr)(target,pname,params);
  printf(" gl.texParameterfv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL void GL_APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param)
{
  ((void(*)(GLenum,GLenum,GLint))lookup[GLTEXPARAMETERI].functionPtr)(target,pname,param);
  printf(" gl.texParameteri(%d,%d,%d);\n",target,pname,param);

  }
GL_APICALL void GL_APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params)
{
  ((void(*)(GLenum,GLenum,const GLint *))lookup[GLTEXPARAMETERIV].functionPtr)(target,pname,params);
  printf(" gl.texParameteriv(%d,%d,0x%p);\n",target,pname,params);

  }
GL_APICALL void GL_APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels)
{
  ((void(*)(GLenum,GLint,GLint,GLint,GLsizei,GLsizei,GLenum,GLenum,const void *))lookup[GLTEXSUBIMAGE2D].functionPtr)(target,level,xoffset,yoffset,width,height,format,type,pixels);
  printf(" gl.texSubImage2D(%d,%d,%d,%d,%d,%d,%d,%d,0x%p);\n",target,level,xoffset,yoffset,width,height,format,type,pixels);

  }
GL_APICALL void GL_APIENTRY glUniform1f (GLint location, GLfloat v0)
{
  ((void(*)(GLint,GLfloat))lookup[GLUNIFORM1F].functionPtr)(location,v0);
  printf(" gl.uniform1f(uniforms[%d],%f);\n",location,v0);

  }
GL_APICALL void GL_APIENTRY glUniform1fv (GLint location, GLsizei count, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,const GLfloat *))lookup[GLUNIFORM1FV].functionPtr)(location,count,value);
  printf(" gl.uniform1fv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform1i (GLint location, GLint v0)
{
  ((void(*)(GLint,GLint))lookup[GLUNIFORM1I].functionPtr)(location,v0);
  printf(" gl.uniform1i(uniforms[%d],%d);\n",location,v0);

  }
GL_APICALL void GL_APIENTRY glUniform1iv (GLint location, GLsizei count, const GLint *value)
{
  ((void(*)(GLint,GLsizei,const GLint *))lookup[GLUNIFORM1IV].functionPtr)(location,count,value);
  printf(" gl.uniform1iv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform2f (GLint location, GLfloat v0, GLfloat v1)
{
  ((void(*)(GLint,GLfloat,GLfloat))lookup[GLUNIFORM2F].functionPtr)(location,v0,v1);
  printf(" gl.uniform2f(uniforms[%d],%f,%f);\n",location,v0,v1);

  }
GL_APICALL void GL_APIENTRY glUniform2fv (GLint location, GLsizei count, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,const GLfloat *))lookup[GLUNIFORM2FV].functionPtr)(location,count,value);
  printf(" gl.uniform2fv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform2i (GLint location, GLint v0, GLint v1)
{
  ((void(*)(GLint,GLint,GLint))lookup[GLUNIFORM2I].functionPtr)(location,v0,v1);
  printf(" gl.uniform2i(uniforms[%d],%d,%d);\n",location,v0,v1);

  }
GL_APICALL void GL_APIENTRY glUniform2iv (GLint location, GLsizei count, const GLint *value)
{
  ((void(*)(GLint,GLsizei,const GLint *))lookup[GLUNIFORM2IV].functionPtr)(location,count,value);
  printf(" gl.uniform2iv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform3f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2)
{
  ((void(*)(GLint,GLfloat,GLfloat,GLfloat))lookup[GLUNIFORM3F].functionPtr)(location,v0,v1,v2);
  printf(" gl.uniform3f(uniforms[%d],%f,%f,%f);\n",location,v0,v1,v2);

  }
GL_APICALL void GL_APIENTRY glUniform3fv (GLint location, GLsizei count, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,const GLfloat *))lookup[GLUNIFORM3FV].functionPtr)(location,count,value);
  printf(" gl.uniform3fv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform3i (GLint location, GLint v0, GLint v1, GLint v2)
{
  ((void(*)(GLint,GLint,GLint,GLint))lookup[GLUNIFORM3I].functionPtr)(location,v0,v1,v2);
  printf(" gl.uniform3i(uniforms[%d],%d,%d,%d);\n",location,v0,v1,v2);

  }
GL_APICALL void GL_APIENTRY glUniform3iv (GLint location, GLsizei count, const GLint *value)
{
  ((void(*)(GLint,GLsizei,const GLint *))lookup[GLUNIFORM3IV].functionPtr)(location,count,value);
  printf(" gl.uniform3iv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform4f (GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3)
{
  ((void(*)(GLint,GLfloat,GLfloat,GLfloat,GLfloat))lookup[GLUNIFORM4F].functionPtr)(location,v0,v1,v2,v3);
  printf(" gl.uniform4f(uniforms[%d],%f,%f,%f,%f);\n",location,v0,v1,v2,v3);

  }
GL_APICALL void GL_APIENTRY glUniform4fv (GLint location, GLsizei count, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,const GLfloat *))lookup[GLUNIFORM4FV].functionPtr)(location,count,value);
  printf(" gl.uniform4fv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniform4i (GLint location, GLint v0, GLint v1, GLint v2, GLint v3)
{
  ((void(*)(GLint,GLint,GLint,GLint,GLint))lookup[GLUNIFORM4I].functionPtr)(location,v0,v1,v2,v3);
  printf(" gl.uniform4i(uniforms[%d],%d,%d,%d,%d);\n",location,v0,v1,v2,v3);

  }
GL_APICALL void GL_APIENTRY glUniform4iv (GLint location, GLsizei count, const GLint *value)
{
  ((void(*)(GLint,GLsizei,const GLint *))lookup[GLUNIFORM4IV].functionPtr)(location,count,value);
  printf(" gl.uniform4iv(uniforms[%d],%d,0x%p);\n",location,count,value);

  }
GL_APICALL void GL_APIENTRY glUniformMatrix2fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,GLboolean,const GLfloat *))lookup[GLUNIFORMMATRIX2FV].functionPtr)(location,count,transpose,value);
  printf("val values = {");
int i;
for (i = 0; i< 4; ++i) { if (i!=0) {printf(",");};printf("%f",value[i]); }
printf("};");printf("gl.uniformMatrix2fv(uniforms[%d], transpose, new Float32Array(values) );", location);

  }
GL_APICALL void GL_APIENTRY glUniformMatrix3fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,GLboolean,const GLfloat *))lookup[GLUNIFORMMATRIX3FV].functionPtr)(location,count,transpose,value);
  printf("val values = {");
int i;
for (i = 0; i< 9; ++i) { if (i!=0) {printf(",");};printf("%f",value[i]); }
printf("};");printf("gl.uniformMatrix3fv(uniforms[%d], transpose, new Float32Array(values) );", location);

  }
GL_APICALL void GL_APIENTRY glUniformMatrix4fv (GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
  ((void(*)(GLint,GLsizei,GLboolean,const GLfloat *))lookup[GLUNIFORMMATRIX4FV].functionPtr)(location,count,transpose,value);
  printf("val values = {");
int i;
for (i = 0; i< 16; ++i) { if (i!=0) {printf(",");};printf("%f",value[i]); }
printf("};");printf("gl.uniformMatrix4fv(uniforms[%d], transpose, new Float32Array(values) );", location);

  }
GL_APICALL void GL_APIENTRY glUseProgram (GLuint program)
{
  ((void(*)(GLuint))lookup[GLUSEPROGRAM].functionPtr)(program);
  printf(" gl.useProgram(programs[%u]);\n",program);

  }
GL_APICALL void GL_APIENTRY glValidateProgram (GLuint program)
{
  ((void(*)(GLuint))lookup[GLVALIDATEPROGRAM].functionPtr)(program);
  printf(" gl.validateProgram(programs[%u]);\n",program);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib1f (GLuint index, GLfloat x)
{
  ((void(*)(GLuint,GLfloat))lookup[GLVERTEXATTRIB1F].functionPtr)(index,x);
  printf(" gl.vertexAttrib1f(attribs[%u],%f);\n",index,x);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib1fv (GLuint index, const GLfloat *v)
{
  ((void(*)(GLuint,const GLfloat *))lookup[GLVERTEXATTRIB1FV].functionPtr)(index,v);
  printf(" gl.vertexAttrib1fv(attribs[%u],0x%p);\n",index,v);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib2f (GLuint index, GLfloat x, GLfloat y)
{
  ((void(*)(GLuint,GLfloat,GLfloat))lookup[GLVERTEXATTRIB2F].functionPtr)(index,x,y);
  printf(" gl.vertexAttrib2f(attribs[%u],%f,%f);\n",index,x,y);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib2fv (GLuint index, const GLfloat *v)
{
  ((void(*)(GLuint,const GLfloat *))lookup[GLVERTEXATTRIB2FV].functionPtr)(index,v);
  printf(" gl.vertexAttrib2fv(attribs[%u],0x%p);\n",index,v);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib3f (GLuint index, GLfloat x, GLfloat y, GLfloat z)
{
  ((void(*)(GLuint,GLfloat,GLfloat,GLfloat))lookup[GLVERTEXATTRIB3F].functionPtr)(index,x,y,z);
  printf(" gl.vertexAttrib3f(attribs[%u],%f,%f,%f);\n",index,x,y,z);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib3fv (GLuint index, const GLfloat *v)
{
  ((void(*)(GLuint,const GLfloat *))lookup[GLVERTEXATTRIB3FV].functionPtr)(index,v);
  printf(" gl.vertexAttrib3fv(attribs[%u],0x%p);\n",index,v);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib4f (GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
  ((void(*)(GLuint,GLfloat,GLfloat,GLfloat,GLfloat))lookup[GLVERTEXATTRIB4F].functionPtr)(index,x,y,z,w);
  printf(" gl.vertexAttrib4f(attribs[%u],%f,%f,%f,%f);\n",index,x,y,z,w);

  }
GL_APICALL void GL_APIENTRY glVertexAttrib4fv (GLuint index, const GLfloat *v)
{
  ((void(*)(GLuint,const GLfloat *))lookup[GLVERTEXATTRIB4FV].functionPtr)(index,v);
  printf(" gl.vertexAttrib4fv(attribs[%u],0x%p);\n",index,v);

  }
GL_APICALL void GL_APIENTRY glVertexAttribPointer (GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
{
  ((void(*)(GLuint,GLint,GLenum,GLboolean,GLsizei,const void *))lookup[GLVERTEXATTRIBPOINTER].functionPtr)(index,size,type,normalized,stride,pointer);
  printf(" gl.vertexAttribPointer(attribs[%u],%d,%d,%d,%d,0x%p);\n",index,size,type,normalized,stride,pointer);

  }
GL_APICALL void GL_APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height)
{
  ((void(*)(GLint,GLint,GLsizei,GLsizei))lookup[GLVIEWPORT].functionPtr)(x,y,width,height);
  printf(" gl.viewport(%d,%d,%d,%d);\n",x,y,width,height);

  }

__attribute__((constructor)) void init(void) { createmap(); }

$NetBSD$

--- app/gfx/gl/gl_bindings.h.orig	2011-04-13 08:01:07.000000000 +0000
+++ app/gfx/gl/gl_bindings.h
@@ -22,7 +22,7 @@
 // The standard OpenGL native extension headers are also included.
 #if defined(OS_WIN)
 #include <GL/wglext.h>
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include <GL/glx.h>
 #include <GL/glxext.h>
 
@@ -52,7 +52,7 @@
 typedef struct osmesa_context *OSMesaContext;
 typedef void (*OSMESAproc)();
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
 // Forward declare EGL types.
 typedef unsigned int EGLBoolean;
@@ -75,7 +75,7 @@ typedef Pixmap   EGLNativePixmapType;
 typedef Window   EGLNativeWindowType;
 #endif
 
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_BSD 
 
 #include "gl_bindings_autogen_gl.h"
 #include "gl_bindings_autogen_osmesa.h"
@@ -83,7 +83,7 @@ typedef Window   EGLNativeWindowType;
 #if defined(OS_WIN)
 #include "gl_bindings_autogen_egl.h"
 #include "gl_bindings_autogen_wgl.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #include "gl_bindings_autogen_egl.h"
 #include "gl_bindings_autogen_glx.h"
 #endif

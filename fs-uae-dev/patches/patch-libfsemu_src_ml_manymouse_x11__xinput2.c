$NetBSD$

Include proper header file.

--- libfsemu/src/ml/manymouse/x11_xinput2.c.orig	2014-03-25 19:40:58.000000000 +0000
+++ libfsemu/src/ml/manymouse/x11_xinput2.c
@@ -25,6 +25,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <dlfcn.h>
+#include <sys/select.h>
 #include <X11/extensions/XInput2.h>
 
 /* 32 is good enough for now. */

$NetBSD: patch-Source_JavaScriptCore_heap_MachineStackMarker.cpp,v 1.2 2012/10/30 12:46:30 drochner Exp $

--- Source/JavaScriptCore/heap/MachineStackMarker.cpp.orig	2014-04-14 06:40:44.000000000 +0000
+++ Source/JavaScriptCore/heap/MachineStackMarker.cpp
@@ -20,6 +20,9 @@
  */
 
 #include "config.h"
+#if OS(SOLARIS)
+#undef _FILE_OFFSET_BITS
+#endif
 #include "MachineStackMarker.h"
 
 #include "ConservativeRoots.h"
@@ -49,6 +52,10 @@
 #include <unistd.h>
 
 #if OS(SOLARIS)
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <procfs.h>
 #include <thread.h>
 #else
 #include <pthread.h>
@@ -310,6 +317,7 @@ typedef pthread_attr_t PlatformThreadReg
 #error Need a thread register struct for this platform
 #endif
 
+#if !OS(SOLARIS)
 static size_t getPlatformThreadRegisters(const PlatformThread& platformThread, PlatformThreadRegisters& regs)
 {
 #if OS(DARWIN)
@@ -363,6 +371,7 @@ static size_t getPlatformThreadRegisters
 #error Need a way to get thread registers on this platform
 #endif
 }
+#endif
 
 static inline void* otherThreadStackPointer(const PlatformThreadRegisters& regs)
 {
@@ -425,6 +434,7 @@ static inline void* otherThreadStackPoin
 #endif
 }
 
+#if !OS(SOLARIS)
 static void freePlatformThreadRegisters(PlatformThreadRegisters& regs)
 {
 #if USE(PTHREADS) && !OS(WINDOWS) && !OS(DARWIN)
@@ -433,20 +443,36 @@ static void freePlatformThreadRegisters(
     UNUSED_PARAM(regs);
 #endif
 }
+#endif
 
 void MachineThreads::gatherFromOtherThread(ConservativeRoots& conservativeRoots, Thread* thread)
 {
+#if OS(SOLARIS)
+    struct lwpstatus lwp;
+    char procfile[64];
+    int fd;
+    snprintf(procfile, 64, "/proc/self/lwp/%u/lwpstatus", thread->platformThread);
+    fd = open(procfile, O_RDONLY, 0);
+    if (fd == -1) {
+        fprintf(stderr, "%s: %s\n", procfile, strerror(errno));
+        abort();
+    }
+    pread(fd, &lwp, sizeof(lwp), 0);
+    close(fd);
+    void* stackPointer = (void*)lwp.pr_reg[REG_SP];
+#else
     PlatformThreadRegisters regs;
     size_t regSize = getPlatformThreadRegisters(thread->platformThread, regs);
 
     conservativeRoots.add(static_cast<void*>(&regs), static_cast<void*>(reinterpret_cast<char*>(&regs) + regSize));
 
     void* stackPointer = otherThreadStackPointer(regs);
+
+    freePlatformThreadRegisters(regs);
+#endif
     void* stackBase = thread->stackBase;
     swapIfBackwards(stackPointer, stackBase);
     conservativeRoots.add(stackPointer, stackBase);
-
-    freePlatformThreadRegisters(regs);
 }
 
 void MachineThreads::gatherConservativeRoots(ConservativeRoots& conservativeRoots, void* stackCurrent)

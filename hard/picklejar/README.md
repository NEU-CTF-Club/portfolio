## pickle.jar
### Difficulty
HARD
### Description
NEU CTF Club tightened the lid on this pickle jar and now we can't get it open! Can you help us out?
### Solution
1. This challenge consists primarily of Java source code, but there’s a hidden twist. A user may start by running the 
   .jar and seeing that the application is a “flag checker” (creative ik)
1. A logical next step is to check the Java source using JADX-GUI or other Java decompilers. Looking at the source code, 
   everything is pretty standard besides the fact that there is a library loaded from resources, and the checkFlag() 
   function has the keyword “native” with no code.
1. A native function in Java is a function that typically calls code from a C/C++ native library, hence having no 
   function body. From here a user is expected to extract the .jar file and obtain the file “libpickles.so”.
1. This is compiled C code, so Ghidra/IDA Pro/Binary Ninja is probably the best way to attack this. Looking at the 
   decompiled function “consideration(char *param_1)”, it’s trivial to reverse, albeit a little painstaking. A user must 
   look at the array indices in the “if” statement one-by-one and reconstruct the flag.
### Flag
CTF{p1ckl3s_th3_c4t}

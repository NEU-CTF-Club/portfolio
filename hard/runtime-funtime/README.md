### (RE) Tempyral
I didn't have time to finish making this challenge :( Last I remember, I had a debug variable set in one of my functions 
to make sure the flag would print alright, but in this build the code is unreachable. Maybe you can reverse the binary 
to get the flag or get it somehow else?

### Solution
1. Looking at the binary in Ghidra will provide little to no help, the unreachable code will not show in the decompiler, 
if isolating the “buildFlag()” function there are 512 different function calls.
1. Open the executable in GDB. Set a breakpoint on main, run, and disassemble.
1. Notice the “jne” instruction. This is the check that we need to jump past. Set a breakpoint on that address. 
Continue.
1. Copy the address of the instruction right after that and jump to it.
1. The flag will appear in the printed text.

### Flag
CTF{sw1mm1ng_w1th_th3_f15h35}


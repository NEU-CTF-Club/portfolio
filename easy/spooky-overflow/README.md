### (PWN) Spooky Overflow
Enter a spooky input, get a spooky output. Overflow the buffer with deadbeef to get the flag.

### Solution
Simple buffer overflow. Overflow the 40-character buffer and slot in 0xDEADBEEF (don't forget about little vs. big endian!)
and you will get the flag.

### Flag
CTF{buff3r_b33f_pwn}

### Building
```bash
make build
```

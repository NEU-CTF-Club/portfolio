### (RE) Lonely Secure
I took the code from the challenge "Lonely" and added some extra checks to it for security! Unfortunately, this did 
nothing to help with the connection issues, so you'll still need to try and talk to that server :/

### Solution
1. Open the jarfile in JADX and look at the decompiled code, write python/script to replicate the request.
1. Implement the "X-Autograph" signature header in your request to pass the server's integrity check.

### Flag
CTF{und3r_the_se4_d00_d00_d00}

### Building
```bash
make build
```

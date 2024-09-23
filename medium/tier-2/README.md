### (WEB) Tier-2
Just made a sweet webpage! It basically echoes whatever you input. Super cool, and 100% secure; some pesky attackers can't get past my defenses now.

### Solution
Simple command injection... or is it?
This time, the flag.txt is not readable! However, a sneaky attacker can run `sudo -l` and see that they have root grep permissions ;)

Use grep to get the flag! For example. `grep -ir ctf`

### Flag
CTF{pr1v3sc-inj3ct10n}

### Deployment
```bash
# Substitute podman if desired
docker compose up -d
```

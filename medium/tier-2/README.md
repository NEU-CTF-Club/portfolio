### Description
Just made a sweet webpage! It basically echoes whatever you input. Super cool, and 100% secure
now that I fixed a small bug in my application!

### Build instructions
use docker compose to build :)

### Flag
CTF{j4v4scr1pt-byp4ss3r-1nj3ct10n}

### Answer
Simple command injection :) --> "x && cat flag.txt"

However, this time, there is client-side protection with JavaScript! But we know that we can't trust execution on client side code ..!
So, the attacker can just either remove the javascript or make a manual web request with something like BurpSuite or DevTools :)

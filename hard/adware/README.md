## adware
### Difficulty
HARD
### Description
Our "friends" over at RPISEC have been up to no good again. They've been distributing this adware to unsuspecting 
students! Can you help us get to the bottom of this?
### Solution
1. Open binary in Ghidra
1. Get dropped in at runtime.main(), follow the decompiled code output to main.main()
1. main.main() calls main.openWindow(), main.openWindow() calls main.randomImageButton(), and main.randomImageButton() 
   calls main.generateImage().
1. This function contains references to main.images, a global var containing b64 image data.
1. These images can be decoded using the base64 command amongst other tools. The middle one will contain the flag
   appended to the end of the image data. Calling strings or cat on the image will reveal the flag.

### Flag
CTF{b3w4r3_th3_4dw4r3}

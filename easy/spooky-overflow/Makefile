.PHONY: build
build:
	gcc -m32 -o exploit ./exploit.c -fno-stack-protector

.PHONY: clean
clean:
	[ -f "./exploit" ] && rm ./exploit

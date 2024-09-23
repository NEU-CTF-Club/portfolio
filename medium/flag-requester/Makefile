.PHONY: build
build:
	gcc -Wno-deprecated-declarations ./flag_requester.c -o ./flag_requester `pkg-config --libs libcurl openssl`

.PHONY: clean
clean:
	[ -f "./flag_requester" ] && rm ./flag_requester

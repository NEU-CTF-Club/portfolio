.PHONY: build
build:
	mkdir -p ./build
	javac -d ./build/ ./src/Main.java
	jar cfe ./lonelysecure.jar Main -C ./build/ ./Main.class

.PHONY: clean
clean:
	rm -rf ./build/

.PHONY: cleanall
cleanall: clean
	[ -f "./lonelysecure.jar" ] && rm ./lonelysecure.jar

GCC = gcc

out/test: $(wildcard c-src/*.c c-src/*h)
	mkdir -p $(dir $@)
	${GCC} -o $@ $(wildcard c-src/*.c)

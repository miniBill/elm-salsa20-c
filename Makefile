GCC = gcc

out/test: $(wildcard src/*.c src/*h)
	mkdir -p $(dir $@)
	${GCC} -o $@ $(wildcard src/*.c)

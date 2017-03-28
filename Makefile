CFLAGS=gcc -m32 -g0  -Wall

make copy:
	$(CFLAGS) src/janky_copy.c -o jcp

clean:
	rm jcp


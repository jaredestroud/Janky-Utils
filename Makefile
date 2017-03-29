CFLAGS=gcc -m32 -g0  -Wall

make:
	$(CFLAGS) src/janky_copy.c -o jcp
	$(CFLAGS) src/janky_copy++.c -o jcpp

make copy:
	$(CFLAGS) src/janky_copy.c -o jcp

make copypp:
	$(CFLAGS) src/janky_copy++.c -o jcpp

clean:
	rm jcp*


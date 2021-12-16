make:
	rm -f ./demo
	gcc demo.c demoASM.s -o demo
clean:
	rm ./demo
run:
	gcc demo.c demoASM.s -o demo
	./demo
asm:
	gcc -S demo.c demoASM.s

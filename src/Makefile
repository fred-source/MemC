CFLAGS=-Wall -DDEBUG -Wuninitialized -std=c11
build: *.c 
	clear
	gcc -o build *.c ${CFLAGS} ${CPPFLAGS}
	make run_other
	
run_win:
	build.exe

run_other:
	./build.exe
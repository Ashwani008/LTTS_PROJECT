SRC = timer_demo.c

all : 
	gcc -c $(SRC) -o timer_demo.o
	gcc timer_demo.o -o timer_demo.exe -lrt

run : all
	./timer_demo.exe

clean : 
	rm timer_demo.o
	rm timer_demo.exe


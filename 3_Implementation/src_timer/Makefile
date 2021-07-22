SRC = timerlib.c timerlib_main.c

target: $(SRC)
	gcc -g $(SRC) -o timerlib_main.out -lrt

run: target
	./timerlib_main.out

memory_leakage:
	valgrind ./timerlib_main.out

clean:
	rm timerlib_main.out
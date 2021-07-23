SRC = timerlib.c timerlib_main.c

target: $(SRC)
gcc test_timerlib.c test_timerlib_main.c unity/unity.c -o a.out -I unity -lrt
	gcc -g $(SRC) -o timerlib_main.out -lrt

run: target
	./timerlib_main.out

memory_leakage:
	valgrind ./timerlib_main.out

clean:
	rm timerlib_main.out
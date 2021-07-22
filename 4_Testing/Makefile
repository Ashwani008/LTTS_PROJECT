SRC = test_timerlib.c test_timerlib_main.c unity/unity.c
DIR = unity

target: $(SRC)
	gcc -g $(SRC) -o timerlib_main.out -I $(DIR) -lrt

run: target
	./timerlib_main.out

memory_leakage:
	valgrind ./timerlib_main.out

clean:
	rm timerlib_main.out
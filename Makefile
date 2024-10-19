CC=gcc -Wall -Werror -Wextra
BUILD=build/

all : build

build: rogalic

rogalic: 
	$(CC) src/*.c -o $(BUILD)rogalic -lncurses


clean:
	rm $(BUILD)* src/*.o

rebuild:
	clean build
CC=gcc -Wall -Werror -Wextra
BUILD=build/

all : build

build: rogalic.c

rogalic.c:
	$(CC) src/*.c -o $(BUILD)rogalic -lncurses
CFLAGS = -Wall -g -D _POSIX_C_SOURCE=200809L -Werror

all: build

build:
	g++ $(CFLAGS) main.cpp database.cpp -o database

run: build
	./database

valgrind: build
	valgrind --leak-check=full ./database

clean:
	rm -f database
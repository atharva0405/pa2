all: count

count: second.c
	gcc -Wall -Werror -fsanitize=address second.c -o second

clean:
	rm -rf second

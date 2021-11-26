CFLAGS := -g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak
LDFLAGS := -fsanitize=address -fsanitize=leak

all : main

print_num.o : print_num.cpp print_num.h
	g++ $(CFLAGS) -c print_num.cpp -o print_num.o

list.o : list.cpp list.h
	g++ $(CFLAGS) -c list.cpp -o list.o

array.o : array.cpp array.h
	g++ $(CFLAGS) -c array.cpp -o array.o

main.o : main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

main : main.o list.o array.o print_num.o
	g++ $(LDFLAGS) main.o array.o list.o print_num.o -o main

clean :
	rm *.o main


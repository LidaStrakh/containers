CFLAGS := -g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak
LDFLAGS := -fsanitize=address -fsanitize=leak

SRCS := print_num.cpp list.cpp array.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all : main

$(OBJS) : %.o : %.cpp %.h
	g++ $(CFLAGS) -c $< -o $@

main.o : main.cpp
	g++ $(CFLAGS) -c main.cpp -o main.o

main : main.o $(OBJS)
	g++ $(LDFLAGS) main.o $(OBJS) -o main

clean :
	rm *.o main


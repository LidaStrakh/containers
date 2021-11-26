CFLAGS := -g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak
LDFLAGS := -fsanitize=address -fsanitize=leak

SRCS := print_num.cpp list.cpp array.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all : main

$(OBJS) : %.o : %.cpp %.h
	g++ $(CFLAGS) -c $< -o $@

main : main.cpp $(OBJS)
	g++ $(CFLAGS) main.cpp $(OBJS) -o main

clean :
	rm $(OBJS) main


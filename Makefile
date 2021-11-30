CFLAGS := -g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak
LDFLAGS := -fsanitize=address -fsanitize=leak

SRCS := print_num.cpp list.cpp array.cpp variant.cpp main.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))
DEPS := $(patsubst %.cpp,%.d,$(SRCS))

all : main

-include $(DEPS)

$(OBJS) : %.o : %.cpp 
	g++ $(CFLAGS) -c -MMD $< -o $@

main : $(OBJS)
	g++ $(LDFLAGS) $(OBJS) -o main

clean :
	rm $(OBJS) main $(DEPS)


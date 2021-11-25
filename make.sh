set -x
set -e

cflags="-g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak"
ldflags="-fsanitize=address -fsanitize=leak"

g++ $cflags -c list.cpp -o list.o
g++ $cflags -c print_num.cpp -o print_num.o
g++ $cflags -c array.cpp -o array.o
g++ $cflags -c main.cpp -o main.o 

g++ $ldflags main.o array.o list.o print_num.o -o main

set -x

g++ -g -Wall -Wextra -fsanitize=address -fsanitize=leak -O2 -c list.cpp -o list.o
g++ -g -Wall -Wextra -fsanitize=address -fsanitize=leak -O2 -c print_num.cpp -o print_num.o
g++ -g -Wall -Wextra -fsanitize=address -fsanitize=leak -O2 -c array.cpp -o array.o
g++ -g -Wall -Wextra -fsanitize=address -fsanitize=leak -O2 -c main.cpp -o main.o && g++ -fsanitize=address -fsanitize=leak main.o array.o list.o print_num.o -o main

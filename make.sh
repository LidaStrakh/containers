set -x
set -e

cflags="-g -O2 -Wall -Wextra -fsanitize=address -fsanitize=leak"
ldflags="-fsanitize=address -fsanitize=leak"

for f in list print_num array main ; do
  g++ $cflags -c $f.cpp -o $f.o
done 

g++ $ldflags main.o array.o list.o print_num.o -o main

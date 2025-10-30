# Инструкция по сборке
для сборки необходимо слинковать файл на языке ассемблера с файлом на языке Си:
```bash
gcc -Wall -Wextra -pedantic -O2 -S sort.c -o sort.s
gcc -c sort.s -o sort.o
gcc -Wall -Wextra -pedantic main.c sort.o -o main
```
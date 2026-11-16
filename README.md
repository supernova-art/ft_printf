*This project has been created as part of the 42 curriculum by yait-elm.*

# ft_printf

Because **ft_putnbr()** and **ft_putstr()** aren't enough.

## Description

ft_printf is a 42 School project that consists of recreating partially the standard C library function printf().

The objective is to implement a simplified version of printf() capable of handling a variable number of arguments and formatting different data types according to conversion specifiers.

The project focuses on variadic functions in C and low-level output using the write() system call.

The implementation produces a static library named libftprintf.a, which can be reused in other C projects.

### Suported conversions :

- `%c` : To print one single `character`.
- `%s` : To print a `string`.
- `%p` : To print a pointer's address in hexadecimal.
- `%i` and `%d` : To print a signed decimal integer in base 10.
- `%u` : To print an unsigned decimal integer.
- `%x` : To print a hexadecimal number with lowercase letters.
- `%X` : To print a hexadecimal number with uppercase letters.
- `%%` : To print a literal percent sign.


## Instructions

### Makefile Commands

- `make` : Compiles the project and creates the library.

- `make all` : Builds the library.

- `make clean` : Removes object files.

- `make fclean` : Removes object files and the library.

- `make re` : Rebuilds the library from scratch.

### Compilation 

Clone the repository and navigate to its directory.

```
git clone <repository's URL>
```
Compile the library.

```
make
```
This generates libftprintf.a at the root of the repository.
Then use the library to compile it with your own source file .

```
cc -Wall -Werror -Wextra main.c libftprintf.a -o porgram
```

## Ressources

The following ressources are useful for understanding the concepts involved in this project.

- [Linux man Page of `stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Linux man page of `printf`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux man page of `write`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [Architecture and Registers (chapter 2.0)](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [Stack Frame layout on x86-64](https://accu.org/journals/overload/31/173/bendersky/)
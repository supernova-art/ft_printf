*This project has been created as part of the 42 curriculum by yait-elm.*

# ft_printf

Because **ft_putnbr()** and **ft_putstr()** aren't enough.

## Description

ft_printf is a 42 School project that consists of recreating partially the standard C library function printf().

The objective is to implement a simplified version of printf() capable of handling a variable number of arguments and formatting different data types according to conversion specifiers.

The project focuses on variadic functions in C and low-level output using the write() system call.

The implementation produces a static library named libftprintf.a, which can be reused in other C projects.

### Supported conversions :

- `%c` : To print one single character.
- `%s` : To print a string.
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
Then compile your own source file with the library:

```
cc -Wall -Werror -Wextra main.c libftprintf.a -o program
```

## Resources

The following resources are useful for understanding the concepts involved in this project.

- [Linux man Page of `stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html)
- [Linux man page of `printf`](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Linux man page of `write`](https://man7.org/linux/man-pages/man3/write.2.html)
- [Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)
- [Architecture and Registers (chapter 2)](https://www.cl72.org/120introAssem/assembly-language64-ubuntu.pdf)
- [Stack Frame layout on x86-64](https://accu.org/journals/overload/31/173/bendersky/)

### Use of AI : 
**AI was used in this project as a learning tool, not as a code generator.** 
- And it helped me to understand :
**Concepts:** explanations of variadic functions (`va_list`, `va_start`,
`va_arg`, `va_end`), how arguments are passed in registers and on the stack
on x86-64 (System V ABI), the memory hierarchy, `write` and file descriptors,
the buffering of the real `printf`, base conversion, and how Makefile
work. It also suggested resources for these topics.

## Algorithm and data structure

`ft_printf` reads the format string once, from left to right, and writes
everything straight to `write(1, ...)`. There is no buffer and no custom data
structure: only the format string, a `va_list` that walks the arguments, and
constant base strings (`"0123456789abcdef"`, `"0123456789ABCDEF"`).

### Algorithm

1. `va_start`, then loop over the format string.
2. A normal character is written immediately.
3. After `%`, `format_handler` reads the argument with the right `va_arg` type
   and calls the matching print function.
4. Every function returns the number of characters written, or -1 if `write`
   fails. `ft_printf` adds them up, and on the first -1 it stops, calls
   `va_end` once, and returns -1.

Numbers are printed by recursion: the last digit is computed first
(`n % base`), but the digits must appear first-to-last, so the function prints
`n / base` before the last digit. For `255` in hex it prints `f`, then `f`.
Complexity is linear in the number of digits.

### Why these choices

- **No buffer:** the subject forbids the original buffer management. Direct
  `write` also reports a failure on the same call (cost: one system call per
  character).
- **Recursion, no `malloc`:** nothing to free, no allocation failure, no leaks.
- **`long long` for `%d`, `%i`, `%u`:** negating `INT_MIN` in an `int`
  overflows; widening avoids a special case, and every `unsigned int` fits.
- **`unsigned long` for hex and `%p`:** wide enough for a 64-bit pointer. `%x`
  reads `unsigned int` first, so `-1` prints `ffffffff`.
- **Base string as lookup table:** `base[n % 16]`; uppercase only changes the
  string.
- **Parser and dispatcher separated:** `ft_printf` handles the loop,
  `format_handler` maps a specifier to a function, so adding a conversion
  changes one place.
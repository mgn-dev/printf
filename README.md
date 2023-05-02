# Printf

A custom implementation of formatted output in C, replicating core `printf` behavior with variadic arguments and modular format handlers.

## Overview

This project implements `_printf`, a subset of the standard C `printf` function that processes format strings character by character. When a `%` specifier is encountered, a dispatch table routes to the appropriate handler function. Each handler extracts its argument from a `va_list`, converts the value to output, and returns the number of characters printed.

The architecture separates concerns across a central formatter (`_printf.c`), a specifier resolver (`get_fmt_fn`), and individual print modules for each conversion type. The project builds directly on variadic function concepts from the main low-level programming project.

## Skills covered


- Build a variadic `_printf` function using `stdarg.h`
- Build a function pointer dispatch table keyed by format specifiers
- Handle literal `%` characters and unknown specifiers gracefully
- Print characters, strings, integers, and unsigned values with correct formatting
- Convert and print binary, octal, and hexadecimal representations
- Build custom specifiers (`S`, `p`, `r`, `R`) beyond standard conversions
- Return accurate character counts excluding the null terminator
- Organize a multi-file C project with a shared header and modular compilation

## Tech Stack

| Category | Technologies |
|----------|-------------|
| Language | C (C99, `gnu89` standard) |
| Compiler | GCC |
| Libraries | `stdarg.h`, `unistd.h` (`write`) |
| Runtime | Ubuntu 20.04+ |

## Project Structure

| File | Role |
|------|------|
| `main.h` | `s_formats` struct, function prototypes, and shared declarations |
| `_printf.c` | Core `_printf`, `handle_specifier`, `handle_char`, and `get_fmt_fn` dispatch |
| `_putchar.c` | Character output helper wrapping `write` |
| `print_char.c` | `%c` — print a single character |
| `print_string.c` | `%s` — print a null-terminated string |
| `print_perc.c` | `%%` — print a literal percent sign |
| `print_int.c` | `%i` — print a signed integer |
| `print_dec.c` | `%d` — print a decimal integer |
| `print_unsigned.c` | `%u` — print an unsigned integer |
| `print_binary.c` | `%b` — print unsigned value in binary |
| `print_oct.c` | `%o` — print unsigned value in octal |
| `print_hex.c` | `%x` — print unsigned value in lowercase hexadecimal |
| `print_hex_bis.c` | `%X` — print unsigned value in uppercase hexadecimal |
| `print_custom_string.c` | `%S` — print string with non-printable chars as hex |
| `print_pointer.c` | `%p` — print a memory address |
| `print_rev.c` | `%r` — print a string in reverse |
| `print_rot13.c` | `%R` — print a string encoded with ROT13 |

## Key Implementations

- **Main formatter (`_printf.c`)** — Iterates the format string; plain characters go through `handle_char` (via `write`); `%` triggers `handle_specifier` which looks up and invokes the matching handler, advancing the index past the specifier
- **Dispatch table (`get_fmt_fn`)** — Maps 14 specifiers (`c`, `s`, `%`, `d`, `i`, `b`, `u`, `o`, `x`, `X`, `S`, `p`, `r`, `R`) to handler function pointers; returns `NULL` for unsupported specifiers
- **Return value semantics** — Accumulates character counts from each handler; returns `-1` on `NULL` format or trailing `%` with no specifier
- **Numeric conversions** — `print_dec`/`print_int` handle signed values; `print_unsigned`, `print_oct`, and `print_hex` decompose unsigned integers digit by digit; `print_binary` renders bit patterns
- **Advanced specifiers** — `print_custom_string` escapes non-printable characters; `print_pointer` formats addresses; `print_rev` and `print_rot13` apply string transformations before output
- **Modular compilation** — Each conversion lives in its own translation unit, compiled and linked together for the final `_printf` library

## Getting Started

### Prerequisites

- Ubuntu 20.04+
- GCC
- Git

### Setup

```bash
git clone <repository-url>
cd printf
```

### Compiling

Compile all source files into a static library or link directly with a test main:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
  -c *.c
ar rcs libprintf.a *.o
```

Or build with a test harness:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \
  *.c main.c -o test_printf
```

### Usage

```c
#include "main.h"

int main(void)
{
    _printf("Hello %s!\n", "World");
    _printf("Decimal: %d, Hex: %x, Binary: %b\n", 42, 255, 10);
    _printf("Pointer: %p\n", (void *)&main);
    return (0);
}
```

### Expected Behavior

```bash
./test_printf
Hello World!
Decimal: 42, Hex: ff, Binary: 1010
Pointer: 0x...
```

## Curriculum Context

Printf is module **0x11** in the ALX low-level C programming project. It is typically completed immediately after variadic functions in the main project and before returning to linked list modules.

| Previous | Next |
|----------|------|
| `alx-low_level_programming` (`0x10-variadic_functions`) | `alx-low_level_programming` (`0x12-singly_linked_lists`) |

Related work:

- `monty` — another dispatch-table interpreter using the same function pointer pattern at a larger scale
- `alx-low_level_programming` — parent project containing the variadic functions module this project extends

# Unit Testing in C

This repository is a library for unit testing your C functions.

## Compilation

To compile the library, run the following command:

```shell
make
```

To use this library, make sure you follow the steps below:

1. Add the macros and library to your compilation.

```
-D REPORT="ut_report()" -D RUN\(test_function\)="ut_run((#test_function), (test_function))" -D ASSERT\(expression\)="if (!ut_assert(__FILE__, __LINE__, (#expression), (expression) ? 1 : 0)) return" -D ASSERT_EQUALS\(expected,\ actual\)="ASSERT((expected) == (actual))" -D ASSERT_STRINGS_EQUALS\(expected,\ actual\)="ASSERT(strcmp((expected),(actual)) == 0)"
```

```
${PATH_TO_LIBRARY}/bin/unit_test.a
```

2. Compile your tests files with macros and unit_test library.

```shell
cc -I${PATH_TO_LIBRARY}/includes/ -D REPORT="ut_report()" -D RUN\(test_function\)="ut_run((#test_function), (test_function))" -D ASSERT\(expression\)="if (!ut_assert(__FILE__, __LINE__, (#expression), (expression) ? 1 : 0)) return" -D ASSERT_EQUALS\(expected,\ actual\)="ASSERT((expected) == (actual))" -D ASSERT_STRINGS_EQUALS\(expected,\ actual\)="ASSERT(strcmp((expected),(actual)) == 0)" ${PATH_TO_LIBRARY}/bin/unit_test.a test_file.c -o test
```

3. Execute your tests.

```shell
./test
```

### Compilation with Makefile

To simplify this process, I recommend you to use Makefile (or equivalent).

Example of rule to compile and execute your tests.

```makefile
# All your tests files
TESTS_SOURCES = your_tests_files.c

tests:
    $(CC) $(CFLAGS) -I${PATH_TO_LIBRARY}/includes/ -D REPORT="ut_report()" -D RUN\(test_function\)="ut_run((#test_function), (test_function))" -D ASSERT\(expression\)="if (!ut_assert(__FILE__, __LINE__, (#expression), (expression) ? 1 : 0)) return" -D ASSERT_EQUALS\(expected,\ actual\)="ASSERT((expected) == (actual))" -D ASSERT_STRINGS_EQUALS\(expected,\ actual\)="ASSERT(strcmp((expected),(actual)) == 0)" ${PATH_TO_LIBRARY}/bin/unit_test.a $(TESTS_SOURCES) -o test
    ./test
.PHONY: tests
```

## Exemple usage

```c
#include "unit_test.h"

int add(int x, int y)
{
    return x + y;
}

void test_add(void)
{
    ASSERT_EQUALS(10, add(8, 2));   // Test success
    ASSERT_EQUALS(20, add(12, 5));  // Test fail
}

void test_string_equal(void)
{
    ASSERT_STRINGS_EQUALS("Hello", "Hello");    // Test success
    ASSERT_STRINGS_EQUALS("Hello", "World");    // Test fail
}

int main(void)
{
    RUN(test_add);
    RUN(test_string_equal);
    return (REPORT);
}
```

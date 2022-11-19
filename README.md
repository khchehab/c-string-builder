# c-string-builder
C string builder written in C.

# API Reference

## Constants
* `SB_MAX_LENGTH`: 1024 - The maximum number of fragments that a string builder can hold.

## Types
### Function Return Enum
* `SB_ERROR`: A function of string builder failed for some reason.
* `SB_NO_ERROR`: A function of string builder was successfully executed.

### String Builder Type
#### `string_builder_t`
The string builder type holds a list of fragments. Each fragment contains the value to append the length of this value as a string.

### Functions
`string_builder_t* sb_init(void)`:
Initializes a string builder and returns a pointer to its memory location.

`void sb_free(string_builder_t* sb)`:
Free the string builder pointer.

`char* sb_to_string(string_builder_t* sb)`:
Returns the string of the string builder which is the concatenation of the string fragments. The string returned from this function has been allocated using `malloc`, so it should be freed using `free` after its no longer used.

`int sb_append_string(string_builder_t* sb, const char* str)`:
Appends a string to the string builder. It will return `SB_NO_ERROR` if there are no errors and `SB_ERROR` if the appending failed.

`int sb_append_char(string_builder_t* sb, const char chr)`:
Appends a single character to the string builder.It will return `SB_NO_ERROR` if there are no errors and `SB_ERROR` if the appending failed.

# Building and Running
The current default target of the Makefile will build and run the tests of the string builder. You can run it by calling `make` in your command line.

```console
user@machine: c-string-builder % make
General Purpose Test Cases
tests/sb_test_cases.c:29:test_sb_zero_appends:PASS

String-based Test Cases
tests/sb_test_cases.c:32:test_sb_string_one_append:PASS
tests/sb_test_cases.c:33:test_sb_string_two_appends:PASS
tests/sb_test_cases.c:34:test_sb_string_multiple_appends:PASS
tests/sb_test_cases.c:35:test_sb_string_max_appends:PASS
tests/sb_test_cases.c:36:test_sb_string_more_than_max_appends:PASS
tests/sb_test_cases.c:37:test_sb_string_multiple_appends_with_null:PASS

Character-based Test Cases
tests/sb_test_cases.c:40:test_sb_char_one_append:PASS
tests/sb_test_cases.c:41:test_sb_char_two_appends:PASS
tests/sb_test_cases.c:42:test_sb_char_multiple_appends:PASS
tests/sb_test_cases.c:43:test_sb_char_max_appends:PASS
tests/sb_test_cases.c:44:test_sb_char_more_than_max_appends:PASS

-----------------------
12 Tests 0 Failures 0 Ignored 
OK
```

# Examples
Below are some examples of the user of the string builder.

```c
#include <stdio.h>
#include <stdlib.h>

#include "string_builder.h"

int main(void) {
    string_builder_t* sb = sb_init();
    
    sb_append_string(sb, "Hello");
    sb_append_string(sb, " ");
    sb_append_string(sb, "World!");
    
    char* string = sb_to_string(sb);
    printf("%s\n", string);

    free(string);
    sb_free(sb);

    return 0;
}
```

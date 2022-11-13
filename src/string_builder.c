#include "string_builder.h"

#include <stdlib.h>
#include <stddef.h>
// TODO FIND A WAY TO CHECK IF string.h EXISTS UNDER THE FILE SYSTEM THEN INCLUDE IT OTHERWISE USE CUSTOM IMPLEMENTATION
#include <string.h>

typedef struct {
    const char* str;
    size_t length;
} string_fragment_t;

// TODO Maybe move the array to a linked list (to avoid having a cap size)
//      Once this has been changed, the change needs to be reflected in the test cases as well.
struct string_builder_ {
    string_fragment_t fragments[SB_MAX_LENGTH];
    size_t total_count;
    size_t pos;
};

#define sb_append_pre_validation(sb) if (sb == NULL || sb->pos >= SB_MAX_LENGTH) { return SB_ERROR; }

void sb_append_fragment(string_builder_t*, size_t, const char*);

string_builder_t* sb_init(void) {
    string_builder_t* sb = malloc(sizeof(string_builder_t));
    sb->total_count = 0;
    sb->pos = 0;
    return sb;
}

void sb_free(string_builder_t* sb) {
    if (sb == NULL) {
        return;
    }

    free(sb);
}

int sb_append_string(string_builder_t* sb, const char* str) {
    if (str == NULL) {
        return SB_NO_ERROR;
    }

    sb_append_pre_validation(sb);
    sb_append_fragment(sb, strlen(str), str);
    return SB_NO_ERROR;
}

int sb_append_char(string_builder_t* sb, const char chr) {
    sb_append_pre_validation(sb);
    sb_append_fragment(sb, 1, &chr);
    return SB_NO_ERROR;
}

char* sb_to_string(string_builder_t* sb) {
    if (sb == NULL || sb->pos < 1) {
        return NULL;
    }

    char* string = malloc(sizeof(char) * (sb->total_count + 1));
    
    size_t i;
    char* temp = string;
    for (i = 0; i < sb->pos; ++i) {
        strcpy(temp, sb->fragments[i].str);
        temp += sb->fragments[i].length;
    }

    return string;
}

/* Private Functions */

void sb_append_fragment(string_builder_t* sb, size_t length, const char* str) {
    sb->fragments[sb->pos++] = (string_fragment_t) { .str = str, .length = length };
    sb->total_count += length;
}

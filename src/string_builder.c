#include "string_builder.h"

#include <stdlib.h>
#include <stddef.h>
// TODO FIND A WAY TO CHECK IF string.h EXISTS UNDER THE FILE SYSTEM THEN INCLUDE IT OTHERWISE USE CUSTOM IMPLEMENTATION
#include <string.h>

typedef struct {
    const char* str;
    size_t length;
    int used_malloc;
} string_fragment_t;

// TODO Maybe move the array to a linked list (to avoid having a cap size)
//      Once this has been changed, the change needs to be reflected in the test cases as well.
struct string_builder_ {
    string_fragment_t fragments[SB_MAX_LENGTH];
    size_t total_count;
    size_t pos;
};

#define sb_append_pre_validation(sb) if (sb == NULL || sb->pos >= SB_MAX_LENGTH) { \
                                         return SB_ERROR;                          \
                                     }
#define sb_append_fragment(sb, len, s, mallocd) size_t length = len;                                                                                   \
                                                sb->fragments[sb->pos++] = (string_fragment_t) { .str = s, .length = length, .used_malloc = mallocd }; \
                                                sb->total_count += length

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

    string_fragment_t fragment;
    size_t i;
    for(i = 0; i < sb->pos; ++i) {
        fragment = sb->fragments[i];
        if (fragment.used_malloc) {
            free((char*) fragment.str);
        }
    }

    free(sb);
}

int sb_append_string(string_builder_t* sb, const char* str) {
    if (str == NULL) {
        return SB_NO_ERROR;
    }

    sb_append_pre_validation(sb);
    sb_append_fragment(sb, strlen(str), str, 0);
    return SB_NO_ERROR;
}

int sb_append_char(string_builder_t* sb, const char chr) {
    sb_append_pre_validation(sb);
    char* str = malloc(sizeof(char) * 2);
    str[0] = chr;
    str[1] = '\0';
    sb_append_fragment(sb, 1, str, 1);
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

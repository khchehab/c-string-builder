#ifndef __STRING_BUILDER_H__
#define __STRING_BUILDER_H__

/**
 * @brief Enum for the function returns of string builder functions.
 */
enum { SB_ERROR, SB_NO_ERROR };

/**
 * @brief The maximum string buffer array size (can append a maximum of this number of strings).
 */
#define SB_MAX_LENGTH 1024

/**
 * @brief A struct that represents a string builder.
 */
typedef struct string_builder_ string_builder_t;

/**
 * @brief Initialize a string builder object.
 * @return string_builder_t* pointer to a string builder object.
 */
string_builder_t* sb_init(void);

/**
 * @brief Free the memory of a string builder object.
 * @param sb string builder object to free.
 */
void sb_free(string_builder_t* sb);

/**
 * @brief Appends a string to the string builder.
 * @param sb string builder object.
 * @param str string to append.
 * @return int return code of the append function.
 */
int sb_append_string(string_builder_t* sb, const char* str);

/**
 * @brief Returns a string containing the appended string fragments.
 *        Note that the returned string has been allocated using malloc, so it needs to be freed when done with it.
 * @param sb string builder object.
 * @return char* string containing the appended string fragments.
 */
char* sb_to_string(string_builder_t* sb);

#endif /* __STRING_BUILDER_H__ */

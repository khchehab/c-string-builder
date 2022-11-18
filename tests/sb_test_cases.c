#include <stdio.h>
#include <stdlib.h>

#include "Unity/unity.h"
#include "string_builder.h"

void test_sb_zero_appends(void);

void test_sb_string_one_append(void);
void test_sb_string_two_appends(void);
void test_sb_string_multiple_appends(void);
void test_sb_string_max_appends(void);
void test_sb_string_more_than_max_appends(void);
void test_sb_string_multiple_appends_with_null(void);

void test_sb_char_one_append(void);
void test_sb_char_two_appends(void);
void test_sb_char_multiple_appends(void);
void test_sb_char_max_appends(void);
void test_sb_char_more_than_max_appends(void);

void setUp(void) {}
void tearDown(void) {}

int main(int argc, const char** argv) {
    UNITY_BEGIN();

    printf("General Purpose Test Cases\n");
    RUN_TEST(test_sb_zero_appends);

    printf("\nString-based Test Cases\n");
    RUN_TEST(test_sb_string_one_append);
    RUN_TEST(test_sb_string_two_appends);
    RUN_TEST(test_sb_string_multiple_appends);
    RUN_TEST(test_sb_string_max_appends);
    RUN_TEST(test_sb_string_more_than_max_appends);
    RUN_TEST(test_sb_string_multiple_appends_with_null);

    printf("\nCharacter-based Test Cases\n");
    RUN_TEST(test_sb_char_one_append);
    RUN_TEST(test_sb_char_two_appends);
    RUN_TEST(test_sb_char_multiple_appends);
    RUN_TEST(test_sb_char_max_appends);
    RUN_TEST(test_sb_char_more_than_max_appends);

    return UNITY_END();
}

void test_sb_zero_appends(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    char* string = sb_to_string(sb);
    TEST_ASSERT_NULL(string);
    TEST_ASSERT_EMPTY(string);

    free(string);
    sb_free(sb);
}

#include <stdlib.h>

#include "Unity/unity.h"
#include "string_builder.h"

void test_sb_zero_appends(void);
void test_sb_one_append(void);
void test_sb_two_appends(void);
void test_sb_multiple_appends(void);
void test_sb_max_appends(void);
void test_sb_more_than_max_appends(void);

void setUp(void) {}
void tearDown(void) {}

int main(int argc, const char** argv) {
    UNITY_BEGIN();

    RUN_TEST(test_sb_zero_appends);
    RUN_TEST(test_sb_one_append);
    RUN_TEST(test_sb_two_appends);
    RUN_TEST(test_sb_multiple_appends);
    RUN_TEST(test_sb_max_appends);
    RUN_TEST(test_sb_more_than_max_appends);

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

void test_sb_one_append(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    int ret = sb_append_string(sb, "Hello World!");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);

    char* string = sb_to_string(sb);
    TEST_ASSERT_NOT_NULL(string);
    TEST_ASSERT_NOT_EMPTY(string);
    TEST_ASSERT_EQUAL_STRING("Hello World!", string);

    free(string);
    sb_free(sb);
}

void test_sb_two_appends(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    int ret = sb_append_string(sb, "Hello");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    ret = sb_append_string(sb, " World!");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);

    char* string = sb_to_string(sb);
    TEST_ASSERT_NOT_NULL(string);
    TEST_ASSERT_NOT_EMPTY(string);
    TEST_ASSERT_EQUAL_STRING("Hello World!", string);

    free(string);
    sb_free(sb);
}

void test_sb_multiple_appends(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    int ret = sb_append_string(sb, "Hello");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    ret = sb_append_string(sb, " ");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    ret = sb_append_string(sb, "World");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    ret = sb_append_string(sb, "!");
    TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);

    char* string = sb_to_string(sb);
    TEST_ASSERT_NOT_NULL(string);
    TEST_ASSERT_NOT_EMPTY(string);
    TEST_ASSERT_EQUAL_STRING("Hello World!", string);

    free(string);
    sb_free(sb);
}

void test_sb_max_appends(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    const char* str = "AB";
    int ret, i;
    for (i = 0; i < SB_MAX_LENGTH; ++i) {
        ret = sb_append_string(sb, str);
        TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    }

    char* string = sb_to_string(sb);
    TEST_ASSERT_NOT_NULL(string);
    TEST_ASSERT_NOT_EMPTY(string);
    TEST_ASSERT_EQUAL_STRING(
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB",
        string
    );

    free(string);
    sb_free(sb);
}

void test_sb_more_than_max_appends(void) {
    string_builder_t* sb = sb_init();
    TEST_ASSERT_NOT_NULL(sb);

    const char* str = "AB";
    int ret, i;
    for (i = 0; i < SB_MAX_LENGTH; ++i) {
        ret = sb_append_string(sb, str);
        TEST_ASSERT_EQUAL_INT(SB_NO_ERROR, ret);
    }

    ret = sb_append_string(sb, str);
    TEST_ASSERT_EQUAL_INT(SB_ERROR, ret);

    char* string = sb_to_string(sb);
    TEST_ASSERT_NOT_NULL(string);
    TEST_ASSERT_NOT_EMPTY(string);
    TEST_ASSERT_EQUAL_STRING(
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB"
        "ABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABABAB",
        string
    );

    free(string);

    sb_free(sb);
}

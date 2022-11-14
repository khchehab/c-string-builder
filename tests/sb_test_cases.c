#include "Unity/unity.h"
#include "string_builder.h"

void test_sb_string_zero_appends(void);
void test_sb_string_one_append(void);
void test_sb_string_two_appends(void);
void test_sb_string_multiple_appends(void);
void test_sb_string_max_appends(void);
void test_sb_string_more_than_max_appends(void);
void test_sb_string_multiple_appends_with_null(void);

void setUp(void) {}
void tearDown(void) {}

int main(int argc, const char** argv) {
    UNITY_BEGIN();

    RUN_TEST(test_sb_string_zero_appends);
    RUN_TEST(test_sb_string_one_append);
    RUN_TEST(test_sb_string_two_appends);
    RUN_TEST(test_sb_string_multiple_appends);
    RUN_TEST(test_sb_string_max_appends);
    RUN_TEST(test_sb_string_more_than_max_appends);
    RUN_TEST(test_sb_string_multiple_appends_with_null);

    return UNITY_END();
}

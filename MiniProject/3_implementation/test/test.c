#include "unity.h"
#include "coronapatients.h"

void setUp() {}

void tearDown() {}

void testing_addbed(void)
{
    TEST_ASSERT_EQUAL(1,addbed());
}

void testing_deletebed(void)
{
    TEST_ASSERT_EQUAL(1,deletebed());
}

void testing_bed(void)
{
    TEST_ASSERT_EQUAL(1,bed());
}

int test_main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testing_addbed);
    RUN_TEST(testing_deletebed);
    RUN_TEST(testing_bed);
    return UNITY_END();
}


#include <gtest/gtest.h>
#include "../include/rf.h"

// 샘플 테스트
TEST(rf_test, basicTest) {
    rf obj;
    EXPECT_EQ(5, 5);
}

// 메인 함수 (GTest 실행)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
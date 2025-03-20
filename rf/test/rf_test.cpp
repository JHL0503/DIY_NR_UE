#include <gtest/gtest.h>
#include "../include/rf.h"

// 샘플 테스트
TEST(rf_test, basicTest) {
    rf_args_t rf_args;
    rf_args.rf_dev_args.freq_offset     = 0;
    rf_args.rf_dev_args.tx_gain         = 50;
    rf_args.rf_dev_args.rx_gain         = 40;
    rf_args.rf_dev_args.srate           = 43.04e6;
    rf_args.rf_dev_args.nof_channels    = 1;



    rf obj;
    obj.init(rf_args);

    EXPECT_EQ(5, 5);
}

// 메인 함수 (GTest 실행)
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
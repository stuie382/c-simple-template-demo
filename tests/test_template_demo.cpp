/**
 * Add your test code here.
 */

#include "gtest/gtest.h"
#include <cstdio>
extern "C" {
#include "../include/template_demo/library.h"
}


class BowlingTest : public testing::Test {

    void SetUp() override {
        b = bowling_init();
    }

    void TearDown() override {
        bowling_free(b);
    }

public:
    struct bowling *b = nullptr;

    void roll_multiple(size_t num_rolls, int score) const {
        for (size_t i = 0; i < num_rolls; i++)
            roll_ball(b, score);
    }

    void roll_spare() const {
        roll_ball(b, 5);
        roll_ball(b, 5);
    }

};




TEST_F(BowlingTest, test_bowling_gutter_game) {
    roll_multiple(20, 0);
    EXPECT_EQ(0, score_game(b));
}

TEST_F(BowlingTest, test_bowling_all_ones) {
    roll_multiple(20, 1);
    EXPECT_EQ(20, score_game(b));
}


TEST_F(BowlingTest, test_bowling_one_spare) {
    roll_spare();
    roll_ball(b, 3);
    roll_multiple(17, 0);
    EXPECT_EQ(16, score_game(b));
}

TEST_F(BowlingTest, test_bowling_one_strike) {
    roll_ball(b, 10);
    roll_ball(b, 3);
    roll_ball(b, 5);
    roll_multiple(17, 0);
    EXPECT_EQ(26, score_game(b));
}

TEST_F(BowlingTest, test_bowling_perfect_game) {
    roll_multiple(12, 10);
    EXPECT_EQ(300, score_game(b));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
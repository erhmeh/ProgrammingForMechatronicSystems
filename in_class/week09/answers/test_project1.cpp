#include "gtest/gtest.h"
#include "project1.h"

TEST(SquareRootTest, PositiveNos) { 
    EXPECT_EQ (18.0, squareroot (324.0));
    EXPECT_EQ (25.4, squareroot (645.16));
    EXPECT_EQ (50.3321, squareroot (2533.310224));
}

TEST (SquareRootTest, ZeroAndNegativeNos) { 
    ASSERT_EQ (0.0, squareroot (0.0));
    ASSERT_EQ (-1, squareroot (-22.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

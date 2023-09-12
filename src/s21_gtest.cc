#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(Test, Constructor_1) {
  S21Matrix A;
  EXPECT_EQ(0, A.GetRows());
  EXPECT_EQ(0, A.GetColumns());
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
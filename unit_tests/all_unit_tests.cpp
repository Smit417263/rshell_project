#include "gtest/gtest.h"

#include "classes_unit_test.h"
#include "test_unit_test.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

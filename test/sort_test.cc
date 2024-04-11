#include <vector>

#include "gtest/gtest.h"
#include "src/lib/sort/sortset.h"

class RandomArray : public ::testing::Test {
 protected:
  void SetUp() override { nums_ = std::vector<int>({3, 2, 1, 5, 4}); }

  void TearDown() override { nums_.clear(); }

  void OrderChecker() {
    EXPECT_EQ(nums_[0], 1);
    EXPECT_EQ(nums_[1], 2);
    EXPECT_EQ(nums_[2], 3);
    EXPECT_EQ(nums_[3], 4);
    EXPECT_EQ(nums_[4], 5);
  }

  std::vector<int> nums_;
};

TEST_F(RandomArray, QuickSort) {
  sort::SortSet::Sort(nums_, sort::kQuickSort);
  OrderChecker();
}

TEST_F(RandomArray, MergeSort) {
  sort::SortSet::Sort(nums_, sort::kMergeSort);
  OrderChecker();
}

TEST_F(RandomArray, BubbleSort) {
  sort::SortSet::Sort(nums_, sort::kBubbleSort);
  OrderChecker();
}

#include <algorithm>
#include <vector>

namespace sort {

enum SortType {
  kQuickSort,
  kMergeSort,
  kBubbleSort,
};

class SortSet {
 public:
  static void Sort(std::vector<int> &nums, SortType sortType);

 private:
  static void SortImpl(std::vector<int> &nums, SortType sortType);

  static void QuickSortImpl(std::vector<int> &nums, int left, int right);

  static void MergeSortImpl(std::vector<int> &nums, int left, int right);
  static void Merge(std::vector<int> &nums, int left, int mid, int right);

  static void BubbleSortImpl(std::vector<int> &nums);
};

}  // namespace sort

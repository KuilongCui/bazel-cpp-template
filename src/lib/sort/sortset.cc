#include "sortset.h"

#include <iostream>

#include "glog/logging.h"

namespace sort {

void SortSet::Sort(std::vector<int> &nums, SortType sortType) {
  SortImpl(nums, sortType);
}

void SortSet::SortImpl(std::vector<int> &nums, SortType sortType) {
  switch (sortType) {
    case kQuickSort:
      QuickSortImpl(nums, 0, nums.size() - 1);
      break;
    case kMergeSort:
      MergeSortImpl(nums, 0, nums.size() - 1);
      break;
    case kBubbleSort:
      BubbleSortImpl(nums);
      break;
    default:
      LOG(WARNING) << "Invalid sort type: " << sortType;
      break;
  }
}

void SortSet::QuickSortImpl(std::vector<int> &nums, int left, int right) {
  if (left < right) {
    int pivot = left;
    int i = left;
    int j = right;
    while (i < j) {
      while (nums[i] <= nums[pivot] && i < right) {
        i++;
      }
      while (nums[j] > nums[pivot]) {
        j--;
      }
      if (i < j) {
        std::swap(nums[i], nums[j]);
      }
    }
    std::swap(nums[pivot], nums[j]);
    QuickSortImpl(nums, left, j - 1);
    QuickSortImpl(nums, j + 1, right);
  }
}

void SortSet::MergeSortImpl(std::vector<int> &nums, int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    MergeSortImpl(nums, left, mid);
    MergeSortImpl(nums, mid + 1, right);
    Merge(nums, left, mid, right);
  }
}

void SortSet::Merge(std::vector<int> &nums, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> l(n1);
  std::vector<int> r(n2);

  for (int i = 0; i < n1; i++) {
    l[i] = nums[left + i];
  }
  for (int j = 0; j < n2; j++) {
    r[j] = nums[mid + 1 + j];
  }

  int i = 0;
  int j = 0;
  int k = left;

  while (i < n1 && j < n2) {
    if (l[i] <= r[j]) {
      nums[k++] = l[i++];
    } else {
      nums[k++] = r[j++];
    }
  }

  while (i < n1) {
    nums[k++] = l[i++];
  }

  while (j < n2) {
    nums[k++] = r[j++];
  }
}

void SortSet::BubbleSortImpl(std::vector<int> &nums) {
  int n = nums.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        std::swap(nums[j], nums[j + 1]);
      }
    }
  }
}

}  // namespace sort

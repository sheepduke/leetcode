/*
  Suppose an array sorted in ascending order is rotated at some pivot unknown
  to you beforehand.

  (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

  You are given a target value to search. If found in the array return its
  index, otherwise return -1.

  You may assume no duplicate exists in the array.

  Your algorithm's runtime complexity must be in the order of O(log n).

  Example 1:

  Input: nums = [4,5,6,7,0,1,2], target = 0
  Output: 4

  Example 2:

  Input: nums = [4,5,6,7,0,1,2], target = 3
  Output: -1
*/

#include "../util/common.hpp"

class Solution {
public:
  int search(const vector<int>& nums, int target) {
    // Deal with special cases.
    if (nums.empty()) {
      return -1;
    }
    if (nums.size() == 1) {
      return (nums[0] == target ? 0 : -1);
    }
    auto pivot = find_pivot(nums);
    auto size = nums.size();
    for (auto [left, right] = make_tuple(0, int(size - 1)); left <= right; ) {
      auto mid = left + (right - left) / 2;
      auto mid_index = (mid + pivot) % size;
      if (nums[mid_index] == target) {
        return mid_index;
      }
      else if (nums[mid_index] < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    return -1;
  }

  /**
   * Find the pivot using binary search and return it.
   */
  size_t find_pivot(const vector<int> &nums) {
    for (auto [left, right] = make_tuple(0, int(nums.size() - 1)); left <= right;) {
      auto mid = left + (right - left) / 2;
      if (nums[mid] > nums[mid + 1]) {
        return mid + 1;
      }
      // Compare the current value with right-most value to get the shift
      // direction.
      if (nums[mid] > *rbegin(nums)) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
    return 0;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{4, 5, 6, 7, 0, 1, 2};

  assert(solution.search(nums, 0) == 4);
  assert(solution.search(nums, 3) == -1);
  assert(solution.search({1}, 0) == -1);
  assert(solution.search({1, 3}, 0) == -1);
  assert(solution.search({5, 1, 3}, 5) == 0);
  
  return 0;
}

/*
  Given a sorted array and a target value, return the index if the target is
  found. If not, return the index where it would be if it were inserted in
  order.

  You may assume no duplicates in the array.

  Example 1:

  Input: [1,3,5,6], 5
  Output: 2

  Example 2:

  Input: [1,3,5,6], 2
  Output: 1

  Example 3:

  Input: [1,3,5,6], 7
  Output: 4

  Example 4:

  Input: [1,3,5,6], 0
  Output: 0

*/

#include "../util/common.hpp"

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      auto mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return left;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{1, 3, 5, 6};
  auto result = solution.searchInsert(nums, 5);
  assert(result == 2);

  result = solution.searchInsert(nums, 2);
  assert(result == 1);

  result = solution.searchInsert(nums, 7);
  assert(result == 4);

  result = solution.searchInsert(nums, 0);
  assert(result == 0);

  return 0;
}

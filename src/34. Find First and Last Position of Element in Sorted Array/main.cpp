/**
   Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

   Your algorithm's runtime complexity must be in the order of O(log n).

   If the target is not found in the array, return [-1, -1].

   Example 1:

   Input: nums = [5,7,7,8,8,10], target = 8
   Output: [3,4]

   Example 2:

   Input: nums = [5,7,7,8,8,10], target = 6
   Output: [-1,-1]
*/

#include "../util/common.hpp"

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto result = vector<int>{-1, -1};

    if (nums.size() == 0) {
      return result;
    }

    // Find the left range.
    auto left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      auto mid = (right - left) / 2 + left;
      // cout << left << " " << mid << " " << right << endl;
      if (nums[mid] == target) {
        result[0] = mid;
      }
      if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    left = 0u;
    right = nums.size() - 1;
    while (left <= right) {
      auto mid = (right - left) / 2 + left;
      // cout << left << ", " << mid << ", " << right << endl;
      if (nums[mid] == target) {
        result[1] = mid;
      }
      if (nums[mid] <= target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    // cout << "Result: " << result << endl;
    return result;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{5, 7, 7, 8, 8, 10};
  auto result = solution.searchRange(nums, 8);
  assert(result.size() == 2 && result[0] == 3 && result[1] == 4);

  nums = {5, 7, 7, 8, 8, 10};
  result = solution.searchRange(nums, 6);
  assert(result.size() == 2 && result[0] == -1 && result[1] == -1);

  nums = {1};
  result = solution.searchRange(nums, 1);
  assert(result.size() == 2 && result[0] == 0 && result[1] == 0);

  nums = {1, 1};
  result = solution.searchRange(nums, 1);
  assert(result.size() == 2 && result[0] == 0 && result[1] == 1);

  nums = {1, 1, 1};
  result = solution.searchRange(nums, 1);
  assert(result.size() == 2 && result[0] == 0 && result[1] == 2);

  return 0;
}

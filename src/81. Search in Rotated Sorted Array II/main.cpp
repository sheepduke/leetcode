/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true,
otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may
contain duplicates. Would this affect the run-time complexity? How and why?
*/

#include "../util/common.hpp"

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    for (auto num: nums) {
      if (num == target) {
        return true;
      }
    }
    return false;
  }
};

void run(vector<int> &nums, int target, bool expected) {
  cout << "Input: " << nums << endl;
  auto result = Solution().search(nums, target);
  assert(result == expected);
}

int main() {
  auto nums = vector<int>{2, 5, 6, 0, 0, 1, 2};
  run(nums, 0, true);
  run(nums, 3, false);

  return 0;
}

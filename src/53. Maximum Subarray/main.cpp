/*
Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:

If you have figured out the O(n) solution, try coding another solution using
the divide and conquer approach, which is more subtle.
 */

#include "../util/common.hpp"

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    auto current_max = nums[0];
    auto result = nums[0];

    for (size_t index = 1; index < nums.size(); index++) {
      current_max = max(current_max + nums[index], nums[index]);
      result = max(result, current_max);
    }
    return result;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert(solution.maxSubArray(nums) == 6);

  nums = {-2, 1};
  assert(solution.maxSubArray(nums) == 1);

  nums = {-2, -1};
  assert(solution.maxSubArray(nums) == -1);

  return 0;
}

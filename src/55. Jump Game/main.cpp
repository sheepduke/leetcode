/*
Given an array of non-negative integers, you are initially positioned at the
first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.
 */

#include "../util/common.hpp"

class Solution {
public:
  bool canJump(vector<int>& nums) {
    auto steps = 1;
    for (int index = nums.size() - 2; index >= 0; index--) {
      if (nums[index] >= steps) {
        steps = 1;
      }
      else {
        steps++;
      }
    }

    return steps == 1;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{2, 3, 1, 1, 4};
  assert(solution.canJump(nums));

  nums = {3, 2, 1, 0, 4};
  assert(!solution.canJump(nums));

  nums = {2, 5, 0, 0, 0};
  assert(solution.canJump(nums));

  nums = {0};
  assert(solution.canJump(nums));

  return 0;
}

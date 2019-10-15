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
    if (nums.size() < 2) {
      return true;
    }

    auto index = size_t(0);
    while (index < nums.size()) {
      if (nums[index] == 0) {
        return false;
      }
      if (index + nums[index] >= nums.size() - 1) {
        return true;
      }
      auto max_jump_length = 0;
      auto jump_step = 0;
      for (auto i = 1; i <= nums[index]; i++) {
        auto jump_length = i + nums[index + i];
        if (jump_length > max_jump_length) {
          max_jump_length = jump_length;
          jump_step = i;
        }
      }
      index += jump_step;
    }
    return true;
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

  return 0;
}

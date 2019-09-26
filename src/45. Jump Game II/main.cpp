/*
  Given an array of non-negative integers, you are initially positioned at the
  first index of the array.

  Each element in the array represents your maximum jump length at that position.

  Your goal is to reach the last index in the minimum number of jumps.

  Example:

  Input: [2,3,1,1,4]
  Output: 2
  Explanation: The minimum number of jumps to reach the last index is 2.
  Jump 1 step from index 0 to 1, then 3 steps to the last index.

  Note:

  You can assume that you can always reach the last index.

 */

#include "../util/common.hpp"

class Solution {
public:
  int jump(vector<int> &nums) {
    if (nums.size() < 2) {
      return 0;
    }

    auto steps = map<unsigned int, unsigned int>();
    for (int index = nums.size() - 1; index >= 0; index--) {
      // If the end point is within the range, just set it to 1.
      // Otherwise, calculate the steps.
      if (nums[index] >= nums.size() - 1 - index) {
        steps[index] = 1;
      } else {
        auto min_step = steps[index + 1] + 1;
        for (int step = 2; step <= nums[index]; step++) {
          min_step = min(min_step, steps[index + step] + 1);
        }
        steps[index] = min_step;
      }
    }
    return steps[0];
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{2, 3, 1, 1, 4};
  assert(solution.jump(nums) == 2);
  
  nums = {1, 2, 1, 1, 1};
  assert(solution.jump(nums) == 3);

  return 0;
}

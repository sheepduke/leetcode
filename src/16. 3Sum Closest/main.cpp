/*
  Given an array nums of n integers and an integer target, find three integers
  in nums such that the sum is closest to target. Return the sum of the three
  integers. You may assume that each input would have exactly one solution.

  Example:

  Given array nums = [-1, 2, 1, -4], and target = 1.

  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/

#include "../util/common.hpp"

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    sort(begin(nums), end(nums), less<>());

    auto result = 0;
    auto min_diff = INT_MAX;
    for (auto first = begin(nums); first < end(nums) - 2; first++) {
      for (auto second = first + 1; second < end(nums) - 1; second++) {
        for (auto third = second + 1; third < end(nums); third++) {
          auto sum = *first + *second + *third;
          auto diff = abs(sum - target);
          if (diff == 0) {
            return sum;
          } else if (diff < min_diff) {
            min_diff = diff;
            result = sum;
          }
        }
      }
    }
    return result;
  }
};


int main() {
  Solution solution;
  vector<int> input = {-1, 2, 1, -4};

  assert(solution.threeSumClosest(input, 1) == 2);

  input = {0, 5, -1, -2, 4, -1, 0, -3, 4, -5};
  assert(solution.threeSumClosest(input, 1) == 1);

  return 0;
}

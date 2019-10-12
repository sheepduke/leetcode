/*
Given an array nums of n integers and an integer target, are there elements a,
b, c, and d in nums such that a + b + c + d = target? Find all unique
quadruplets in the array which gives the sum of target.

Note:

The solution set must not contain duplicate quadruplets.

Example:

Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) {
      return vector<vector<int>>();
    }
    sort(begin(nums), end(nums));
    auto result = vector<vector<int>>();
    auto num_last_index = map<int, size_t>();
    for (int index = nums.size() - 1; index >= 0; index--) {
      if (num_last_index.find(nums[index]) == end(num_last_index)) {
        num_last_index[nums[index]] = index;
      }
    }
    auto size = nums.size();
    for (size_t first = 0; first < nums.size() - 3; first++) {
      if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) {
        break;
      }
      if (nums[first] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target
          || (first > 0 && nums[first] == nums[first - 1])) {
        continue;
      }
      for (size_t second = first + 1; second < nums.size() - 2; second++) {
        if (nums[first] + nums[second] + nums[second + 1]
            + nums[second + 2] > target) {
          break;
        }
        if (nums[first] + nums[second] + nums[size - 2] + nums[size - 1] < target
            || (second > first + 1 && nums[second] == nums[second - 1])) {
          continue;
        }
        for (size_t third = second + 1; third < nums.size() - 1; third++) {
          if (nums[first] + nums[second] + nums[third]
              + nums[third + 1] > target) {
            break;
          }
          if (third > second + 1 && nums[third] == nums[third - 1]) {
            continue;
          }
          auto four_num = target - nums[first] - nums[second] - nums[third];
          if (num_last_index.find(four_num) != end(num_last_index)
              && num_last_index[four_num] > third) {
            result.push_back(vector<int>{nums[first], nums[second],
                  nums[third], four_num});
          }
        }
      }
    }
    return result;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{1, 0, -1, 0, -2, 2};

  auto result = solution.fourSum(nums, 0);
  cout << "Result:" << endl << result << endl;

  nums = {-3, -2, -1, 0, 0, 1, 2, 3};
  result = solution.fourSum(nums, 0);
  cout << "Result:" << endl << result << endl;

  return 0;
}

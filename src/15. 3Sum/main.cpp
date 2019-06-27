/*

  Given an array nums of n integers, are there elements a, b, c in nums such
  that a + b + c = 0? Find all unique triplets in the array which gives the sum
  of zero.

  Note:

  The solution set must not contain duplicate triplets.

  Example:

  Given array nums = [-1, 0, 1, 2, -1, -4],

  A solution set is:
  [
  [-1, 0, 1],
  [-1, -1, 2]
  ]

*/

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
      return {{}};
    }
    
    sort(begin(nums), end(nums), less<>());

    // Map from integer to its count.
    map<int, unsigned int> num_count;
    for (auto num : nums) {
      num_count[num]++;
    }

    vector<vector<int>> result;
    for (auto first = begin(nums); first < end(nums) - 2; first++) {
      for (auto second = first + 1; second < end(nums) - 1; second++) {
        auto target = 0 - *first - *second;
        if (num_count.find(target) != end(num_count)) {
          if (target > *second
              || (target == *second
                  && num_count[target] > (*first == *second ? 2 : 1))) {
            result.push_back({*first, *second, target});
          }
        }
        while (*(second + 1) == *second) second++;
      }
      while (*(first + 1) == *first) first++;
    }
    return result;
  }
};

int main() {
  Solution solution;

  vector<int> input = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = {{-1, -1, 2}, {-1, 0, 1}};
  assert(solution.threeSum(input) == result);

  input = {-1, 0, 1};
  result = {{-1, 0, 1}};
  assert(solution.threeSum(input) == result);

  input = {0, 0, 0};
  result = {{0, 0, 0}};
  assert(solution.threeSum(input) == result);

  input = {0, 0, 0, 0};
  result = {{0, 0, 0}};
  assert(solution.threeSum(input) == result);

  input = {};
  result = {{}};
  assert(solution.threeSum(input) == result);

  return 0;
}

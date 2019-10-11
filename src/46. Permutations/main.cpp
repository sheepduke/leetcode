/*
  Given a collection of distinct integers, return all possible permutations.

  Example:

  Input: [1,2,3]
  Output:
  [
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
  ]
*/

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    auto result = vector<vector<int>>();
    solve(result, nums, 0);
    return result;
  }

private:
  void solve(vector<vector<int>> &result, vector<int> &nums, size_t index) {
    if (index == nums.size() - 1) {
      result.push_back(nums);
    }
    else {
      for (int i = index; i < nums.size(); i++) {
        swap(nums, i, index);
        solve(result, nums, index + 1);
        swap(nums, i, index);
      }
    }
  }

  void swap(vector<int> &nums, size_t a, size_t b) {
    auto temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>();

  for (int i = 0; i < 11; i++) {
    nums.push_back(i);
  }

  solution.permute(nums);

  return 0;
}

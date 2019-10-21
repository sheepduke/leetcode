/*
Given a set of distinct integers, nums, return all possible subsets (the power
set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    auto result = vector<vector<int>>();
    auto selected = vector<int>();
    for (auto count = 0; count <= nums.size(); count++) {
      solve(result, selected, nums, count, 0);
    }
    return result;
  }

private:
  void solve(vector<vector<int>> &result, vector<int> &selected,
             const vector<int> &nums, int count, int start_index) {
    if (count == 0) {
      result.push_back(selected);
    }
    else {
      for (auto index = start_index; index < int(nums.size()); index++) {
        selected.push_back(nums[index]);
        solve(result, selected, nums, count - 1, index + 1);
        selected.pop_back();
      }
    }
  }
};

int main() {
  auto nums = vector<int>{1, 2, 3};
  auto result = Solution().subsets(nums);
  cout << "Result: " << endl
       << result << endl;

  return 0;
}

/*
Given two integers n and k, return all possible combinations of k numbers out
of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]


 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    auto combinations = vector<vector<int>>();
    auto nums = vector<int>();
    for (auto i = 1; i <= n; i++) {
      nums.push_back(i);
    }
    auto selected = vector<int>();
    solve(combinations, nums, selected, k, 0);
    return combinations;
  }

private:
  void solve(vector<vector<int>> &combinations,
             const vector<int> &nums, vector<int> &selected,
             int count, int start_index) {
    if (count == 0) {
      combinations.push_back(selected);
    }
    else {
      for (auto index = start_index; index < int(nums.size()); index++) {
        selected.push_back(nums[index]);
        solve(combinations, nums, selected, count - 1, index + 1);
        selected.pop_back();
      }
    }
  }
};

int main() {
  cout << "Result: " << endl
       << Solution().combine(4, 2)
       << endl;

  return 0;
}

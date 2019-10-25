/*
Given a collection of integers that might contain duplicates, nums, return all
possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    auto result = vector<vector<int>>();
    auto taken = vector<int>();
    sort(begin(nums), end(nums));
    for (auto count = 0u; count <= nums.size(); count++) {
      solve(result, nums, taken, count, 0);
    }
    return result;
  }

private:
  void solve(vector<vector<int>> &subsets, const vector<int> &nums,
             vector<int> &taken, size_t count, size_t begin_index) {
    if (count == 0) {
      subsets.push_back(taken);
    }
    else {
      for (auto index = begin_index; index < nums.size(); index++) {
        if (index > begin_index && nums[index] == nums[index - 1]) {
          continue;
        }
        taken.push_back(nums[index]);
        solve(subsets, nums, taken, count - 1, index + 1);
        taken.pop_back();
      }
    }
  }
};

void run(vector<int> &nums, int expected_count) {
  auto result = Solution().subsetsWithDup(nums);
  cout << "Result: " << endl << result << endl;
  assert(result.size() == expected_count);
}

int main() {
  auto nums = vector<int>{1, 2, 2};
  run(nums, 6);

  nums = {1, 2, 3};
  run(nums, 8);

  return 0;
}

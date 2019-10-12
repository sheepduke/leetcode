/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(begin(nums), end(nums));
    auto result = vector<vector<int>>();
    auto taken = set<int>();
    solve(result, nums, 0);
    return result;
  }

private:
  void solve(vector<vector<int>> &result, vector<int> &nums, size_t index) {
    if (index == nums.size() - 1) {
      result.push_back(nums);
    }
    else {
      auto front_elements = set<int>();
      for (size_t i = index; i < nums.size(); i++) {
        if (front_elements.find(nums[i]) == end(front_elements)) {
          front_elements.insert(nums[i]);
        }
      }
      for (size_t i = index; i < nums.size(); i++) {
        if (front_elements.find(nums[i]) != end(front_elements)) {
          swap(nums, i, index);
          solve(result, nums, index + 1);
          swap(nums, i, index);
          front_elements.erase(nums[i]);
        }
      }
    }
  }

  void swap(vector<int> &nums, size_t index1, size_t index2) {
    auto temp = nums[index1];
    nums[index1] = nums[index2];
    nums[index2] = temp;
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{1, 2, 2, 1, 3};
  // auto nums = vector<int>{1, 2, 3};
  auto result = solution.permuteUnique(nums);

  cout << "Result: " << endl
       << result << endl;

  return 0;
}

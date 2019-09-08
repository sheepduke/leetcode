/*
  Given a set of candidate numbers (candidates) (without duplicates) and a
  target number (target), find all unique combinations in candidates where the
  candidate numbers sums to target.

  The same repeated number may be chosen from candidates unlimited number of times.

  Note:

  All numbers (including target) will be positive integers.
  The solution set must not contain duplicate combinations.

  Example 1:

  Input: candidates = [2,3,6,7], target = 7,
  A solution set is:
  [
  [7],
  [2,2,3]
  ]

  Example 2:

  Input: candidates = [2,3,5], target = 8,
  A solution set is:
  [
  [2,2,2,2],
  [2,3,3],
  [3,5]
  ]

*/

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    auto result = vector<vector<int>>();
    auto current_solution = vector<int>();
    sort(begin(candidates), end(candidates));
    auto real_candidates = deque<int>(begin(candidates), end(candidates));
    solve(result, current_solution, real_candidates, target);

    return result;
  }

private:
  void solve(vector<vector<int>> &solutions, vector<int> &solution,
             deque<int> &candidates, int target) {
    // cout << "Candidates: " << candidates << endl
    //      << "Solution: [" << solution << "] => " << target << endl
    //      << endl;
    if (target == 0) {
      solutions.push_back(solution);
      return ;
    }
    if (candidates.empty()) {
      return ;
    }
    auto candidate = candidates.front();
    if (candidate <= target) {
      // Take current candidate.
      solution.push_back(candidate);
      solve(solutions, solution, candidates, target - candidate);
      solution.pop_back();
      // Do not take current candidate.
      candidates.pop_front();
      solve(solutions, solution, candidates, target);
      candidates.push_front(candidate);
    }
  }
};

int main() {
  Solution solution;

  auto nums = vector<int>{2, 3, 6, 7};
  cout << "Result: " << endl
       << solution.combinationSum(nums, 7) << endl;

  nums = {2, 3, 5};
  cout << "Result: " << endl
       << solution.combinationSum(nums, 8) << endl;

  nums = vector<int>{8 ,7, 4, 3};
  cout << "Result: " << endl
       << solution.combinationSum(nums, 11) << endl;

  return 0;
}

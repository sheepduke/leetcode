/*
  Given a collection of candidate numbers (candidates) and a target number
  (target), find all unique combinations in candidates where the candidate
  numbers sums to target.

  Each number in candidates may only be used once in the combination.

  Note:

  All numbers (including target) will be positive integers.
  The solution set must not contain duplicate combinations.

  Example 1:

  Input: candidates = [10,1,2,7,6,1,5], target = 8,
  A solution set is:
  [
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
  ]

  Example 2:

  Input: candidates = [2,5,2,1,2], target = 5,
  A solution set is:
  [
  [1,2,2],
  [5]
  ]

*/

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(begin(candidates), end(candidates));
    auto solutions = vector<vector<int>>();
    auto solution = vector<int>();
    auto candidates_deque = deque<int>(begin(candidates), end(candidates));
    solve(solutions, solution, candidates_deque, target);
    return solutions;
  }

private:
  void solve(vector<vector<int>> &solutions, vector<int> &solution,
             deque<int> &candidates, int target) {
    if (target == 0) {
      solutions.push_back(solution);
      return ;
    }
    if (!candidates.empty()) {
      auto candidate = candidates.front();
      if (candidate <= target) {
        candidates.pop_front();
        auto pop_count = 1u;
        
        // Take it!
        solution.push_back(candidate);
        solve(solutions, solution, candidates, target - candidate);
        solution.pop_back();
        // Not taking it.
        while (candidates.front() == candidate) {
          candidates.pop_front();
          pop_count++;
        }
        solve(solutions, solution, candidates, target);

        for (; pop_count > 0; pop_count--) {
          candidates.push_front(candidate);
        }
      }
    }
  }
};

int main() {
  Solution solution;

  auto candidates = vector<int>{10, 1, 2, 7, 6, 1, 5};
  cout << "Result: " << endl
       << solution.combinationSum2(candidates, 8) << endl;

  candidates = vector<int>{2, 5, 2, 1, 2};
  cout << "Result: " << endl
       << solution.combinationSum2(candidates, 5) << endl;

  return 0;
}

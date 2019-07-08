/*
  Given n pairs of parentheses, write a function to generate all combinations of
  well-formed parentheses.

  For example, given n = 3, a solution set is:

  [
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
  ]
*/

#include "../util/common.hpp"

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    auto result = vector<string>();
    solve(result, "", n, n);

    return result;
  }

private:
  void solve(vector<string> &solutions, string current,
             unsigned int left_count, unsigned int right_count) {
    if (left_count == 0 && right_count == 0) {
      solutions.push_back(current);
      return;
    }
    if (left_count > 0) {
      solve(solutions, current + "(", left_count - 1, right_count);
    }
    if (right_count > left_count) {
      solve(solutions, current + ")", left_count, right_count - 1);
    }
  }
};

int main() {
  Solution solution;

  cout << solution.generateParenthesis(3) << endl;
  return 0;
}

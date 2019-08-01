/*
  Given a string containing just the characters '(' and ')', find the length of
  the longest valid (well-formed) parentheses substring.

  Example 1:

  Input: "(()"
  Output: 2
  Explanation: The longest valid parentheses substring is "()"

  Example 2:

  Input: ")()())"
  Output: 4
  Explanation: The longest valid parentheses substring is "()()"

*/

#include "../util/common.hpp"

class Solution {
public:
  int longestValidParentheses(string s) {
    auto indices = stack<int>();
    indices.push(-1);
    auto max_length = 0;
    for (auto i = 0; i < s.length(); i++) {
      auto ch = s[i];
      if (s[i] == '(') {
        indices.push(i);
      } else {
        indices.pop();
        if (indices.empty()) {
          indices.push(i);
        } else {
          max_length = max(max_length, i - indices.top());
        }
      }
    }
    return max_length;
  }
};

int main() {
  Solution solution;

  assert(solution.longestValidParentheses("(()") == 2);
  assert(solution.longestValidParentheses(")()())") == 4);
  assert(solution.longestValidParentheses("()(()") == 2);
  assert(solution.longestValidParentheses("(())())(()") == 6);

  return 0; 
}

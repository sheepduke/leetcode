/*
Given a string containing only three types of characters: '(', ')' and '*',
write a function to check whether this string is valid. We define the validity
of a string by these rules:

- Any left parenthesis '(' must have a corresponding right parenthesis ')'.
- Any right parenthesis ')' must have a corresponding left parenthesis '('.
- Left parenthesis '(' must go before the corresponding right parenthesis ')'.
- '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
- An empty string is also valid.

Example 1:
Input: "()"
Output: True

Example 2:
Input: "(*)"
Output: True

Example 3:
Input: "(*))"
Output: True

Note:
The string size will be in the range [1, 100].
 */

#include "../util/common.hpp"

// TE
class Solution {
public:
  bool checkValidString(string s) {
    return solve(s, 0, 0);
  }
  
public:
  bool solve(const string &s, size_t start, size_t left_count) {
    for (auto i = start; i < s.size(); i++) {
      auto ch = s[i];
      if (ch == '(') {
        left_count++;
      }
      else if (ch == ')') {
        if (left_count == 0) return false;
        else left_count--;
      }
      else if (ch == '*') {
        return solve(s, start + 1, left_count)
          || solve(s, start + 1, left_count + 1)
          || (left_count > 0 && solve(s, start + 1, left_count - 1));
      }
    }
    return (left_count == 0);
  }
};

int main() {
  Solution solution;

  assert(solution.checkValidString("()"));
  assert(!solution.checkValidString(")("));
  assert(solution.checkValidString("(*)"));
  assert(solution.checkValidString("(**)"));
  assert(solution.checkValidString("((*)"));
  assert(solution.checkValidString("(*))"));
  assert(solution.checkValidString("(**))"));
  assert(!solution.checkValidString("((*)(*))((*"));

  return 0;
}

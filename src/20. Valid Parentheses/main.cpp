/**
   Given a string containing just the characters '(', ')', '{', '}', '[' and
   ']', determine if the input string is valid.

   An input string is valid if:

   Open brackets must be closed by the same type of brackets.
   Open brackets must be closed in the correct order.

   Note that an empty string is also considered valid.

   Example 1:

   Input: "()"
   Output: true

   Example 2:

   Input: "()[]{}"
   Output: true

   Example 3:

   Input: "(]"
   Output: false

   Example 4:

   Input: "([)]"
   Output: false

   Example 5:

   Input: "{[]}"
   Output: true
*/

#include "../util/common.hpp"

class Solution {
public:
  bool isValid(string s) {
    stack<char> parens;
    for (auto ch: s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        parens.push(ch);
      } else {
        if (!parens.empty() && is_pair(parens.top(), ch)) {
          parens.pop();
        } else {
          return false;
        }
      }
    }
    return parens.empty();
  }

private:
  bool is_pair(char left, char right) {
    return (left == '(' && right == ')')
      || (left == '[' && right == ']')
      || (left == '{' && right == '}');
  }
};

int main() {
  Solution solution;
  

  return 0;
}

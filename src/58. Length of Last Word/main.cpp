/*
Given a string s consists of upper/lower-case alphabets and empty space
characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
 */

#include "../util/common.hpp"

class Solution {
public:
  int lengthOfLastWord(string s) {
    size_t length = 0;
    for (auto ch = rbegin(s); ch != rend(s); ch++) {
      if (*ch == ' ') {
        if (length > 0) {
          return length;          
        }
      }
      else {
        length++;
      }
    }
    return length;
  }
};

int main() {
  Solution solution;

  assert(solution.lengthOfLastWord("Hello World") == 5);

  return 0;
}

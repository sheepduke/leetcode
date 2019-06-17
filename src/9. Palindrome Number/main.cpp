/**
Determine whether an integer is a palindrome. An integer is a palindrome when
it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include "../util/common.hpp"

class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    auto input = to_string(x);
    for (int right = input.length() / 2,
           left = (input.length() % 2 == 0 ? right - 1 : right);
         left >= 0;
         left--, right++) {
      if (input[left] != input[right]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solution;
  assert(solution.isPalindrome(121));
  assert(!solution.isPalindrome(-121));
}

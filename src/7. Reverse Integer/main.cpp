/**
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note: Assume we are dealing with an environment which could only store
integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For the
purpose of this problem, assume that your function returns 0 when the reversed
integer overflows.
*/

#include "../util/common.hpp"

class Solution {
public:
  int reverse(int x) {
    int result = 0;
    while (x != 0) {
      int digit = x % 10;
      if (result > INT_MAX / 10
          || (result == INT_MAX / 10 && digit > INT_MAX % 10)
          || result < INT_MIN / 10
          || (result == INT_MIN / 10 && digit < INT_MIN % 10)) {
        return 0;
      }
      result = result * 10 + digit;
      x /= 10;
    }
    return result;
  }
};

int main() {
  Solution solution;
  assert(solution.reverse(INT_MAX) == 0);
  assert(solution.reverse(123) == 321);
  assert(solution.reverse(-123) == -321);
  assert(solution.reverse(-1463847412) == -2147483641);
  
  return 0;
}


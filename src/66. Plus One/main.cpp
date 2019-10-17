/*
Given a non-empty array of digits representing a non-negative integer, plus one
to the integer.

The digits are stored such that the most significant digit is at the head of
the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number
0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    if (digits.empty()) return vector<int>{1};

    auto it = rbegin(digits);
    auto carry = (*it + 1) / 10;
    *it = (*it + 1) % 10;
    it++;

    for (; carry > 0 && it != rend(digits); it++) {
      auto sum = (*it + carry);
      *it = sum % 10;
      carry = sum / 10;
    }

    if (carry > 0) digits.insert(begin(digits), carry);

    return digits;
  }
};

void run(vector<int> &digits, vector<int> expected) {
  cout << "Input: " << digits << endl;
  auto result = Solution().plusOne(digits);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  auto digits = vector<int>{1, 2, 3};
  auto expected = vector<int>{1, 2, 4};
  run(digits, expected);

  digits = {1, 9, 9};
  expected = {2, 0, 0};
  run(digits, expected);

  digits = {0};
  expected = {1};
  run(digits, expected);

  digits = {9};
  expected = {1, 0};
  run(digits, expected);

  return 0;
}

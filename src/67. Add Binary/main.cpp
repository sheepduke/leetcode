/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 */

#include "../util/common.hpp"

class Solution {
public:
  string addBinary(string a, string b) {
    auto result = vector<char>();
    auto carry = 0;
    for (auto it1 = rbegin(a), it2 = rbegin(b);
         it1 != rend(a) || it2 != rend(b);) {
      auto value1 = (it1 != rend(a) ? *it1 - '0' : 0);
      auto value2 = (it2 != rend(b) ? *it2 - '0' : 0);
      auto sum = value1 + value2 + carry;
      result.push_back('0' + sum % 2);
      carry = sum / 2;
      if (it1 != rend(a)) it1++;
      if (it2 != rend(b)) it2++;
    }
    if (carry > 0) {
      result.push_back('0' + carry);
    }
    cout << result << endl;
    return string(rbegin(result), rend(result));
  }
};

void run(string a, string b, string expected) {
  cout << "Input: " << a << " + " << b << endl;
  auto result = Solution().addBinary(a, b);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  run("1", "11", "100");

  return 0;
}

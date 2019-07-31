/*
  Implement strStr().

  Return the index of the first occurrence of needle in haystack, or -1 if
  needle is not part of haystack.

  Example 1:

  Input: haystack = "hello", needle = "ll"
  Output: 2

  Example 2:

  Input: haystack = "aaaaa", needle = "bba"
  Output: -1
*/

#include "../util/common.hpp"

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.length() > haystack.length()) {
      return -1;
    }

    for (auto i = 0u; i <= haystack.length() - needle.length(); i++) {
      if (haystack.substr(i, needle.length()) == needle) {
        return i;
      }
    }

    return -1;
  }
};


int main() {

  Solution solution;

  assert(solution.strStr("hello", "ll") == 2);
  assert(solution.strStr("asdf", "") == 0);
  assert(solution.strStr("aaaaa", "bba") == -1);
  assert(solution.strStr("", "a") == -1);

  return 0;
}

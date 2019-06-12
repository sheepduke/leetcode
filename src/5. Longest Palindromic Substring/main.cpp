/**
Given a string s, find the longest palindromic substring in s. You may assume
that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

*/

#include "../util/common.hpp"

class Solution {
public:
  string longestPalindrome(string s) {
    if (s.length() == 0 || s.length() == 1) {
      return s;
    }

    string result;
    for (int left = 0, right = 1; right < s.length(); left++, right++) {
      auto odd_length = longest_palindrome(s, left, left);
      auto even_length = 0x0;
      if (left + 1 < s.length()) {
        even_length = longest_palindrome(s, left, left + 1);
      }
      if (odd_length > result.length()) {
        result = s.substr(left - odd_length / 2, odd_length);
      }
      if (even_length > result.length()) {
        result = s.substr(left - even_length / 2 + 1, even_length);
      }
    }

    return result;
  }

private:
  // Find out the length of longest palindrome for a single run.
  unsigned int longest_palindrome(const string &s, int left, int right) {
    for (; left >= 0 && right < s.length(); left--, right++) {
      if (s[left] != s[right]) {
        break;
      }
    }
    return right - left - 1;
  }
};

int main() {

  Solution solution;

  assert(solution.longestPalindrome("aa") == "aa");
  assert(solution.longestPalindrome("bbb") == "bbb");
  assert(solution.longestPalindrome("cbbd") == "bb");
  assert(solution.longestPalindrome("abcbed") == "bcb");

  return 0;
}

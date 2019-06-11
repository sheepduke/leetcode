/**
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3

Explanation: The answer is "wke", with the length of 3.  Note that the answer
             must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    
    auto max_length = 1;
    for (int left = 0, right = 1; right < s.length(); right++) {
      char current = s[right];
      for (auto index = right - 1; index >= left; index--) {
        if (current == s[index]) {
          left = index + 1;
        }
      }
      max_length = max(max_length, right - left + 1);
    }
    return max_length;
  }
};

int main() {
  Solution solution;
  assert(solution.lengthOfLongestSubstring("abcabcbb") == 3);
  assert(solution.lengthOfLongestSubstring("bbbbb") == 1);
  assert(solution.lengthOfLongestSubstring("pwwkew") == 3);
  assert(solution.lengthOfLongestSubstring("abc") == 3);
  
  return 0;
}

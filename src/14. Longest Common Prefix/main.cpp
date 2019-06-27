/*
  Write a function to find the longest common prefix string amongst an array of
  strings.

  If there is no common prefix, return an empty string "".

  Example 1:

  Input: ["flower","flow","flight"]
  Output: "fl"

  Example 2:

  Input: ["dog","racecar","car"]
  Output: ""
  Explanation: There is no common prefix among the input strings.

  Note:

  All given inputs are in lowercase letters a-z.
*/

#include "../util/common.hpp"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }

    sort(begin(strs), end(strs), [](auto a, auto b) {
                                   return a.length() < b.length();
                                 });

    auto index = 0u;
    for (; index < strs[0].length(); index++) {
      auto ch = strs[0][index];
      if (any_of(strs.begin() + 1, strs.end(),
                 [index, ch](auto x) {
                   return index >= x.length() || x[index] != ch;
                 })) {
        break;
      }
    }
    return strs[0].substr(0, index);
  }
};

int main() {
  Solution solution;

  auto input = vector<string>{"flower", "flow", "flight"};
  assert(solution.longestCommonPrefix(input) == "fl");

  input = vector<string>{"dog", "racecarf", "car"};
  assert(solution.longestCommonPrefix(input) == "");
}

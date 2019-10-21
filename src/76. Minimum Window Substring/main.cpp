/*
Given a string S and a string T, find the minimum window in S which will
contain all the characters in T in complexity O(n).

Example:

Input: S = "ADOBECODEBANC", T = "ABC"
Output: "BANC"
Note:

If there is no such window in S that covers all characters in T, return the empty string "".
If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */

#include "../util/common.hpp"

class Solution {
public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
      return "";
    }

    auto targets = map<char, int>();
    for (auto ch: t) {
      targets[ch]++;
    }
    auto remaining = targets;
    auto chars = map<char, int>();

    auto min_left = -1;
    auto min_length = INT_MAX;

    for (int left = 0, right = 0; right < int(s.length()); right++) {
      auto current = s[right];
      chars[current]++;
      if (remaining.find(current) != end(remaining) && remaining[current] > 0) {
        remaining[current]--;
        if (remaining[current] <= 0) {
          remaining.erase(current);
        }
      }
      while (left < right &&
             (targets.find(s[left]) == end(targets)
              || chars[s[left]] > targets[s[left]])) {
        chars[s[left]]--;
        left++;
      }
      if (remaining.empty() && min_length > right - left + 1) {
        min_left = left;
        min_length = right - left + 1;
      }
    }

    return !remaining.empty() ? "" : s.substr(min_left, min_length);
  }
};

void run(string s, string t, string expected) {
  cout << "Input: " << s << " " << t << endl;
  auto result = Solution().minWindow(s, t);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  run("abcde", "fg", "");
  run("ADOBECODEBANC", "ABC", "BANC");
  run("ABABC", "CB", "BC");
  run("a", "a", "a");
  run("ab", "a", "a");
  run("ab", "b", "b");
  run("abc", "b", "b");
  run("aa", "aa", "aa");
  run("cabwefgewcwaefgcf", "cae", "cwae");

  return 0;
}

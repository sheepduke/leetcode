/*
  Given an input string (s) and a pattern (p), implement regular expression
  matching with support for '.' and '*'.

  '.' Matches any single character.
  '*' Matches zero or more of the preceding element.

  The matching should cover the entire input string (not partial).

  Note:

  s could be empty and contains only lowercase letters a-z.
  p could be empty and contains only lowercase letters a-z, and characters like . or *.

  Example 1:

  Input:
  s = "aa"
  p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".

  Example 2:

  Input:
  s = "aa"
  p = "a*"
  Output: true
  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore,
  by repeating 'a' once, it becomes "aa".

  Example 3:

  Input:
  s = "ab"
  p = ".*"
  Output: true
  Explanation: ".*" means "zero or more (*) of any character (.)".

  Example 4:

  Input:
  s = "aab"
  p = "c*a*b"
  Output: true
  Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore,
  it matches "aab".

  Example 5:

  Input:
  s = "mississippi"
  p = "mis*is*p*."
  Output: false

*/

#include "../util/common.hpp"

class Solution {
public:
  bool isMatch(string s, string p) {
    solutions.clear();
    solve(s, p, 0, 0);
    return solutions[make_pair(0, 0)];
  }

private:
  void solve(string s, string p, size_t s_start, size_t p_start) {
    auto key = make_pair(s_start, p_start);
    if (solutions.find(key) != end(solutions)) {
      return ;
    }

    if (s_start >= s.length() && p_start >= p.length()) {
      solutions[key] = true;
    } else if (p_start == p.length()) {
      solutions[key] = false;
    } else if (s_start == s.length()) {
      if (p_start + 1 < p.length() && p[p_start + 1] == '*') {
        solve(s, p, s_start, p_start + 2);
        solutions[key] = solutions[make_pair(s_start, p_start + 2)];
      } else {
        solutions[key] = false;
      }
    } else {
      auto can_match = p[p_start] == '.' || p[p_start] == s[s_start];
      auto can_match_any_count = (p_start + 1 < p.length())
        ? p[p_start + 1] == '*'
        : false;

      if (can_match && can_match_any_count) {
        solve(s, p, s_start + 1, p_start);
        solve(s, p, s_start + 1, p_start + 2);
        solve(s, p, s_start, p_start + 2);
        solutions[key] = solutions[make_pair(s_start + 1, p_start)]
          || solutions[make_pair(s_start + 1, p_start + 2)]
          || solutions[make_pair(s_start, p_start + 2)];
      } else if (can_match && !can_match_any_count) {
        solve(s, p, s_start + 1, p_start + 1);
        solutions[key] = solutions[make_pair(s_start + 1, p_start + 1)];
      } else if (!can_match && can_match_any_count) {
        solve(s, p, s_start, p_start + 2);
        solutions[key] = solutions[make_pair(s_start, p_start + 2)];
      } else {
        solutions[key] = false;
      }
    }
  }

  map<pair<size_t, size_t>, size_t> solutions;
};

int main() {

  Solution solution;

  assert(!solution.isMatch("aa", "a"));
  assert(solution.isMatch("aa", "a*"));
  assert(solution.isMatch("ab", ".*"));
  assert(!solution.isMatch("mississippi", "mis*is*p*."));
  assert(solution.isMatch("bbbba", ".*a*a"));
  assert(solution.isMatch("a", "a*a"));
  assert(!solution.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c"));
  assert(solution.isMatch("", "c*c*"));
  assert(!solution.isMatch("", "..*"));

  return 0;
}

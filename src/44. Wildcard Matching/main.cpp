/*
  Given an input string (s) and a pattern (p), implement wildcard pattern
  matching with support for '?' and '*'.

  '?' Matches any single character.
  '*' Matches any sequence of characters (including the empty sequence).

  The matching should cover the entire input string (not partial).

  Note:

  s could be empty and contains only lowercase letters a-z.
  p could be empty and contains only lowercase letters a-z, and characters like ? or *.

  Example 1:

  Input:
  s = "aa"
  p = "a"
  Output: false
  Explanation: "a" does not match the entire string "aa".

  Example 2:

  Input:
  s = "aa"
  p = "*"
  Output: true
  Explanation: '*' matches any sequence.

  Example 3:

  Input:
  s = "cb"
  p = "?a"
  Output: false
  Explanation: '?' matches 'c', but the second letter is 'a', which does not
  match 'b'.

  Example 4:

  Input:
  s = "adceb"
  p = "*a*b"
  Output: true
  Explanation: The first '*' matches the empty sequence, while the second '*'
  matches the substring "dce".

  Example 5:

  Input:
  s = "acdcb"
  p = "a*c?b"
  Output: false


 */

#include "../util/common.hpp"

class Solution {
public:
  bool isMatch(string s, string p) {
    auto solutions = map<pair<int, int>, bool>();
    solve(s, p, 0, 0, solutions);
    return solutions[make_pair(0, 0)];
  }

private:
  void solve(string s, string p, int s_start, int p_start,
             map<pair<int, int>, bool> &solutions) {
    // If this combination is already solved, simply return it.
    auto pair = make_pair(s_start, p_start);
    if (solutions.find(pair) != end(solutions)) {
      return ;
    }

    int s_size = s.size();
    int p_size = p.size();

    // If p is empty, the return code depends on the state of s.
    if (p_start >= p_size) {
      solutions[pair] = (s_start >= s_size);
    }
    // If s is empty while p is not, check the content of p.
    else if (s_start >= s_size) {
      for (auto i = p_start; i < p_size; i++) {
        if (p[i] != '*') {
          solutions[pair] = false;
          return ;
        }
        solutions[pair] = true;
      }
    }
    else if (p[p_start] == '?' || s[s_start] == p[p_start]) {
      solve(s, p, s_start + 1, p_start + 1, solutions);
      solutions[pair] = solutions[make_pair(s_start + 1, p_start + 1)];
    }
    else if (p[p_start] == '*') {
      for (int i = s_size; i >= s_start; i--) {
        auto target_pair = make_pair(i, p_start + 1);
        solve(s, p, i, p_start + 1, solutions);
        if (solutions[target_pair]) {
          solutions[pair] = true;
          return ;
        }
      }
      solutions[pair] = false;
    }
    else {
      solutions[pair] = false;
    }
  }
};

int main() {
  Solution solution;

  assert(!solution.isMatch("", "?"));
  assert(solution.isMatch("a", "a*"));
  assert(!solution.isMatch("aa", "a"));
  assert(solution.isMatch("aa", "*"));
  assert(!solution.isMatch("cb", "?a"));
  assert(solution.isMatch("xaecdb", "*a*b"));
  assert(!solution.isMatch("acdcb", "a*c?b"));
  assert(solution.isMatch("adceb", "*a*b"));

  return 0;
}

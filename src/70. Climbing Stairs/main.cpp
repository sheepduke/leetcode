/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you
climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 */

#include "../util/common.hpp"

class Solution {
public:
  int climbStairs(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    auto solutions = vector<int>(size_t(n));
    solutions[n - 1] = 1;
    solutions[n - 2] = 2;
    for (auto i = int(n - 3); i >= 0; i--) {
      solutions[i] = solutions[i + 1] + solutions[i + 2];
    }
    return solutions[0];
  }
};

void run(int n, int expected) {
  Solution().climbStairs
  assert()
}

int main() {
  Solution solution;

  return 0;
}

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

How many possible unique paths are there?

Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3

Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right

Example 2:

Input: m = 7, n = 3
Output: 28
 */

#include "../util/common.hpp"

class Solution {
public:
  int uniquePaths(int m, int n) {
    auto solutions = map<pair<int, int>, int>();
    solutions[make_pair(m, n)] = 1;
    solve(solutions, 1, 1, m, n);
    return solutions[make_pair(1, 1)];
  }

private:
  void solve(map<pair<int, int>, int> &solutions, int row, int col, int max_row, int max_col) {
    auto coordinate = make_pair(row, col);
    if (solutions.find(coordinate) != end(solutions)) return;

    if (row < max_row) {
      solve(solutions, row + 1, col, max_row, max_col);
      solutions[coordinate] += solutions[make_pair(row + 1, col)];
    }
    if (col < max_col) {
      solve(solutions, row, col + 1, max_row, max_col);
      solutions[coordinate] += solutions[make_pair(row, col + 1)];
    }
  }
};

void run(int m, int n, int expected) {
  auto result = Solution().uniquePaths(m, n);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  run(3, 2, 3);
  // run(7, 3, 28);

  return 0;
}

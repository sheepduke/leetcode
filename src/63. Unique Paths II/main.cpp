/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in
the diagram below).

The robot can only move either down or right at any point in time. The robot is
trying to reach the bottom-right corner of the grid (marked 'Finish' in the
diagram below).

Now consider if some obstacles are added to the grids. How many unique paths
would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2

Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

#include "../util/common.hpp"

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &board) {
    if (board.front().front() == 1 || board.back().back() == 1) return false;

    auto row_count = board.size();
    auto col_count = board[0].size();
    auto solutions = vector<vector<int>>(
      board.size(), vector<int>(board[0].size(), 0));
    solutions.back().back() = 1;
    solve(solutions, board, 0, 0, row_count - 1, col_count - 1);
    return solutions.front().front();
  }

private:
  void solve(vector<vector<int>> &solutions,
             const vector<vector<int>> &board,
             int row, int col, int max_row, int max_col) {
    if (solutions[row][col] > 0) {
      return;
    }
    if (row < max_row && board[row + 1][col] == 0) {
      solve(solutions, board, row + 1, col, max_row, max_col);
      solutions[row][col] += solutions[row + 1][col];
    }
    if (col < max_col && board[row][col + 1] == 0) {
      solve(solutions, board, row, col + 1, max_row, max_col);
      solutions[row][col] += solutions[row][col + 1];
    }
  }
};

void run(vector<vector<int>> &board, int expected) {
  auto result = Solution().uniquePathsWithObstacles(board);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  auto board = vector<vector<int>>{
    {0, 0, 0},
    {0, 1, 0},
    {0, 0, 0}
  };
  // run(board, 2);

  board = {
    {0},
    {0}
  };
  run(board, 1);

  return 0;
}

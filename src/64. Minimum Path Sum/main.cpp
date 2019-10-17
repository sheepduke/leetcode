/*
Given a m x n grid filled with non-negative numbers, find a path from top left
to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 */

#include "../util/common.hpp"

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    auto max_row = grid.size() - 1;
    auto max_col = grid[0].size() - 1;

    for (int row = max_row; row >= 0; row--) {
      for (int col = max_col; col >= 0; col--) {
        if (row == max_row && col == max_col) {}
        else if (row == max_row) grid[row][col] += grid[row][col + 1];
        else if (col == max_col) grid[row][col] += grid[row + 1][col];
        else grid[row][col] += min(grid[row + 1][col], grid[row][col + 1]);
      }
    }
    return grid[0][0];
  }
};

void run(vector<vector<int>> &grid, int expected) {
  auto result = Solution().minPathSum(grid);
  cout << "Result: " << result;
  assert(result == expected);
}

int main() {
  auto grid = vector<vector<int>>{
    {1, 3, 1},
    {1, 5, 1},
    {4, 2, 1}
  };
  run(grid, 7);

  return 0;
}

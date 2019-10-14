/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example:

Input: 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */

#include "../util/common.hpp"

class Solution {
public:
  int totalNQueens(int n) {
    auto board = vector<vector<bool>>(
      size_t(n), vector<bool>(size_t(n), false));

    int total_count = 0;
    solve(total_count, board, n);
    return total_count;
  }

private:
  void solve(int &total_count, 
             vector<vector<bool>> &board,
             int count) {
    // If there is no count, add to solution accordingly.
    if (count == 0) {
      total_count++;
      return ;
    }
    // Try each position in current row.
    size_t row = board.size() - count;
    for (size_t col = 0; col < board.size(); col++) {
      if (is_valid(board, row, col)) {
        board[row][col] = true;
        solve(total_count, board, count - 1);
        board[row][col] = false;
      }
    }
  }

  bool is_valid(const vector<vector<bool>> &board, size_t row, size_t col) {
    for (size_t i = 0; i < board.size(); i++) {
      if (board[row][i]) {
        return false;
      }
    }
    for (size_t i = 0; i < board.size(); i++) {
      if (board[i][col]) {
        return false;
      }
    }
    for (size_t i = (row < col ? 0 : row - col), j = (col < row ? 0 : col - row);
         i < row && j < col; i++, j++) {
      if (board[i][j]) {
        return false;
      }
    }
    for (int i = row, j = row + col - i;
         i >= 0 && j < int(board.size());
         i--, j++) {
      if (board[i][j]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution solution;

  auto result = solution.totalNQueens(4);
  cout << "Result: " << result;

  return 0;
}

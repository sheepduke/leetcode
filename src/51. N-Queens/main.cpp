/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens'
placement, where 'Q' and '.' both indicate a queen and an empty space
respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    auto solutions = vector<vector<string>>();
    auto board = vector<vector<bool>>(
      size_t(n), vector<bool>(size_t(n), false));
    solve(solutions, board, n);
    return solutions;
  }

private:
  void solve(vector<vector<string>> &solutions,
             vector<vector<bool>> &board,
             int count) {
    // If there is no count, add to solution accordingly.
    if (count == 0) {
      auto solution = vector<string>();
      for (auto row: board) {
        string line(board.size(), '.');
        for (size_t i = 0; i < board.size(); i++) {
          if (row[i]) {
            line[i] = 'Q';
          }
        }
        solution.push_back(line);
      }
      solutions.push_back(solution);
      return ;
    }
    // Try each position in current row.
    size_t row = board.size() - count;
    for (size_t col = 0; col < board.size(); col++) {
      if (is_valid(board, row, col)) {
        board[row][col] = true;
        solve(solutions, board, count - 1);
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

  auto result = solution.solveNQueens(4);
  for (int i = 0; i < result.size(); i++) {
    cout << "Solution " << i + 1 << endl;
    for (auto line: result[i]) {
      cout << line << endl;
    }
    cout << endl;
  }

  return 0;
}

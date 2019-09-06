/*
  Write a program to solve a Sudoku puzzle by filling the empty cells.

  A sudoku solution must satisfy all of the following rules:

  Each of the digits 1-9 must occur exactly once in each row.
  Each of the digits 1-9 must occur exactly once in each column.
  Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

  Empty cells are indicated by the character '.'.


  A sudoku puzzle...


  ...and its solution numbers marked in red.

  Note:

  The given board contain only digits 1-9 and the character '.'.
  You may assume that the given Sudoku puzzle will have a single unique solution.
  The given board size is always 9x9.

*/

#include "../util/common.hpp"

class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    solve(board, 0, 0);
  }

private:
  bool solve(vector<vector<char>> &board, unsigned int start_row,
             unsigned int start_col) {
    auto optional_empty_cell = find_next_empty_cell(board, start_row, start_col);
    if (!optional_empty_cell) {
      // Solved!
      return true;
    }

    auto [row, col] = optional_empty_cell.value();

    for (auto candidate = '1'; candidate <= '9'; candidate++) {
      if (is_valid(board, row, col, candidate)) {
        board[row][col] = candidate;
        if (solve(board, row, col)) {
          return true;
        }
        board[row][col] = '.';
      }
    }
    return false;
  }

  /**
   * Find the next empty cell that should be solved. If nothing is found,
   * return empty.
   */
  optional<pair<unsigned int, unsigned int>> find_next_empty_cell(
    const vector<vector<char>> &board,
    unsigned int start_row,
    unsigned int start_col) {

    // Find the possible empty cell of the same line.
    for (auto col = start_col; col < 9; col++) {
      if (board[start_row][col] == '.') {
        return make_pair(start_row, col);
      }
    }

    // Find the possible empty cell of next lines.
    for (auto row = start_row + 1; row < 9; row++) {
      for (auto col = 0; col < 9; col++) {
        if (board[row][col] == '.') {
          return make_pair(row, col);
        }
      }
    }
    return nullopt;
  }

  /**
   * Return candidates of given point.
   */
  bool is_valid(const vector<vector<char>> &board,
                unsigned int row, unsigned int col, char target) {
    // Check for row and column.
    for (auto i = 0u; i < 9; i++) {
      if ((board[row][i] != '.' && board[row][i] == target)
          || (board[i][col] != '.' && board[i][col] == target)) {
        return false;
      }
    }

    // Check for corresponding 3x3 block.
    auto block_start_row = row / 3 * 3;
    auto block_start_col = col / 3 * 3;
    for (auto i = block_start_row; i < block_start_row + 3; i++) {
      for (auto j = block_start_col; j < block_start_col + 3; j++) {
        if (board[i][j] != '.' && board[i][j] == target) {
          return false;
        }
      }
    }

    return true;
  }
};

void solve(vector<vector<char>> board) {
  Solution solution;

  cout << "Board:" << endl
       << board << endl;

  solution.solveSudoku(board);

  cout << "Result: " << endl
       << board << endl;
}

int main() {

  auto board = vector<vector<char>>{
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };
  
  solve(board);

  return 0;
}

/*

Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

Note:

    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    The given board contain only digits 1-9 and the character '.'.
    The given board size is always 9x9.

*/

#include "../util/common.hpp"

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    auto block = vector<char>();


    for (auto row = 0; row < 9; row++) {
      block.clear();
      for (auto col = 0; col < 9; col++) {
        block.push_back(board[row][col]);
      }
      if (!is_block_valid(block)) {
        return false;
      }
    }
    for (auto col = 0; col < 9; col++) {
      block.clear();
      for (auto row = 0; row < 9; row++) {
        block.push_back(board[row][col]);
      }
      if (!is_block_valid(block)) {
        return false;
      }
    }
    for (auto row = 0; row < 9; row += 3) {
      for (auto col = 0; col < 9; col += 3) {
        block = vector<char>{
          board[row][col], board[row][col + 1], board[row][col + 2],
          board[row + 1][col], board[row + 1][col + 1], board[row + 1][col + 2],
          board[row + 2][col], board[row + 2][col + 1], board[row + 2][col + 2]
        };
        if (!is_block_valid(block)) {
          return false;
        }
      }
    }
    return true;
  }

  // Given a vector of elements, return a boolean value indicating if it is
  // valid.
  bool is_block_valid(const vector<char> &block) {
    auto filled = set<char>();
    for (auto ch : block) {
      if (ch != '.' && filled.find(ch) != end(filled)) {
        return false;
      }
      filled.insert(ch);
    }
    return true;
  }
};

int main() {
  Solution solution;

  auto board = vector<vector<char>>{
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
  };

  assert(solution.isValidSudoku(board));

  board = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
  };

  assert(!solution.isValidSudoku(board));
  
  return 0;
}

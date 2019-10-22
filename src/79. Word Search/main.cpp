/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where
"adjacent" cells are those horizontally or vertically neighboring. The same
letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 */

#include "../util/common.hpp"

class Solution {
public:
  bool exist(vector<vector<char>>& board, string word) {
    for (auto row = 0; row < int(board.size()); row++) {
      for (auto col = 0; col < int(board[0].size()); col++) {
        auto path = set<pair<int, int>>();
        if (board[row][col] == word.front()
            && exist_(board, word, path, row, col, 0)) {
          return true;
        }
      }
    }
    return false;
  }

private:
  bool exist_(vector<vector<char>> &board, const string &word,
              set<pair<int, int>> &path,
              int row, int col, size_t start_index) {
    if (start_index == word.length()) {
      return true;
    }

    auto coordinate = make_pair(row, col);
    if (row < 0 || row >= int(board.size())
        || col < 0 || col >= int(board[0].size())
        || board[row][col] != word[start_index]
        || path.find(coordinate) != end(path)) {
      return false;
    }

    path.insert(coordinate);
    auto result = exist_(board, word, path, row - 1, col, start_index + 1)
      || exist_(board, word, path, row + 1, col, start_index + 1)
      || exist_(board, word, path, row, col - 1, start_index + 1)
      || exist_(board, word, path, row, col + 1, start_index + 1);
    path.erase(coordinate);

    return result;
  }
};

void run(vector<vector<char>> &board, string word, bool expected) {
  cout << "Find: " << word << endl << board << endl;
  auto result = Solution().exist(board, word);
  assert(result == expected);
}

int main() {
  auto board = vector<vector<char>>{
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}
  };

  run(board, "ABCCED", true);
  run(board, "SEE", true);
  run(board, "ABCB", false);
  run(board, "ABCESEECFDAS", true);
  return 0;
}

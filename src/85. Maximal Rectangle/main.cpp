/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 */

#include "../util/common.hpp"

class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return 0;
    }
    auto max_area = 0u;
    for (auto row = 0u; row < matrix.size(); row++) {
      for (auto col = 0u; col < matrix[0].size(); col++) {
        max_area = max(max_area, max_area_begin_at(matrix, row, col));
      }
    }
    return max_area;
  }

private:
  unsigned int max_area_begin_at(const vector<vector<char>> &matrix,
                                 size_t begin_row, size_t begin_col) {
    auto row_zero_count = vector<unsigned int>();
    for (auto row = begin_row; row < matrix.size(); row++) {
      auto count = 0u;
      for (auto col = begin_col; col < matrix[0].size(); col++) {
        if (matrix[row][col] == '1') {
          count++;
        }
        else break;
      }
      row_zero_count.push_back(count);
    }
    auto max_area = 0u;
    for (auto row = 0u; row < row_zero_count.size(); row++) {
      auto width = *min_element(begin(row_zero_count),
                                begin(row_zero_count) + row + 1);
      auto height = row + 1;
      max_area = max(max_area, height * width);
    }
    return max_area;
  }
};

void run(vector<vector<char>> &matrix, int expected) {
  cout << "Input: " << endl << matrix << endl;
  auto result = Solution().maximalRectangle(matrix);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  auto matrix = vector<vector<char>>{
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}
  };
  run(matrix, 6);

  matrix = {};
  run(matrix, 0);

  matrix = {{}};
  run(matrix, 0);

  matrix = {{'1'}};
  run(matrix, 1);

  matrix = {{'1', '1', '1'}};
  run(matrix, 3);

  matrix = {{'1'}, {'1'}};
  run(matrix, 2);

  return 0;
}

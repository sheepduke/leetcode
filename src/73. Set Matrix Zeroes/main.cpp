/*
Given a m x n matrix, if an element is 0, set its entire row and column to
0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */

#include "../util/common.hpp"

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    if (matrix.empty())
      return ;

    // Check if the first row/column contains 0.
    bool is_first_row_zero =
      find(begin(matrix[0]), end(matrix[0]), 0) != end(matrix[0]);
    bool is_first_col_zero = false;
    for (auto row = 0u; row < matrix.size(); row++) {
      if (matrix[row][0] == 0)
        is_first_col_zero = true;
    }

    // If there is a zero anywhere in the matrix, set the first row/column to 0.
    for (auto row = 0u; row < matrix.size(); row++) {
      for (auto col = 0u; col < matrix[0].size(); col++) {
        if (matrix[row][col] == 0) {
          matrix[0][col] = 0;
          matrix[row][0] = 0;
        }
      }
    }

    // For each row/column, set zero if needed.
    for (auto row = 1u; row < matrix.size(); row++) {
      if (matrix[row][0] == 0) {
        for (auto col = 0u; col < matrix[0].size(); col++)
          matrix[row][col] = 0;
      }
    }
    for (auto col = 1u; col < matrix[0].size(); col++) {
      if (matrix[0][col] == 0) {
        for (auto row = 0u; row < matrix.size(); row++)
          matrix[row][col] = 0;
      }
    }

    // Handle the cases that first row/column contains zero originally.
    if (is_first_col_zero) {
      for (auto row = 0u; row < matrix.size(); row++) {
        matrix[row][0] = 0;
      }
    }
    if (is_first_row_zero) {
      for (auto col = 0u; col < matrix[0].size(); col++) {
        matrix[0][col] = 0;
      }
    }
  }
};

void run(vector<vector<int>> &matrix) {
  cout << "Input: " << endl << matrix << endl;
  Solution().setZeroes(matrix);
  cout << "Result: " << endl << matrix << endl;
}

int main() {
  auto matrix = vector<vector<int>>{
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 1}
  };
  run(matrix);

  matrix = {
    {0, 1, 3, 4},
    {3, 4, 5, 0},
    {2, 1, 3, 4}
  };
  run(matrix);

  matrix = {
    {1, 2, 3, 4},
    {2, 3, 0, 1},
    {0, 2, 1, 1}
  };
  run(matrix);

  matrix = {
    {1}, {0}, {3}
  };
  run(matrix);

  return 0;
}

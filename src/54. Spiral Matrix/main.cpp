/*
Given a matrix of m x n elements (m rows, n columns), return all elements of
the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 */

#include "../util/common.hpp"

class Solution {
public:
  enum class Direction {
    UP, DOWN, LEFT, RIGHT
  };

  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    auto result = vector<int>();
    if (matrix.empty() || matrix[0].empty()) {
      return result;
    }

    int row_min = 0;
    int row_max = matrix.size() - 1;
    int col_min = 0;
    int col_max = matrix[0].size() - 1;

    auto direction = Direction::RIGHT;

    while (row_min <= row_max && col_min <= col_max) {
      switch (direction) {
      case Direction::RIGHT:
        for (int row = row_min, col = col_min; col <= col_max; col++) {
          result.push_back(matrix[row][col]);
        }
        row_min++;
        direction = Direction::DOWN;
        break;
      case Direction::DOWN:
        for (int row = row_min, col = col_max; row <= row_max; row++) {
          result.push_back(matrix[row][col]);
        }
        col_max--;
        direction = Direction::LEFT;
        break;
      case Direction::LEFT:
        for (int row = row_max, col = col_max; col >= col_min; col--) {
          result.push_back(matrix[row][col]);
        }
        row_max--;
        direction = Direction::UP;
        break;
      case Direction::UP:
        for (int row = row_max, col = col_min; row >= row_min; row--) {
          result.push_back(matrix[row][col]);
        }
        col_min++;
        direction = Direction::RIGHT;
        break;
      }
    }

    return result;
  }
};

int main() {
  Solution solution;

  auto matrix = vector<vector<int>>{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  cout << solution.spiralOrder(matrix) << endl;

  matrix = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9,10,11,12}
  };
  cout << solution.spiralOrder(matrix) << endl;

  matrix = {
    {1, 2},
    {3, 4}
  };
  cout << solution.spiralOrder(matrix) << endl;

  return 0;
}

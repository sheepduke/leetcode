/*
Given a positive integer n, generate a square matrix filled with elements from
1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

#include "../util/common.hpp"

class Solution {
public:
  enum class Direction {
    UP, DOWN, LEFT, RIGHT
  };

  vector<vector<int>> generateMatrix(int n) {
    auto matrix = vector<vector<int>>(size_t(n), vector<int>(size_t(n)));

    auto direction = Direction::RIGHT;
    auto number = int(1);

    auto [row_min, row_max, col_min, col_max] = make_tuple(0, n - 1, 0, n - 1);

    while (row_min <= row_max && col_min <= col_max) {
      if (direction == Direction::RIGHT) {
        for (auto col = col_min; col <= col_max; col++, number++) {
          matrix[row_min][col] = number;
        }
        row_min++;
        direction = Direction::DOWN;
      }
      else if (direction == Direction::DOWN) {
        for (auto row = row_min; row <= row_max; row++, number++) {
          matrix[row][col_max] = number;
        }
        col_max--;
        direction = Direction::LEFT;
      }
      else if (direction == Direction::LEFT) {
        for (auto col = col_max; col >= col_min; col--, number++) {
          matrix[row_max][col] = number;
        }
        row_max--;
        direction = Direction::UP;
      }
      else if (direction == Direction::UP) {
        for (auto row = row_max; row >= row_min; row--, number++) {
          matrix[row][col_min] = number;
        }
        col_min++;
        direction = Direction::RIGHT;
      }
    }

    return matrix;;
  }
};

int main() {
  Solution solution;

  auto max_wanted = 5;
  for (auto i = 0; i <= max_wanted; i++) {
    cout << solution.generateMatrix(i) << endl;
  }

  return 0;
}

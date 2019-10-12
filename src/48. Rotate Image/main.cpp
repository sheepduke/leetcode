/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]


 */

#include "../util/common.hpp"

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    for (size_t row = 0; row < matrix.size() / 2; row++) {
      for (size_t col = row; col < matrix.size() - 1 - row; col++) {
        auto x = row;
        auto y = col;
        auto old_value = matrix[x][y];
        for (auto i = 0; i < 4; i++) {
          auto new_x = y;
          auto new_y = matrix.size() - 1 - x;
          auto new_value = matrix[new_x][new_y];
          matrix[new_x][new_y] = old_value;
          old_value = new_value;
          x = new_x;
          y = new_y;
        }
      }
    }
  }
};

vector<vector<int>> make_nums(size_t size) {
  auto number = 1;
  auto result = vector<vector<int>>(size, vector<int>(size));
  for (size_t row = 0; row < size; row++) {
    for (size_t col = 0; col < size; col++) {
      result[row][col] = number;
      number++;
    }
  }
  return result;
}

void run(vector<vector<int>> &nums) {
  Solution solution;
  cout << "Before: " << endl << nums << endl;
  solution.rotate(nums);
  cout << "After: " << endl << nums << endl;

}

int main() {
  auto nums = make_nums(4);
  run(nums);

  return 0;
}

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
 */

#include "../util/common.hpp"

class Solution {
public:
  bool searchMatrix(const vector<vector<int>> &matrix, int target) {
    if (matrix.empty()
        || matrix[0].empty()
        || matrix.front().front() > target
        || matrix.back().back() < target)
      return false;

    // Find the row where the target might be in.
    auto row = matrix.size() - 1;
    for (auto i = 1u; i < matrix.size(); i++) {
      if (matrix[i][0] > target) {
        row = i -1 ;
        break;
      }
    }

    // Search in the corresponding row using binary search.
    auto left = 0;
    auto right = int(matrix[0].size() - 1);
    while (left <= right) {
      auto mid = (left + right) / 2;
      auto current = matrix[row][mid];
      if (current == target) {
        return true;
      }
      else if (current < target) {
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }

    return false;
  }
};

void run(const vector<vector<int>> &matrix, int target, bool expected) {
  cout << "Find: " << target << " in" << endl << matrix << endl;
  auto result = Solution().searchMatrix(matrix, target);
  assert(result == expected);
}

int main() {
  auto matrix = vector<vector<int>>{
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  run(matrix, 3, true);

  run(matrix, 13, false);

  matrix = {
    {1, 3}
  };
  run(matrix, 3, true);

  matrix = {
    {1}, {3}
  };
  run(matrix, 3, true);

  return 0;
}

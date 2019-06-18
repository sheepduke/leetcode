/**
Given n non-negative integers a1, a2, ..., an , where each represents a point
at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2. 

The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this
case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include "../util/common.hpp"

class Solution {
public:
    int maxArea(vector<int> &height) {
      auto left = begin(height);
      auto right = end(height) - 1;
      int max_area = 0;
      while (left < right) {
        max_area = max(max_area, int(right - left) * min(*left, *right));
        if (*left < *right) {
          left++;
        } else {
          right--;
        }
      }
      return max_area;
    }
};

int main() {
  Solution solution;

  auto input = vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7};
  assert(solution.maxArea(input) == 49);
  return 0;
}

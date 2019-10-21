/*
Given an array with n objects colored red, white or blue, sort them in-place so
that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white,
and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite
array with total number of 0's, then 1's and followed by 2's.

Could you come up with a one-pass algorithm using only constant space?
 */

#include "../util/common.hpp"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    if (nums.size() < 2) {
      return;
    }
    
    auto next_zero = 0;
    auto next_two = int(nums.size() - 1);

    for (auto index = 0; index <= next_two; index++) {
      if (nums[index] == 0) {
        swap(nums[index], nums[next_zero]);
        next_zero++;
      }
      else if (nums[index] == 2) {
        swap(nums[index], nums[next_two]);
        next_two--;
        index--;
      }
    }
  }
};

void run(vector<int> &nums, vector<int> &expected) {
  cout << "Input: " << nums << endl;
  Solution().sortColors(nums);
  cout << "Result: " << nums << endl;
  assert(nums == expected);
}

int main() {
  auto nums = vector<int>{2, 0, 2, 1, 1, 0};
  auto expected = vector<int>{0, 0, 1, 1, 2, 2};
  run(nums, expected);

  nums = {2, 1, 2, 1, 0, 0, 1, 2};
  expected = {0, 0, 1, 1, 1, 2, 2, 2};
  run(nums, expected);

  nums = {2};
  expected = {2};
  run(nums, expected);

  nums = {1, 2};
  expected = {1, 2};
  run(nums, expected);

  nums = {0, 0};
  expected = {0, 0};
  run(nums, expected);

  nums = {2, 2};
  expected = {2, 2};
  run(nums, expected);

  return 0;
}

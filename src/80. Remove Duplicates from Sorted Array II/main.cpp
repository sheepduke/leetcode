/*
Given a sorted array nums, remove the duplicates in-place such that duplicates
appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying
the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums
being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.

Example 2:

Given nums = [0,0,1,1,1,1,2,3,3],

Your function should return length = 7, with the first seven elements of nums
being modified to 0, 0, 1, 1, 2, 3 and 3 respectively.

It doesn't matter what values are set beyond the returned length.

Clarification:

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by reference, which means modification
to the input array will be known to the caller as well.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
 */

#include "../util/common.hpp"

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() <= 2) {
      return nums.size();
    }
    auto buffer = deque<int>{nums.front()};
    auto length = 1;
    auto out_index = 1;
    for (auto index = 1u; index < nums.size(); index++, out_index++) {
      auto num = nums[index];
      if (buffer.size() == 0 || (buffer.size() == 1 && buffer.back() == num)) {
        buffer.push_back(num);
        length++;
        swap(nums[index], nums[out_index]);
      }
      else if (buffer.size() > 0 && buffer.back() != num) {
        buffer.clear();
        buffer.push_back(num);
        length++;
        swap(nums[index], nums[out_index]);
      }
      else {
        out_index--;
      }
    }
    return length;
  }
};

void run(vector<int> &nums, const vector<int> &expected) {
  cout << "Input: " << nums << endl;
  auto length = Solution().removeDuplicates(nums);
  auto output = vector<int>(begin(nums), begin(nums) + length);

  cout << "Result length: " << length << endl
       << "Result array: " << output << endl;
  assert(output == expected);
}

int main() {
  auto nums = vector<int>{1, 1, 1, 2, 2, 3};
  auto output = vector<int>{1, 1, 2, 2, 3};
  run(nums, output);

  nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  output = {0, 0, 1, 1, 2, 3, 3};
  run(nums, output);

  nums = {0};
  output = {0};
  run(nums, output);

  nums = {0, 0};
  output = {0, 0};
  run(nums, output);

  return 0;
}

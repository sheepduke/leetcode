/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one
sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.

You may assume that nums1 has enough space (size that is greater or equal to m
+ n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
 */

#include "../util/common.hpp"

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    auto result_index = m + n - 1;
    auto first_index = (int) m - 1;
    auto second_index = (int) n - 1;
    for (; first_index >= 0 && second_index >= 0; result_index--) {
      if (nums1[first_index] < nums2[second_index]) {
        nums1[result_index] = nums2[second_index];
        second_index--;
      }
      else {
        nums1[result_index] = nums1[first_index];
        first_index--;
      }
    }
    for (; second_index >= 0; second_index--, result_index--) {
      nums1[result_index] = nums2[second_index];
    }
  }
};

int main() {
  Solution solution;

  return 0;
}

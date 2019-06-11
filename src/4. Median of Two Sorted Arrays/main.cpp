/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity
should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0

Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

#include "../util/common.hpp"

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    auto total_size = nums1.size() + nums2.size();
    auto count = 0;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    auto current = 0;
    auto last = 0;
    while (count < total_size / 2 + 1) {
      last = current;
      if (it1 == nums1.end()) {
        current = *it2;
        it2++;
      } else if (it2 == nums2.end()) {
        current = *it1;
        it1++;
      } else if (*it1 < *it2) {
        current = *it1;
        it1++;
      } else {
        current = *it2;
        it2++;
      }
      count++;
    }

    if (total_size % 2 == 0) {
      return ((double) current + last) / 2;
    } else {
      return current;
    }
  }
};

int main() {
  Solution solution;
  vector<int> nums1;
  vector<int> nums2;

  nums1 = {1, 3};
  nums2 = {2};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 2.0);

  nums1 = {1, 2};
  nums2 = {3, 4};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 2.5);

  nums1 = {2};
  nums2 = {};
  assert(solution.findMedianSortedArrays(nums1, nums2) == 2);

  return 0;
}

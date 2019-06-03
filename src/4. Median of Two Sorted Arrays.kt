package p4

import kotlin.test.assertEquals

/**
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

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

class Solution {
    fun findMedianSortedArrays(nums1: IntArray, nums2: IntArray): Double {
        val nums = mutableListOf<Int>()
        nums1.forEach { nums.add(it) }
        nums2.forEach { nums.add(it) }
        nums.sort()
        val half = nums.size / 2
        return if (nums.size % 2 == 0) {
            (nums[half].toDouble() + nums[half - 1].toDouble())  / 2
        } else {
            nums[half].toDouble()
        }
    }
}

fun main() {
    assertEquals(2.0, Solution().findMedianSortedArrays(intArrayOf(1, 3), intArrayOf(2)))
}
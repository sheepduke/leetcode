package p1

import kotlin.test.assertEquals
import kotlin.test.assertTrue

/**
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
 */

class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val numToIndex = nums.mapIndexed { index, value -> value to index }.toMap()
        nums.withIndex().forEach {
            val complementIndex = numToIndex[target - it.value]
            if (complementIndex != null && complementIndex != it.index) {
                return@twoSum intArrayOf(it.index, complementIndex)
            }
        }
        return intArrayOf()
    }
}

fun main() {
    val solution = Solution()
    assertTrue { intArrayOf(0, 1).contentEquals(solution.twoSum(intArrayOf(2, 7, 11, 15), 9)) }
    assertTrue { intArrayOf(1, 2).contentEquals(solution.twoSum(intArrayOf(3, 2, 4), 6)) }
}
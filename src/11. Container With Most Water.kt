package p11

import kotlin.math.abs
import kotlin.math.max
import kotlin.math.min
import kotlin.test.assertEquals

/**
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49

 */

class Solution {
    fun maxArea(heights: IntArray): Int {
        var maxSquare = 0
        for (i in 0 until heights.size) {
            for (j in i until heights.size) {
                val square = abs(min(heights[j], heights[i]) * (j - i))
                maxSquare = max(maxSquare, square)
            }
        }
        return maxSquare
    }
}

fun main() {
    val solution = Solution()

    assertEquals(49, solution.maxArea(intArrayOf(1, 8, 6, 2, 5, 4, 8, 3, 7)))
    assertEquals(20, solution.maxArea(intArrayOf(1, 2, 5, 6, 7, 4, 5)))
    println("Success.")
}
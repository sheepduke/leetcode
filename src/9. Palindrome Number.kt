package p9

import kotlin.test.assertFalse
import kotlin.test.assertTrue

/**
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true

Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 */

class Solution {
    fun isPalindrome(x: Int): Boolean {
        if (x < 0) return false
        if (x < 10) return true
        val string = x.toString()
        var left = (string.length - 1) / 2
        var right = string.length / 2
        while (left >= 0 && right < string.length) {
            if (string[left] != string[right]) return false
            left--
            right++
        }
        return true
    }
}

fun main() {
    val solution = Solution()
    assertTrue { solution.isPalindrome(121) }
    assertFalse { solution.isPalindrome(-121) }
    assertFalse { solution.isPalindrome(10) }
}
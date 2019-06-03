package p7

import kotlin.test.assertEquals

/**
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321

Example 2:

Input: -123
Output: -321

Example 3:

Input: 120
Output: 21

Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 */

class Solution {
    fun reverse(x: Int): Int {
        var num = x
        var result = 0
        while (num != 0) {
            val digit = num % 10
            if (result > Int.MAX_VALUE / 10 || result < Int.MIN_VALUE / 10 ||
                    (result == Int.MAX_VALUE / 10 && digit > Int.MAX_VALUE % 10) ||
                    (result == Int.MIN_VALUE / 10 && -digit < Int.MIN_VALUE % 10)) {
                return 0
            }
            result = result * 10 + digit
            num /= 10
        }
        return result
    }
}

fun main() {
    assertEquals(321, Solution().reverse(123))
    assertEquals(-123, Solution().reverse(-321))
    assertEquals(21, Solution().reverse(120))
    assertEquals(-1463847412, Solution().reverse(-2147483641))
    assertEquals(0, Solution().reverse(Int.MIN_VALUE))
    assertEquals(0, Solution().reverse(Int.MAX_VALUE))
}
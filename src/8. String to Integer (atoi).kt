package p8

import kotlin.test.assertEquals

/**
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.

Example 1:

Input: "42"
Output: 42

Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
Then take as many numerical digits as possible, which gets 42.

Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
Thefore INT_MIN (−231) is returned.

 */

class Solution {
    fun myAtoi(str: String): Int {
        var string = str.trimStart()
        if (string.isEmpty()) {
            return 0
        }
        // Check if the number shall be negative.
        var isNegative = false
        when (string.first()) {
            '+' -> string = string.substring(1)
            '-' -> {
                isNegative = true
                string = string.substring(1)
            }
        }
        // Parse the character one by one.
        var result = 0
        for (char in string) {
            if (char !in '0'..'9') {
                break
            }
            val digit = char - '0'
            when {
                result > Int.MAX_VALUE / 10
                        || result == Int.MAX_VALUE / 10 && digit > Int.MAX_VALUE % 10 -> {
                    return Int.MAX_VALUE
                }
                result < Int.MIN_VALUE / 10
                        || result == Int.MIN_VALUE / 10 && digit > -(Int.MIN_VALUE % 10) -> {
                    return Int.MIN_VALUE
                }
                else -> result = result * 10 + digit * (if (isNegative) -1 else 1)
            }
        }
        return result
    }
}

fun main() {
    val solution = Solution()

    assertEquals(42, solution.myAtoi("42"))
    assertEquals(-42, solution.myAtoi("    -42"))
    assertEquals(4193, solution.myAtoi("4193 with words"))
    assertEquals(0, solution.myAtoi("words and 987"))
    assertEquals(-2147483648, solution.myAtoi("-91283472332"))
    assertEquals(2147483647, solution.myAtoi("2147483648"))
    assertEquals(-2147483648, solution.myAtoi("-2147483649"))
}
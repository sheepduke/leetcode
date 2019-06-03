package p5

import kotlin.test.assertEquals

/**
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:

Input: "cbbd"
Output: "bb"

 */

class Solution {
    fun longestPalindrome(s: String): String {
        var result = ""
        s.withIndex().forEach { (index, _) ->
            val palindrome1 = longestPalindromeWithCenter(s, index - 1, index + 1)
            val palindrome2 = longestPalindromeWithCenter(s, index, index + 1)
            if (palindrome1.length > result.length) result = palindrome1
            if (palindrome2.length > result.length) result = palindrome2
        }
        return result
    }

    /**
     * Return the palidrome of string [s]. The start point is specified by [leftStart] and [rightStart].
     */
    private fun longestPalindromeWithCenter(s: String, leftStart: Int, rightStart: Int): String {
        var left = leftStart
        var right = rightStart
        while (left >= 0 && right < s.length && s[left] == s[right]) {
            left--
            right++
        }
        return s.substring(left + 1, right)
    }
}

fun main() {
    assertEquals("aba", Solution().longestPalindrome("cabad"))
    assertEquals("bb", Solution().longestPalindrome("cbbd"))
}
package p3

import kotlin.math.max
import kotlin.test.assertEquals

/**
 * Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution {
    fun lengthOfLongestSubstring(s: String): Int {
        if (s.isEmpty()) {
            return 0
        }

        var start  = 0
        // Pointer of current char.
        var end = 0
        var maxLength = 0

        // Constructs a sliding window that moves along with the index of char.
        // For each window, update maxLength accordingly.
        while (end < s.length) {
            val char = s[end]
            val subString = s.substring(start, end)
            if (subString.contains(char)) {
                start += s.substring(start, end).lastIndexOf(char) + 1
            }
            end++
            maxLength = Math.max(maxLength, end - start)
        }

        return maxLength
    }
}

fun main() {
    assertEquals(3, Solution().lengthOfLongestSubstring("abcabcbc"))
    assertEquals(1, Solution().lengthOfLongestSubstring("bbbbb"))
}
package p6

import kotlin.test.assertEquals

/**
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

 */

class Solution {
    fun convert(s: String, numRows: Int): String {
        if (numRows == 1) {
            return s
        }
        val charPositions = mutableMapOf<Pair<Int, Int>, Char>()
        var row = 0
        var col = 0
        val moveUp = { row--; col++ }
        val moveDown = { row++ }
        var moveFun = moveDown
        // Construct the character matrix.
        s.forEach {
            charPositions[Pair(row, col)] = it
            when (row) {
                numRows - 1 -> moveFun = moveUp
                0 -> moveFun = moveDown
            }
            moveFun()
        }
        val result = StringBuilder()
        for (i in 0 until numRows) {
            for (j in 0..col) {
                val char = charPositions[Pair(i, j)]
                if (char != null) {
                    result.append(char)
                }
            }
        }
        return result.toString()
    }
}

fun main() {
    assertEquals("PAHNAPLSIIGYIR", Solution().convert("PAYPALISHIRING", 3))
    assertEquals("PINALSIGYAHRPI", Solution().convert("PAYPALISHIRING", 4))
}
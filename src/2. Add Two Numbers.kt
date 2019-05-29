package p2

import util.ListNode
import kotlin.test.assertEquals

/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 */

class Solution {
    fun addTwoNumbers(list1: ListNode?, list2: ListNode?): ListNode? {
        var l1 = list1
        var l2 = list2
        val head = ListNode(0)
        var node = head

        var carry = 0
        while (l1 != null || l2 != null || carry > 0) {
            val sum = (l1?.`val` ?: 0) + (l2?.`val` ?: 0) + carry
            val digit = sum % 10
            node.next = ListNode(sum % 10)
            node = node.next!!
            carry = sum / 10
            l1 = l1?.next
            l2 = l2?.next
        }

        return head.next
    }
}

private fun makeListNode(vararg vals: Int): ListNode {
    var root = ListNode(vals.first())
    var temp = root
    vals.drop(1).forEach {
        val node = ListNode(it)
        temp.next = node
        temp = node
    }
    return root
}

private fun assertSingle(l1: ListNode, l2: ListNode, expected: ListNode) {
    assertEquals(expected, Solution().addTwoNumbers(l1, l2))
}

fun main() {
    assertSingle(makeListNode(2, 4, 3), makeListNode(5, 6, 4), makeListNode(7, 0, 8))
    assertSingle(makeListNode(9), makeListNode(1, 9, 9), makeListNode(0, 0, 0, 1))
}
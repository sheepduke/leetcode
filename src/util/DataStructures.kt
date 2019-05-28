package util

class ListNode(var `val`: Int) {
    var next: ListNode? = null

    override fun equals(other: Any?): Boolean {
        return isListNodeEqual(this, other as ListNode)
    }

    override fun hashCode(): Int {
        var result = `val`
        result = 31 * result + (next?.hashCode() ?: 0)
        return result
    }

    override fun toString(): String {
        return "$`val` -> ${next.toString()}"
    }
}

fun isListNodeEqual(list1: ListNode?, list2: ListNode?): Boolean {
    var l1 = list1
    var l2 = list2
    while (l1 != null && l2 != null) {
        if (l1.`val` != l2.`val`) {
            return false
        }
        l1 = l1.next
        l2 = l2.next
    }
    return true
}
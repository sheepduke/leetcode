/**
You are given two non-empty linked lists representing two non-negative
integers. The digits are stored in reverse order and each of their nodes
contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the
number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto p = head;
    auto carry = 0;
    while (l1 || l2) {
      auto sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = sum / 10;
      p->next = new ListNode(sum % 10);
      p = p->next;
      l1 = l1 ? l1->next : NULL;
      l2 = l2 ? l2->next : NULL;
    }
    if (carry > 0) {
      p->next = new ListNode(carry);
    }

    return head->next;
  }
};

int main() {
  return 0;
}

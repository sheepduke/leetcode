/**
   Given a linked list, remove the n-th node from the end of list and return
   its head.

   Example:

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes
   1->2->3->5.

   Note:

   Given n will always be valid.
*/

#include "../util/common.hpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      auto count = 0u;
      for (auto p = head; p; p = p->next, count++);

      // Handle special cases.
      if (!head || n <= 0) return head;
      if (count == n) {
        auto result = head->next;
        delete head;
        return result;
      }

      auto previous = head;
      for (auto i = 0; i < count - n - 1; i++, previous = previous->next);

      auto next = previous->next;
      previous->next = previous->next->next;
      delete next;
      next = NULL;
      return head;
    }
};


int main() {
  Solution solution;

  auto head = new ListNode(1);
  auto node = head;
  for (int i = 2; i <= 5; i++) {
    node->next = new ListNode(i);
    node = node->next;
  }

  cout << head << endl;
  solution.removeNthFromEnd(head, 2);
  cout << head << endl;
  return 0;
}

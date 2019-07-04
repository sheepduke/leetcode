/*
  Merge two sorted linked lists and return it as a new list. The new list
  should be made by splicing together the nodes of the first two lists.

  Example:

  Input: 1->2->4, 1->3->4
  Output: 1->1->2->3->4->4
*/

#include "../util/common.hpp"

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto head = ListNode(0);
    auto node = &head;
    while (l1 || l2) {
      if (!l1 || (l2 && l1->val > l2->val)) {
        node->next = l2;
        l2 = l2->next;
      } else {
        node->next = l1;
        l1 = l1->next;
      }
      node = node->next;
    }
    return head.next;
  }
};

int main() {
  Solution solution;

  auto l1 = make_list({1, 2, 4});
  auto l2 = make_list({1, 3, 4});

  auto result = solution.mergeTwoLists(l1, l2);

  cout << "L1: " << l1 << endl
       << "L2: " << l2 << endl
       << "Result: " << result << endl;
  
  return 0;
}

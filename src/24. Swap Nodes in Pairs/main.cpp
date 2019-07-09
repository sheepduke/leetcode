/*
  Given a linked list, swap every two adjacent nodes and return its head.

  You may not modify the values in the list's nodes, only nodes itself may be
  changed.

  Example:

  Given 1->2->3->4, you should return the list as 2->1->4->3.

*/

#include "../util/common.hpp"

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    auto first = head;
    auto second = first->next;
    auto third = second->next;
    second->next = first;
    first->next = swapPairs(third);
    return second;
  }
};

int main() {
  Solution solution;
  cout << solution.swapPairs(make_list({1})) << endl
       << solution.swapPairs(make_list({1, 2, 3})) << endl
       << solution.swapPairs(make_list({1, 2, 3, 4})) << endl;

  return 0;
}

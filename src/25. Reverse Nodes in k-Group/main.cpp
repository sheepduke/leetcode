/*
  Given a linked list, reverse the nodes of a linked list k at a time and
  return its modified list.

  k is a positive integer and is less than or equal to the length of the linked
  list. If the number of nodes is not a multiple of k then left-out nodes in
  the end should remain as it is.

  Example:

  Given this linked list: 1->2->3->4->5

  For k = 2, you should return: 2->1->4->3->5

  For k = 3, you should return: 3->2->1->4->5

  Note:

  - Only constant extra memory is allowed.
  - You may not alter the values in the list's nodes, only nodes itself may be
    changed.
*/

#include "../util/common.hpp"

class Solution {
public:
  ListNode* reverseKGroup(ListNode* head, int k) {
    auto nodes = vector<ListNode *>();
    auto p = head;
    for (auto i = 0; i < k && p; i++) {
      nodes.push_back(p);
      p = p->next;
    }
    
    if (nodes.size() < (unsigned int) k) {
      return head;
    }
    
    for (auto i = nodes.size() - 1; i > 0; i--) {
      nodes[i]->next = nodes[i - 1];
    }
    nodes[0]->next = reverseKGroup(p, k);
    return *(end(nodes) - 1);
  }
};

int main() {

  auto solution = Solution();

  auto input = make_list({1, 2, 3, 4, 5});
  cout << solution.reverseKGroup(input, 2) << endl;

  input = make_list({1, 2, 3, 4, 5});
  cout << solution.reverseKGroup(input, 3) << endl;
  
  return 0;
}

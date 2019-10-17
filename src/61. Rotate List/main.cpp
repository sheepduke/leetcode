/*
Given a linked list, rotate the list to the right by k places, where k is
non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
 */

#include "../util/common.hpp"

class Solution {
public:
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k == 0) return head;

    // Calculate the real shift count.
    auto length = 0u;
    for (auto p = head; p; p = p->next, length++);
    auto shift_count = k % length;

    if (shift_count == 0) return head;
    
    // Calculate the last node of new list.
    auto new_last = head;
    for (auto i = 0; i < length - shift_count - 1; i++) {
      new_last = new_last->next;
    }
    auto new_head = new_last->next;

    // Set corresponding nodes.
    new_last->next = NULL;
    auto new_prev_old_head = new_head;
    for (; new_prev_old_head->next; new_prev_old_head = new_prev_old_head->next);
    new_prev_old_head->next = head;

    return new_head;
  }
};

void run(const vector<int> &nums, int k) {
  cout << Solution().rotateRight(make_list(nums), k) << endl;
}

int main() {
  Solution solution;

  auto nums = vector<int>{1, 2, 3, 4, 5};
  run(nums, 2);

  nums = {0, 1, 2};
  run(nums, 4);

  return 0;
}

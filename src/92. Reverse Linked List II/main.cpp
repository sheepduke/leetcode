/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include "../util/common.hpp"

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || !head->next || m == n) {
      return head;
    }
    
    ListNode *interval_prev = (m == 1 ? NULL : head);
    auto interval_begin = (m == 1 ? head : head->next);
    auto index = (m == 1 ? 1 : 2);
    
    for (; index < m; index++) {
      interval_begin = interval_begin->next;
      interval_prev = interval_prev->next;
    }
    auto prev = interval_begin;
    auto current = interval_begin->next;
    for (index++; index <= n; index++) {
      auto next = current->next;
      current->next = prev;
      prev = current;
      current = next;
    }
    interval_begin->next = current;
    if (interval_prev) {
      interval_prev->next = prev;
    }

    return (m == 1 ? prev : head);
  }
};

void run(const vector<int> &nums, int m, int n) {
  auto head = make_list(nums);
  cout << endl << "Input: " << head << " | " << m << ", " << n << endl;
  auto result = Solution().reverseBetween(head, m, n);
  cout << "Result: " << result << endl;
}

int main() {
  auto nums = vector<int>{1, 2, 3, 4, 5};
  run(nums, 2, 4);
  run(nums, 1, 3);
  run(nums, 3, 5);
  run(nums, 1, 5);

  return 0;
}

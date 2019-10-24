/*
Given a linked list and a value x, partition it such that all nodes less than x
come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two
partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
 */

#include "../util/common.hpp"

class Solution {
public:
  ListNode* partition(ListNode *head, int target) {
    auto fake_small_head = ListNode(0);
    auto fake_big_head = ListNode(0);

    auto small_tail = &fake_small_head;
    auto big_tail = &fake_big_head;

    for (auto p = head; p != NULL; p = p->next) {
      if (p->val < target) {
        small_tail->next = p;
        small_tail = p;
      }
      else {
        big_tail->next = p;
        big_tail = p;
      }
    }
    small_tail->next = NULL;
    big_tail->next = NULL;
    // If there is not any number smaller than target, return the original head.
    if (!fake_small_head.next) {
      return head;
    }
    // Otherwise connect the tail of small values with the head of big values.
    if (fake_big_head.next) {
      small_tail->next = fake_big_head.next;
    }
    
    return fake_small_head.next;
  }
};

void run(const vector<int> &nums, int target, const vector<int> &expected) {
  auto head = make_list(nums);

  if (head) {
    cout << "Input: " << head << " | " << target << endl;
  }
  else {
    cout << "Input: NULL | " << target << endl;
  }

  auto result = Solution().partition(head, target);
  if (result) {
    cout << "Result: " << result << endl;
  }
  else {
    cout << "Result: NULL" << endl;
  }

  auto expected_list = make_list(expected);

  assert((!expected_list && !result)
         || (*expected_list == *result));
}

int main() {
  auto nums = vector<int>{1, 4, 3, 2, 5, 2};
  auto expected = vector<int>{1, 2, 2, 4, 3, 5};
  run(nums, 3, expected);

  expected = {1, 4, 3, 2, 5, 2};
  run(nums, 8, expected);

  expected = {1, 4, 3, 2, 2, 5};
  run(nums, 5, expected);

  expected = {1, 4, 3, 2, 5, 2};
  run(nums, 0, expected);

  nums = {1};
  expected = {1};
  run(nums, 10, expected);

  nums = {};
  expected = {};
  run(nums, 10, expected);

  return 0;
}

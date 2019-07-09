/*
  Merge k sorted linked lists and return it as one sorted list. Analyze and
  describe its complexity.

  Example:

  Input:
  [
  1->4->5,
  1->3->4,
  2->6
  ]
  Output: 1->1->2->3->4->4->5->6
*/

#include "../util/common.hpp"

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode *> &lists) {
    auto nodes = list<ListNode *>(begin(lists), end(lists));
    nodes.remove(NULL);

    if (nodes.empty()) {
      return NULL;
    }
    nodes.sort([](auto a, auto b) { return a->val < b->val; });

    auto result = ListNode(0);
    auto node = &result;

    while (!nodes.empty()) {
      auto target = *begin(nodes);
      nodes.erase(begin(nodes));
      node->next = target;
      node = node->next;
      target = target->next;
      if (target) {
        auto position = find_if(begin(nodes), end(nodes),
                                [target](auto x) {
                                  return x->val > target->val;
                                });
        nodes.insert(position, target);
      }
    }
    
    return result.next;
  }
};

int main() {
  Solution solution;
  auto lists = vector<ListNode *>{
    make_list({1, 4, 5}),
    make_list({1, 3, 4}),
    make_list({2, 6})
  };

  cout << solution.mergeKLists(lists) << endl;

  lists = {NULL, make_list({1})};
  cout << solution.mergeKLists(lists) << endl;

  return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <queue>
#include <map>

#include <climits>
#include <cassert>

using namespace std;

template<class T>
void print(const T &collection) {
  for (auto item: collection) {
    cout << item << " ";
  }
  cout << endl;
}

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *make_list(const vector<int> &values) {
  auto head = ListNode(0);
  auto node = &head;
  for (auto value: values) {
    node->next = new ListNode(value);
    node = node->next;
  }
  return head.next;
}

ostream &operator <<(ostream &out, ListNode *node) {
  if (!node) {
    out << "NULL";
  }
  out << node->val;

  node = node->next;
  while (node) {
    out << "->" << node->val;
    node = node->next;
  }

  return out;
}

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>

#include <climits>
#include <cassert>

using namespace std;

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

ostream &operator <<(ostream &out, const ListNode *node) {
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

template <class T>
ostream &print(ostream &out, const T &thing) {
  auto it = begin(thing);
  if (it != end(thing)) {
    out << *it;
    it++;
    while (it != end(thing)) {
      out << ", " << *it;
      it++;
    }
  }
  return out;
}

template<class T>
ostream &operator <<(ostream &out, const deque<T> &container) {
  return print(out, container);
}

template<class T>
ostream &operator <<(ostream &out, const vector<T> &container) {
  return print(out, container);
}

template<class T>
ostream &operator <<(ostream &out, const list<T> &container) {
  return print(out, container);
}

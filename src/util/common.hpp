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

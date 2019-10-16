/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() < 2) {
      return intervals;
    }

    auto result = vector<vector<int>>();
    sort(begin(intervals), end(intervals),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    auto current = intervals[0];
    for (auto it = begin(intervals) + 1; it != end(intervals); it++) {
      if ((*it)[0] > current[1]) {
        // The new interval is totally out of current one, add the current to
        // the result.
        result.push_back(current);
        current = *it;
      }
      else if ((*it)[1] <= current[1]) {
        // The new interval is entirely wrapped by the current one, do nothing.
      }
      else {
        // The new interval overlaps with the old one.
        current[1] = (*it)[1];
      }
    }

    result.push_back(current);

    return result;
  }
};

int main() {
  Solution solution;

  auto intervals = vector<vector<int>>{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  cout << solution.merge(intervals) << endl;

  return 0;
}

/*
Given a set of non-overlapping intervals, insert a new interval into the
intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their
start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &new_interval) {
    if (intervals.empty()) {
      return vector<vector<int>>{new_interval};
    }
    auto first_it = begin(intervals);
    if (new_interval[1] < (*first_it)[0]) {
      intervals.insert(begin(intervals), new_interval);
      return intervals;
    }
    // Find the starting point (inclusive).
    auto start_it = find_if(begin(intervals), end(intervals),
                            [new_interval](auto interval) {
                              return new_interval[0] <= interval[1];
                            });
    // Find the end point (inclusive).
    auto end_it = find_if(begin(intervals), end(intervals),
                          [new_interval](auto interval) {
                            return new_interval[1] < interval[0];
                          });
    end_it--;
    // Construct the result.
    auto result = vector<vector<int>>(begin(intervals), start_it);
    auto current = new_interval;
    if (start_it != end(intervals) && (*start_it)[0] < new_interval[0]) {
      current[0] = (*start_it)[0];
    }
    if (end_it != end(intervals) && (*end_it)[1] > new_interval[1]) {
      current[1] = (*end_it)[1];
    }
    result.push_back(current);
    result.insert(end(result), end_it + 1, end(intervals));
        
    return result;
  }
};

void run(vector<vector<int>> &intervals, vector<int> &new_interval,
         const vector<vector<int>> &expected) {
  auto result = Solution().insert(intervals, new_interval);
  cout << "Result: " << endl << result << endl;
  assert(result == expected);
}

int main() {
  Solution solution;

  auto intervals = vector<vector<int>>{{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  auto new_interval = vector<int>{4, 8};
  auto expected = vector<vector<int>>{{1, 2}, {3, 10}, {12, 16}};
  run(intervals, new_interval, expected);

  intervals = {{2, 5}};
  new_interval = {0, 1};
  expected = {{0, 1}, {2, 5}};
  run(intervals, new_interval, expected);

  intervals = {{2, 5}};
  new_interval = {0, 4};
  expected = {{0, 5}};
  run(intervals, new_interval, expected);

  intervals = {{1, 3}, {6, 9}};
  new_interval = {2, 5};
  expected = {{1, 5}, {6, 9}};
  run(intervals, new_interval, expected);

  intervals = {{1, 4}, {7, 8}};
  new_interval = {4, 7};
  expected = {{1, 8}};
  run(intervals, new_interval, expected);

  intervals = {};
  new_interval = {1, 7};
  expected = {{1, 7}};
  run(intervals, new_interval, expected);

  intervals = {{1, 3}, {7, 8}};
  new_interval = {4, 6};
  expected = {{1, 3}, {4, 6}, {7, 8}};
  run(intervals, new_interval, expected);

  return 0;
}

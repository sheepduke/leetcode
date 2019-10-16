/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
 */

#include "../util/common.hpp"

class Solution {
public:
  string getPermutation(int n, int k) {
    auto input = vector<char>();
    for (auto i = 0; i < n; i++) {
      input.push_back('1'+ i);
    }
    vector<char> output;
    solve(output, input, k, 0);

    auto result = string(n, '0');
    for (auto i = 0; i < n; i++) {
      result[i] = output[i];
    }

    return result;
  }

private:
  void solve(vector<char> &result, const vector<char> &input,
             int &count, size_t start_index) {
    if (start_index >= input.size() - 1) {
      count--;
      if (count == 0) {
        result = input;
      }
      return;
    }

    for (auto i = start_index; i < input.size(); i++) {
      auto new_input = input;
      swap(new_input, i, start_index);
      sort(begin(new_input) + start_index + 1, end(new_input));
      solve(result, new_input, count, start_index + 1);
      if (count == 0) {
        return ;
      }
    }
  }

  void swap(vector<char> &input, size_t index1, size_t index2) {
    auto temp = input[index1];
    input[index1] = input[index2];
    input[index2] = temp;
  }
};

void run(int n, int k, string expected) {
  auto result = Solution().getPermutation(n, k);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  run(3, 3, "213");
  run(3, 5, "312");
  run(3, 6, "321");
  run(4, 9, "2314");
  run(9, 218621, "643791825");

  return 0;
}

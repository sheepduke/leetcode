/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:

    All inputs will be in lowercase.
    The order of your output does not matter.
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    auto hash_to_vector = map<string, vector<string>>();
    for (auto str: strs) {
      auto hash = str;
      sort(begin(hash), end(hash));
      if (hash_to_vector.find(hash) == end(hash_to_vector)) {
        hash_to_vector[hash] = vector<string>{str};
      }
      else {
        hash_to_vector[hash].push_back(str);
      }
    }

    auto result = vector<vector<string>>();
    for (auto pair: hash_to_vector) {
      result.push_back(pair.second);
    }
    return result;
  }
};

int main() {
  Solution solution;

  auto input = vector<string>{
    "eat", "tea", "tan", "ate", "nat", "bat"
  };

  cout << solution.groupAnagrams(input) << endl;

  return 0;
}

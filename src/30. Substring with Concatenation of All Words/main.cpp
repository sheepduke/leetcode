/*
  You are given a string, s, and a list of words, words, that are all of the
  same length. Find all starting indices of substring(s) in s that is a
  concatenation of each word in words exactly once and without any intervening
  characters.

  Example 1:

  Input:
  s = "barfoothefoobarman",
  words = ["foo","bar"]

  Output: [0,9]

  Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar"
  respectively.  The output order does not matter, returning [9,0] is fine too.

  Example 2:

  Input:
  s = "wordgoodgoodgoodbestword",
  words = ["word","good","best","word"]
  
  Output: []
*/

#include "../util/common.hpp"

class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty() || words[0].length() > s.length()
        || s.length() < words.size() * words[0].length()) {
      return {};
    }

    auto word_count = map<string, unsigned int>();
    for (auto word: words) {
      word_count[word]++;
    }
    
    auto slice_length = words[0].length();
    auto result = vector<int>();
    for (auto start = 0u; start <= s.length() - slice_length; start++) {
      auto seen_word_count = map<string, unsigned int>();
      auto count = 0u;
      for (auto left = start;
           count < words.size();
           left += slice_length, count++) {
        auto target = s.substr(left, slice_length);
        if (word_count.find(target) != end(word_count)
            && seen_word_count[target] < word_count[target]) {
          seen_word_count[target]++;
        } else {
          break;
        }
      }
      if (count == words.size()) {
        result.push_back(start);
      }
    }
    return result;
  }
};

int main() {
  Solution solution;

  auto s = "barfoothefoobarman";
  auto words = vector<string>{"foo", "bar"};
  auto result = solution.findSubstring(s, words);
  assert(result.size() == 2);
  assert(result[0] == 0);
  assert(result[1] == 9);

  s = "wordgoodgoodgoodbestword";
  words = {"word", "good", "best", "word"};
  result = solution.findSubstring(s, words);
  assert(result.empty());

  s = "a";
  words = {"a"};
  result = solution.findSubstring(s, words);
  assert(result.size() == 1 && result[0] == 0);

  return 0;
}

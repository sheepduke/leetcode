/*
  Given a string containing digits from 2-9 inclusive, return all possible
  letter combinations that the number could represent.

  A mapping of digit to letters (just like on the telephone buttons) is given
  below. Note that 1 does not map to any letters.

  Example:

  Input: "23"
  Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

  Note:

  Although the above answer is in lexicographical order, your answer could be
  in any order you want.

*/

#include "../util/common.hpp"

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return {};
    }
    // Initialize the calculation process.
    deque<string> combinations;
    for (auto ch: digit_to_string(digits[0])) {
      combinations.push_back(string(1, ch));
    }
    for (auto digit = begin(digits) + 1; digit < end(digits); digit++) {
      auto strings = digit_to_string(*digit);
      for (auto count = combinations.size(); count > 0; count--) {
        auto combination = combinations.front();
        for (auto ch: strings) {
          combinations.push_back(combination + string(1, ch));
        }
        combinations.pop_front();
      }
    }

    return vector<string>(begin(combinations), end(combinations));
  }

  string digit_to_string(char digit) {
    switch (digit) {
    case '2': return "abc";
    case '3': return "def";
    case '4': return "ghi";
    case '5': return "jkl";
    case '6': return "mno";
    case '7': return "pqrs";
    case '8': return "tuv";
    case '9': return "wxyz";
    default: return "";
    }
  }
};

int main() {
  Solution solution;
  
  auto digits = "23";
  print(solution.letterCombinations(digits));

  return 0;
}

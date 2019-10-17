/*
Given an array of words and a width maxWidth, format the text such that each
line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the
number of spaces on a line do not divide evenly between words, the empty slots
on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is
inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
Example 1:

Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
Example 2:

Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
Example 3:

Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<string> fullJustify(vector<string>& words, int max_width) {
    // Group the words into lines.
    auto lines = vector<vector<vector<string>::iterator>>{{}};
    auto total_width = 0;
    for (auto it = begin(words); it != end(words); it++) {
      if (total_width + it->length() > max_width) {
        lines.push_back(vector<vector<string>::iterator>{it});
        total_width = it->length() + 1;
      }
      else {
        lines.back().push_back(it);
        total_width += it->length() + 1;
      }
    }
    // For each line, justify the words.
    auto result = vector<string>();
    for (auto it = begin(lines); it != end(lines); it++) {
      result.push_back(get_justified_string(*it, max_width,
                                            (it == end(lines) - 1 ? true : false)));
    }
    return result;
  }

private:
  string get_justified_string(const vector<vector<string>::iterator> &iterators,
                              int max_width, bool left_justified = false) {
    if (iterators.size() == 1) left_justified = true;

    stringstream ss;
    if (left_justified) {
      ss << *iterators.front();
      auto width = iterators.front()->length();
      for (auto word = next(begin(iterators)); word != end(iterators); word++) {
        ss << " " << **word;
        width += (*word)->length() + 1;
      }
      ss << string(max_width - width, ' ');
    }
    else {
      auto total_width = 0;
      for (auto it: iterators) {
        total_width += it->length();
      }
      auto base_space_width = (max_width - total_width) / (iterators.size() - 1);
      auto extra_sapce_count = (max_width - total_width) % (iterators.size() - 1);

      ss << *iterators.front();
      for (auto itt = begin(iterators) + 1; itt != end(iterators); itt++) {
        auto space_count = base_space_width;
        if (extra_sapce_count > 0) {
          space_count++;
          extra_sapce_count--;
        }
        ss << string(space_count, ' ');
        ss << **itt;
      }
    }
    return ss.str();
  }
};

void run(vector<string> &words, int max_width) {
  cout << "Input: " << words << endl;
  auto result = Solution().fullJustify(words, max_width);
  cout << "Result: " << endl;
  for (auto line: result) {
    cout << "\"" << line << "\"" << endl;
  }
}

int main() {
  Solution solution;

  auto words = vector<string>{"This", "is", "an", "example", "of", "text", "justification."};
  run(words, 16);

  words = {"What", "must", "be", "acknowledgment", "shall", "be"};
  run(words, 16);

  return 0;
}

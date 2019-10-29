/*
Given a string containing only digits, restore it by returning all possible
valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
 */

#include "../util/common.hpp"

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    auto result = vector<string>();
    auto taken = vector<string>();
    solve(result, taken, "", s);
    return result;
  }

private:
  void solve(vector<string> &solutions, vector<string> &taken,
             string current, string input) {
    if (input.empty() && taken.size() >= 3) {
      if (taken.size() == 3) {
        taken.push_back(current);
        solutions.push_back(vector_to_ip(taken));
        taken.pop_back();
      }
      else {
        solutions.push_back(vector_to_ip(taken));
      }
    }
    else if (!input.empty() && taken.size() < 4) {
      if (current.length() > 0) {
        // Try to add a dot.
        taken.push_back(current);
        solve(solutions, taken, "", input);
        taken.pop_back();
      }
      current.push_back(input.front());
      if (current.size() <= 3
          && (current.size() == 1
              || (current.size() > 1 && current.front() != '0'))
          && stoi(current) <= 255) {
        solve(solutions, taken, current, input.substr(1));
      }
    }
  }

  string vector_to_ip(const vector<string> &strs) {
    stringstream ss;
    ss << strs[0];
    for (auto i = 1u; i < 4; i++) {
      ss << "." << strs[i];
    }
    return ss.str();
  }
};

void run(string s) {
  cout << endl << "Input: " << s << endl;
  auto result = Solution().restoreIpAddresses(s);
  cout << "Result: " << result << endl;
}

int main() {
  run("25525511135");
  run("010010");
  
  return 0;
}

/*
A message containing letters from A-Z is being encoded to numbers using the
following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26

Given a non-empty string containing only digits, determine the total number of
ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
 */

#include "../util/common.hpp"

// class Solution {
// public:
//     int numDecodings(string s) {
        
//         //Corner case - 
//         if(s[0]=='0')return 0;
        
//         //General case - 
//         vector<int>dp(s.length()+1);
//         //dp[i] = number of ways to decode the array till i
//         dp[0] = 1;
//         dp[1] = 1;
        
//         for(int i=2;i<=s.length();i++){
//             int one = stoi(s.substr(i-1,1));
//             int two = stoi(s.substr(i-2,2));
            
//             if(one>=1)dp[i]=dp[i]+dp[i-1];
//             if(two>=10 && two<=26)dp[i]=dp[i]+dp[i-2];
//         }
        
//         return dp[s.length()];
//     }
// };

class Solution {
public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
      return 0;
    }
    if (s.length() == 1) {
      return 1;
    }

    auto possible_count = vector<int>(s.length(), 0);
    possible_count[0] = (s[0] > '0' ? 1 : 0);
    possible_count[1] = (s[1] > '0' ? 1 : 0);
    auto first_two = s.substr(0, 2);
    if (first_two >= "10" && first_two <= "26") {
      possible_count[1]++;
    }
    
    for (auto i = 2u; i < s.length(); i++) {
      if (s[i] > '0') {
        possible_count[i] += possible_count[i - 1];
      }
      auto last_two = s.substr(i - 1, 2);
      if (last_two >= "10" && last_two <= "26") {
        possible_count[i] += possible_count[i - 2];
      }
    }

    return possible_count[s.length() - 1];
  }
};

void run(string s, int expected) {
  cout << "Input: " << s << endl;
  auto result = Solution().numDecodings(s);
  cout << "Result: " << result << endl;
  assert(result == expected);
}

int main() {
  run("101", 1);
  run("12", 2);
  run("226", 3);
  run("123", 3);
  run("0", 0);

  return 0;
}

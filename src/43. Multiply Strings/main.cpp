/*
  Given two non-negative integers num1 and num2 represented as strings, return
  the product of num1 and num2, also represented as a string.

  Example 1:

  Input: num1 = "2", num2 = "3"
  Output: "6"

  Example 2:

  Input: num1 = "123", num2 = "456"
  Output: "56088"

  Note:

  The length of both num1 and num2 is < 110.
  Both num1 and num2 contain only digits 0-9.
  Both num1 and num2 do not contain any leading zero, except the number 0 itself.
  You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

#include "../util/common.hpp"

class Solution {
public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    if (num1 == "1") return num2;
    if (num2 == "1") return num1;

    string *longer_num = (num1.size() >= num2.size() ? &num1 : &num2);
    string *shorter_num = (longer_num == &num1 ? &num2 : &num1);

    string result;
    for (auto ch: *shorter_num) {
      result = plus(result + "0", multiply(*longer_num, ch));
    }

    // Remove leading zero if any.
    if (result[0] == '0') return result.substr(1);
    else return result;
  }

  string plus(string num1, string num2) {
    unsigned int carry = 0;
    string result;

    int index1 = num1.size() - 1;
    int index2 = num2.size() - 1;

    for (; index1 >= 0 && index2 >= 0; index1--, index2--) {
      auto value = (num1[index1] - '0') + (num2[index2] - '0') + carry;
      carry = value / 10;
      result.push_back(value % 10 + '0');
    }

    // Process possible remaining data.
    auto index = -1;
    string *remaining_num = NULL;
    if (index1 >= 0) {
      index = index1;
      remaining_num = &num1;
    } else if (index2 >= 0) {
      index = index2;
      remaining_num = &num2;
    }

    for (; index >= 0; index--) {
      auto value = (*remaining_num)[index] - '0' + carry;
      carry = value / 10;
      result.push_back(value % 10 + '0');
    }
    if (carry > 0) {
      result.push_back(carry + '0');
    }

    reverse(begin(result), end(result));
    
    return result;
  }
  
  // Multiply given num with digit.
  // 
  string multiply(string num, char digit) {
    if (digit == '0') return "0";
    if (digit == '1') return num;
    auto digit_value = digit - '0';

    auto carry = 0u;
    string result;
    
    for (auto it = rbegin(num); it < rend(num); it++) {
      auto value = (*it - '0') * digit_value + carry;
      carry = value / 10;
      result.push_back(value % 10 + '0');
    }
    if (carry > 0) result.push_back(carry + '0');

    reverse(begin(result), end(result));

    return result;
  }
};

int main() {
  Solution solution;

  assert(solution.multiply("140", "721") == "100940");
  assert(solution.multiply("2925", "4787") == "14001975");
  assert(solution.multiply("1234", "0") == "0");
  assert(solution.multiply("0", "0") == "0");
  assert(solution.multiply("2", "3") == "6");
  assert(solution.multiply("123", "456") == "56088");
  

  return 0;
}

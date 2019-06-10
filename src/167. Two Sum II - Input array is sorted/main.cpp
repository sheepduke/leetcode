#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      auto left = 0;
      auto right = numbers.size() - 1;
      while (left < right) {
        auto sum = numbers[left] + numbers[right];
        if (sum == target) {
          vector<int> result;
          result.push_back(left + 1);
          result.push_back(right + 1);
          return result;
        } else if (sum < target) {
          left++;
        } else {
          right--;
        }
      }
      return vector<int>();
    }
};

void print_vector(const vector<int> &vec) {
  for (auto num : vec) {
    cout << num << ", ";
  }
  cout << endl;
}

int main() {
  Solution solution;
  vector<int> input = {2, 3, 4};
  auto result = solution.twoSum(input, 6);
  print_vector(result);

  input = {-1, 0};
  result = solution.twoSum(input, -1);
  print_vector(result);
  
  return 0;
}

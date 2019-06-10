#include <iostream>
#include <vector>

using namespace std;

/**
 * 1. Two Sum
 Easy

 Given an array of integers, return indices of the two numbers such that they
 add up to a specific target.

 You may assume that each input would have exactly one solution, and you may
 not use the same element twice.

 Example:

 Given nums = [2, 7, 11, 15], target = 9,

 Because nums[0] + nums[1] = 2 + 7 = 9,
 return [0, 1].

*/

#include <map>

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> number_indices;

    for (auto index = 0; index < nums.size(); index++) {
      auto num = nums[index];
      auto remaining = target - num;
      if (number_indices.find(remaining) != number_indices.end()
          && number_indices.at(remaining) != index) {
        vector<int> result;
        result.push_back(index);
        result.push_back(number_indices[remaining]);
        return result;
      } else {
        number_indices[num] = index;
      }
    }
    return vector<int>();
  }
};

int main() {
  Solution solution;
  
  vector<int> nums = { 2, 7, 11, 15 };
  for (auto index : solution.twoSum(nums, 9)) {
    cout << index << " ";
  }
  cout << endl;
}

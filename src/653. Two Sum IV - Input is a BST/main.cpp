/**
 * Given a Binary Search Tree and a target number, return true if there exist
 * two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True

 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  bool findTarget(TreeNode* root, int target) {
    vector<int> nums;
    tree_to_array(root, nums);
    auto left = 0;
    auto right = nums.size() - 1;
    while (left < right) {
      auto sum = nums[left] + nums[right];
      if (sum == target) {
        return true;
      } else if (sum < target) {
        left++;
      } else {
        right--;
      }
    }
    return false;
  }

private:
  void tree_to_array(TreeNode *root, vector<int> &array) {
    if (root) {
      tree_to_array(root->left, array);
      array.push_back(root->val);
      tree_to_array(root->right, array);
    }
  }
};

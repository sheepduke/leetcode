/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

> Google: 90% of our engineers use the software you wrote (Homebrew), but you
> can’t invert a binary tree on a whiteboard so f*** off.
*/

#include "../util/common.hpp"

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return NULL;
    }
    auto left = invertTree(root->left);
    auto right = invertTree(root->right);
    root->left = left;
    root->right = right;
    return root;
  }
};

int main() {
  Solution solution;

  return 0;
}

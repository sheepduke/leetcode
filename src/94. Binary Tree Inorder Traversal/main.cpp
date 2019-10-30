/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
 */

#include "../util/common.hpp"

/**
 * Recursive version.
 */
// class Solution {
// public:
//   vector<int> inorderTraversal(TreeNode* root) {
//     auto nodes = vector<int>();
//     traverse(nodes, root);
//     return nodes;
//   }

// private:
//   void traverse(vector<int> &nodes, TreeNode *root) {
//     if (root) {
//       traverse(nodes, root->left);
//       nodes.push_back(root->val);
//       traverse(nodes, root->right);
//     }
//   }
// };

/**
 * Iteration version.
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root) {
        return vector<int>();
      }

      auto result = vector<int>();
      auto nodes = stack<TreeNode *>();
      auto visited = set<TreeNode *>{root};
      nodes.push(root);

      while (!nodes.empty()) {
        auto node = nodes.top();
        if (node->left && visited.find(node->left) == end(visited)) {
          nodes.push(node->left);
        }
        else {
          result.push_back(node->val);
          nodes.pop();
          visited.insert(node);
          if (node->right && visited.find(node->right) == end(visited)) {
            nodes.push(node->right);
          }
        }
      }

      return result;
    }
};

int main() {
  auto root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);

  Solution().inorderTraversal(root);

  return 0;
}

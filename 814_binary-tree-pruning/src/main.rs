#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

struct Solution {}

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        match root {
            None => None,
            Some(root_node) => {
                let left = Solution::prune_tree(root_node.borrow().left.clone());
                let right = Solution::prune_tree(root_node.borrow().right.clone());
                if root_node.borrow().val == 1 || left != None || right != None {
                    root_node.borrow_mut().left = left;
                    root_node.borrow_mut().right = right;
                    Some(root_node.clone())
                } else {
                    None
                }
            }
        }
    }
}

fn main() {
    println!("Hello, world!");
}

struct Solution {}

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

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn merge_trees(
        t1: Option<Rc<RefCell<TreeNode>>>,
        t2: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if t1 == None {
            t2
        } else if t2 == None {
            t1
        } else {
            let t1_node = t1.as_ref().unwrap().borrow();
            let t2_node = t2.as_ref().unwrap().borrow();
            let mut root = TreeNode::new(t1_node.val + t2_node.val);
            root.left = Self::merge_trees(t1_node.left.clone(), t2_node.left.clone());
            root.right = Self::merge_trees(t1_node.right.clone(), t2_node.right.clone());
            Some(Rc::new(RefCell::new(root)))
        }
    }
}

fn main() {
    println!("Hello, world!");
}

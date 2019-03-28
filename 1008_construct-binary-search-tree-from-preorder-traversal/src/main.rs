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
    pub fn bst_from_preorder(preorder: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        if preorder.is_empty() {
            None
        } else {
            let root = Solution::new_node(preorder[0]);

            for i in 1..preorder.len() {
                let val = preorder[i];

                let mut target = Rc::clone(root.as_ref().unwrap());

                loop {
                    if val < target.borrow().val {
                        if target.borrow().left == None {
                            target.borrow_mut().left = Solution::new_node(val);
                            break;
                        } else {
                            let temp = Rc::clone(target.borrow().left.as_ref().unwrap());
                            target = temp;
                        }
                    } else {
                        if target.borrow().right == None {
                            target.borrow_mut().right = Solution::new_node(val);
                            break;
                        } else {
                            let temp = Rc::clone(target.borrow().right.as_ref().unwrap());
                            target = temp;
                        }
                    }
                }
            }
            root
        }
    }

    fn new_node(val: i32) -> Option<Rc<RefCell<TreeNode>>> {
        Some(Rc::new(RefCell::new(TreeNode::new(val))))
    }
}

fn main() {
    println!(
        "{:#?}",
        Solution::bst_from_preorder(vec![8, 5, 1, 7, 10, 12])
    );
}

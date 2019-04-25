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
use std::collections::HashMap;
use std::rc::Rc;
impl Solution {
    pub fn all_possible_fbt(n: i32) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        let mut result: HashMap<i32, Vec<Option<Rc<RefCell<TreeNode>>>>> = HashMap::new();
        result.insert(1, vec![Some(Rc::new(RefCell::new(TreeNode::new(0))))]);
        Self::all_possible_fbt_recv(n, &mut result)
    }

    pub fn all_possible_fbt_recv(
        n: i32,
        result: &mut HashMap<i32, Vec<Option<Rc<RefCell<TreeNode>>>>>,
    ) -> Vec<Option<Rc<RefCell<TreeNode>>>> {
        match result.get(&n) {
            Some(r) => r.clone(),
            None => {
                let mut possibilities = Vec::new();
                for left_node_count in 1..n - 1 {
                    let right_node_count = n - 1 - left_node_count;
                    Self::all_possible_fbt_recv(left_node_count, result)
                        .iter()
                        .for_each(|left_node| {
                            Self::all_possible_fbt_recv(right_node_count, result)
                                .iter()
                                .for_each(|right_node| {
                                    let mut root_node = TreeNode::new(0);
                                    root_node.left = left_node.clone();
                                    root_node.right = right_node.clone();
                                    possibilities.push(Some(Rc::new(RefCell::new(root_node))));
                                })
                        })
                }
                result.insert(n, possibilities.clone());
                possibilities
            }
        }
    }
}

fn main() {
    let input = 19;
    let result = Solution::all_possible_fbt(input);
    println!("Possible Count: {}", result.len());
}

struct Solution {}

use std::collections::HashMap;

/// This solution can be further optimized as below:
/// Make a vector storing the indices of the original vector, then sort the
/// indices vector according to the value of the original numbers.
/// Then use 2 pointers left and right and find out the target.
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash_table = HashMap::new();

        for (index, num) in nums.iter().enumerate() {
            let complement = target - num;
            match hash_table.get(&complement) {
                None => (),
                Some(complement_index) => {
                    return vec![*complement_index as i32, index as i32];
                }
            }
            hash_table.insert(num, index);
        }
        return vec![];
    }
}

fn main() {
    let input = vec![2, 7, 11, 15];
    let target = 9;
    println!("{:?}", Solution::two_sum(input, target));
}

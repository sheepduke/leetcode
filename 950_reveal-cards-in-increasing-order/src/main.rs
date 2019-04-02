struct Solution {}

use std::collections::LinkedList;

/// In this problem there are 2 variables:
/// 1. The card itself.
/// 2. The index of cards.
///
/// Since the sorted input is actually the "result" of card revealing process,
/// it is easy to solve this problem if we use a queue to simulate the
/// revealing and adjust the result accordingly.
impl Solution {
    pub fn deck_revealed_increasing(deck: Vec<i32>) -> Vec<i32> {
        let mut sorted_deck = deck.clone();
        sorted_deck.sort();

        let mut indexes: LinkedList<usize> = LinkedList::new();
        for i in 0..deck.len() {
            indexes.push_back(i);
        }

        let mut result = deck.clone();
        for i in 0..deck.len() {
            let index = indexes.pop_front().unwrap();
            result[index] = sorted_deck[i];
            match indexes.pop_front() {
                Some(front) => indexes.push_back(front),
                None => (),
            }
        }
        result
    }
}

fn main() {
    let input = vec![17, 13, 11, 2, 3, 5, 7];
    let result = Solution::deck_revealed_increasing(input);
    println!("Result: {:?}", result);
}

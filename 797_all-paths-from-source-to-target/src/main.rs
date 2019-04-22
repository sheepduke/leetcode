struct Solution {}

use std::collections::HashMap;

impl Solution {
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut result: HashMap<i32, Vec<Vec<i32>>> = HashMap::new();
        let end = graph.len() as i32 - 1;
        result.insert(end, vec![vec![end]]);

        for current_index in (0..end).rev() {
            Self::calculate_single(&graph, current_index, &mut result);
        }

        match result.get(&0) {
            None => vec![vec![]],
            Some(paths) => paths.clone(),
        }
    }

    pub fn calculate_single(
        graph: &Vec<Vec<i32>>,
        start: i32,
        result: &mut HashMap<i32, Vec<Vec<i32>>>,
    ) {
        let mut all_paths = Vec::new();
        for next in &graph[start as usize] {
            if !result.contains_key(&next) {
                Self::calculate_single(graph, *next, result)
            }
            for path in result.get(next).unwrap() {
                let mut one_path = vec![start];
                one_path.append(&mut path.clone());
                all_paths.push(one_path);
            }
        }
        result.insert(start, all_paths);
    }
}

fn main() {
    let input = vec![vec![1, 2], vec![3], vec![3], vec![]];
    let result = Solution::all_paths_source_target(input);
    println!("Result: {:?}", result);
}

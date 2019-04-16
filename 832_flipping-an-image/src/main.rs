struct Solution {}

impl Solution {
    pub fn flip_and_invert_image(a: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut result = Vec::new();
        a.into_iter().for_each(|row| {
            let mut temp = Vec::new();
            row.into_iter().rev().for_each(|num| {
                temp.push(num ^ 1);
            });
            result.push(temp);
        });
        result
    }
}

#[test]
fn test1() {
    let input = vec![vec![1, 1, 0], vec![1, 0, 1], vec![0, 0, 0]];
    assert_eq!(
        vec![vec![1, 0, 0], vec![0, 1, 0], vec![1, 1, 1]],
        Solution::flip_and_invert_image(input)
    );
}

#[test]
fn test2() {
    let input = vec![
        vec![1, 1, 0, 0],
        vec![1, 0, 0, 1],
        vec![0, 1, 1, 1],
        vec![1, 0, 1, 0],
    ];
    assert_eq!(
        vec![
            vec![1, 1, 0, 0],
            vec![0, 1, 1, 0],
            vec![0, 0, 0, 1],
            vec![1, 0, 1, 0]
        ],
        Solution::flip_and_invert_image(input)
    );
}

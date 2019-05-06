struct Solution {}

impl Solution {
    pub fn partition_labels(s: String) -> Vec<i32> {
        let mut result: Vec<i32> = Vec::new();

        let chars: Vec<char> = s.chars().collect();
        let mut start = 0;
        let mut end = 1;

        while start < s.len() {
            let mut current = start;
            while current < end {
                end = end.max(s.rfind(chars[current]).unwrap() + 1);
                current += 1;
            }
            result.push((end - start) as i32);
            start = current;
            end = start + 1;
        }
        result
    }
}

#[test]
fn test() {
    let input = "ababcbacadefegdehijhklij".to_string();
    let result = Solution::partition_labels(input);

    assert_eq!(vec![9, 7, 8], result);
}

fn main() {
    let input = "ababcbacadefegdehijhklij".to_string();
    let result = Solution::partition_labels(input);
}

struct Solution {}

impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut start = 0;
        let mut end = s.len();
        let mut result = Vec::new();
        s.chars().for_each(|ch| {
            if ch == 'I' {
                result.push(start);
                start += 1;
            } else {
                result.push(end as i32);
                end -= 1;
            }
        });
        result.push(start);
        result
    }
}

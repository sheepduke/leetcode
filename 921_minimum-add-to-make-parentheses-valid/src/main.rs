struct Solution {}

impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut count = 0;
        let mut left_count = 0;
        s.chars().for_each(|c| {
            if c == '(' {
                left_count += 1;
            } else if c == ')' && left_count > 0 {
                left_count -= 1;
            } else {
                count += 1;
            }
        });
        count += left_count;
        count
    }
}

#[test]
fn test() {
    let input = "())".to_string();
    assert_eq!(1, Solution::min_add_to_make_valid(input));

    let input = "(((".to_string();
    assert_eq!(3, Solution::min_add_to_make_valid(input));

    let input = "()))((".to_string();
    assert_eq!(4, Solution::min_add_to_make_valid(input));
}

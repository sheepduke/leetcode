struct Solution {}

impl Solution {
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut left_parentheses_count = 0;
        let mut result = String::new();
        s.chars().rev().for_each(|ch| match ch {
            ')' => {
                if left_parentheses_count > 0 {
                    result.push(ch);
                }
                left_parentheses_count += 1;
            }
            '(' => {
                if left_parentheses_count > 1 {
                    result.push(ch);
                }
                left_parentheses_count -= 1;
            }
            _ => panic!("Invalid character."),
        });
        result.chars().rev().collect()
    }
}

#[test]
fn test() {
    assert_eq!(
        "()()()",
        Solution::remove_outer_parentheses("(()())(())".to_string())
    );
    assert_eq!(
        "()()()()(())",
        Solution::remove_outer_parentheses("(()())(())(()(()))".to_string())
    );
    assert_eq!("", Solution::remove_outer_parentheses("()()".to_string()));
}

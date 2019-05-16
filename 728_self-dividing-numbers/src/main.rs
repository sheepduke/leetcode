struct Solution {}

impl Solution {
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        (left..=right).filter(Self::can_self_dividing).collect()
    }

    pub fn can_self_dividing(num: &i32) -> bool {
        let original_num = *num;
        let mut num = original_num;
        while num > 0 {
            let digit = num % 10;
            if digit == 0 || original_num % digit != 0 {
                return false;
            }
            num /= 10;
        }
        true
    }
}

#[test]
fn test() {
    let left = 1;
    let right = 22;
    let expected = vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22];
    let result = Solution::self_dividing_numbers(left, right);
    assert_eq!(expected, result);
}

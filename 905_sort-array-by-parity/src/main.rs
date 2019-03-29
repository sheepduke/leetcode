struct Solution {}
impl Solution {
    pub fn sort_array_by_parity(a: Vec<i32>) -> Vec<i32> {
        let mut result: Vec<i32> = a.clone();
        let mut first = 0;
        let mut last = result.len() - 1;

        while first < last {
            if result[first] % 2 == 0 {
                first += 1;
            } else if result[last] % 2 != 0 {
                last -= 1;
            } else {
                result.swap(first, last);
            }
        }

        result
    }
}

#[test]
fn test() {
    assert_eq!(
        Solution::sort_array_by_parity(vec![3, 1, 2, 4]),
        vec![4, 2, 1, 3]
    )
}

struct Solution {}

/// It can be optimized to use the Brian Kernighan algorithm.
///
/// while(n != 0){
///     n &= (n-1);
///     count += 1;
/// }
impl Solution {
    pub fn hamming_distance(x: i32, y: i32) -> i32 {
        let mut xor = x ^ y;
        let mut count = 0;
        while xor > 0 {
            if xor % 2 != 0 {
                count += 1;
            }
            xor /= 2;
            // Optimized version:
            // xor &= xor - 1;
            // count += 1;
        }
        count
    }
}

#[test]
fn test() {
    assert_eq!(2, Solution::hamming_distance(1, 4));
}

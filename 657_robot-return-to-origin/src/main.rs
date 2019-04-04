struct Solution {}

impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let (mut x, mut y) = (0, 0);
        moves.chars().for_each(|ch| match ch {
            'U' => y -= 1,
            'D' => y += 1,
            'L' => x -= 1,
            'R' => x += 1,
            _ => panic!("Unexpected character"),
        });
        x == 0 && y == 0
    }
}

fn main() {
    let input = "UDR";
    let result = Solution::judge_circle(String::from(input));
    println!("Result: {}", result);
}

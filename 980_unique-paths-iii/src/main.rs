struct Solution {}

use std::clone::Clone;
use std::cmp::PartialEq;

#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

impl Clone for Point {
    fn clone(&self) -> Self {
        Point { ..*self }
    }
}

impl PartialEq for Point {
    fn eq(&self, other: &Point) -> bool {
        self.x == other.x && self.y == other.y
    }
}

impl Solution {
    pub fn unique_paths_iii(grid: Vec<Vec<i32>>) -> i32 {
        if grid.is_empty() || grid[0].is_empty() {
            return 0;
        }
        // Find start and end point.
        let mut start = Point { x: 0, y: 0 };
        let mut cell_count = 0;
        for row in 0..grid.len() {
            for col in 0..grid[row].len() {
                match grid[row][col] {
                    1 => {
                        start = Point {
                            x: row as i32,
                            y: col as i32,
                        }
                    }
                    0 => cell_count += 1,
                    _ => (),
                }
            }
        }

        // Solve it!
        Solution::unique_path_recv(&grid, &start, cell_count)
    }

    pub fn unique_path_recv(grid: &Vec<Vec<i32>>, start: &Point, cell_count: i32) -> i32 {
        if start.x < 0
            || start.x as usize >= grid.len()
            || start.y < 0
            || start.y as usize >= grid[0].len()
            || grid[start.x as usize][start.y as usize] == -1
        {
            0
        } else if grid[start.x as usize][start.y as usize] == 2 {
            if cell_count < 0 {
                1
            } else {
                0
            }
        } else {
            let mut count = 0;
            let mut new_grid = grid.clone();
            new_grid[start.x as usize][start.y as usize] = -1;
            count += Solution::unique_path_recv(
                &new_grid,
                &Point {
                    x: start.x - 1,
                    ..*start
                },
                cell_count - 1,
            );
            count += Solution::unique_path_recv(
                &new_grid,
                &Point {
                    x: start.x + 1,
                    ..*start
                },
                cell_count - 1,
            );
            count += Solution::unique_path_recv(
                &new_grid,
                &Point {
                    y: start.y - 1,
                    ..*start
                },
                cell_count - 1,
            );
            count += Solution::unique_path_recv(
                &new_grid,
                &Point {
                    y: start.y + 1,
                    ..*start
                },
                cell_count - 1,
            );

            count
        }
    }
}

fn main() {
    let grid = vec![vec![1, 0, 0, 0], vec![0, 0, 0, 0], vec![0, 0, 0, 2]];
    // let grid = vec![vec![0, 1], vec![2, 0]];
    let result = Solution::unique_paths_iii(grid);
    println!("Result: {}", result);
}

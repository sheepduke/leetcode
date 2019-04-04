struct Solution {}

use std::collections::HashMap;

impl Solution {
    pub fn find_and_replace_pattern(words: Vec<String>, pattern_string: String) -> Vec<String> {
        let mut pattern: Vec<char> = Vec::new();
        pattern_string.chars().for_each(|ch| pattern.push(ch));

        let mut result: Vec<String> = Vec::new();
        for word in words {
            let mut word_to_pattern: HashMap<char, char> = HashMap::new();
            let mut pattern_to_word: HashMap<char, char> = HashMap::new();
            let mut can_be_mapped = true;
            for (index, ch) in word.chars().enumerate() {
                if !word_to_pattern.contains_key(&ch)
                    && !pattern_to_word.contains_key(&pattern[index])
                {
                    word_to_pattern.insert(ch, pattern[index]);
                    pattern_to_word.insert(pattern[index], ch);
                } else if *word_to_pattern.get(&ch).unwrap_or(&'\0') != pattern[index]
                    || *pattern_to_word.get(&pattern[index]).unwrap_or(&'\0') != ch
                {
                    can_be_mapped = false;
                    break;
                }
            }
            if can_be_mapped {
                result.push(word.clone());
            }
        }
        result
    }
}

fn main() {
    let input = vec!["abc", "deq", "mee", "aqq", "dkd", "ccc"];
    let pattern = "abb";
    let result = Solution::find_and_replace_pattern(
        input.iter().map(|string| string.to_string()).collect(),
        pattern.to_string(),
    );
    println!("Matched: {:?}", result);
}

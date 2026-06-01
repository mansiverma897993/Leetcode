impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String { 
        match strs.is_empty() {
            true => "".to_string(),
            _ => {
                strs.iter().skip(1).fold(strs[0].clone(), |acc, x| {
                     acc
                        .chars()
                        .zip(x.chars())
                        .take_while(|(x,y)| x == y)
                        .map(|(x, _)| x)
                        .collect()
                })
            }
        }
    }
}
#solution is much faster in rust instead of c++ because of the way it handles strings and memory management. Rust's ownership model allows for more efficient memory usage and avoids unnecessary copying of data, which can lead to faster execution times. Additionally, Rust's standard library provides powerful tools for working with strings, making it easier to implement algorithms like finding the longest common prefix efficiently. In contrast, C++ may require more manual memory management and can be prone to issues like buffer over
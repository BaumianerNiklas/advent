pub fn leftpad(s: &str, n: usize) -> String {
    let repetitions = if n >= s.len() { n - s.len() } else { 0 };
    "0".repeat(repetitions) + s
}

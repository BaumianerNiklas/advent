mod days;
mod util;

use std::env;

use crate::{
    days::get_day,
    util::input::{input_for_day, sample_for_day},
};

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        eprintln!("Usage: cargo run -- <day> [--only-sample]");
        return;
    }

    let day: u8 = args[1].parse().expect("Invalid day");

    let (part1, part2) = get_day(day);
    if part1.is_none() && part2.is_none() {
        eprintln!("Day {} not implemented.", day);
        return;
    }

    let sample = sample_for_day(day);
    let input = input_for_day(day);

    println!("=== SAMPLE ===");
    if let Some(part1) = part1 {
        println!("Part 1: {}", part1(&sample));
    }
    if let Some(part2) = part2 {
        println!("Part 2: {}", part2(&sample));
    }

    if !args.contains(&"--only-sample".to_owned()) {
        println!("=== INPUT ===");
        if let Some(part1) = part1 {
            println!("Part 1: {}", part1(&input));
        }
        if let Some(part2) = part2 {
            println!("Part 2: {}", part2(&input));
        }
    }
}

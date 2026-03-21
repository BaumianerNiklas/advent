mod day03;
mod day04;
mod day05;

type DayFn = fn(&str) -> i64;

pub fn get_day(day: u8) -> (Option<DayFn>, Option<DayFn>) {
    match day {
        3 => (Some(day03::part1), Some(day03::part2)),
        4 => (Some(day04::part1), Some(day04::part2)),
        5 => (Some(day05::part1), Some(day05::part2)),
        _ => (None, None),
    }
}

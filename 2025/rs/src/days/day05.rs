use std::{
    cmp::{max, min},
    fmt::Debug,
    str::Lines,
};

#[derive(Clone)]
struct Interval {
    start: u64,
    end: u64,
}

impl Interval {
    fn intersects(&self, other: &Self) -> bool {
        other.start <= self.end && other.end >= self.start
    }

    fn merge(&self, other: &Self) -> Option<Interval> {
        if self.intersects(other) {
            Some(Interval {
                start: min(self.start, other.start),
                end: max(self.end, other.end),
            })
        } else {
            None
        }
    }

    fn contains(&self, x: u64) -> bool {
        x >= self.start && x <= self.end
    }

    fn len(&self) -> u64 {
        self.end - self.start + 1
    }
}

impl Debug for Interval {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "[{}, {}]", self.start, self.end)
    }
}

pub fn part1(input: &str) -> i64 {
    let mut lines = input.lines();
    let intervals = parse_input_to_merged_intervals(&mut lines);

    let mut fresh = 0;
    while let Some(line) = lines.next() {
        let num: u64 = line.parse().unwrap();

        // could do binary search here but this is fast enough because of the merged intervals
        if intervals.iter().any(|interval| interval.contains(num)) {
            fresh += 1
        }
    }

    fresh
}

pub fn part2(input: &str) -> i64 {
    // can just sum the merged interval lengths because they have no overlap
    parse_input_to_merged_intervals(&mut input.lines())
        .iter()
        .map(Interval::len)
        .sum::<u64>() as i64
}

fn parse_input_to_merged_intervals(lines: &mut Lines) -> Vec<Interval> {
    let mut intervals = vec![];

    while let Some(line) = lines.next()
        && !line.is_empty()
    {
        let (from, to) = line.split_once('-').unwrap();
        let from: u64 = from.parse().unwrap();
        let to: u64 = to.parse().unwrap();
        intervals.push(Interval {
            start: from,
            end: to,
        });
    }

    // sort intervals by start and greedily merge them together to minimize the amount of intervals
    intervals.sort_by_key(|i| i.start);

    let mut merged_intervals = vec![];
    let mut i = 0;
    let n = intervals.len() - 1;
    while i < n {
        let mut current = intervals[i].clone();

        while i < n
            && let Some(merged) = current.merge(&intervals[i + 1])
        {
            current = merged;
            i += 1;
        }

        merged_intervals.push(current);
        i += 1;
    }

    merged_intervals
}

pub fn part1(input: &str) -> i64 {
    let lines: Vec<&str> = input.lines().collect();
    let mut sum = 0;

    for line in lines {
        let n = line.len();
        let (max1, i_max1) = find_max_digit(&line[..=n - 2]);
        let (max2, _) = find_max_digit(&line[i_max1 + 1..]);

        sum += 10 * max1 + max2;
    }

    sum.try_into().unwrap()
}

pub fn part2(input: &str) -> i64 {
    let lines: Vec<&str> = input.lines().collect();
    let mut sum = 0;

    for line in lines {
        let mut w_start = 0;
        let mut w_end = line.len() - 12 + 1;
        let mut i = 0;

        while i < 12 {
            let (max, i_max) = find_max_digit(&line[w_start..w_end]);
            w_start += i_max + 1;
            w_end += 1;

            sum += max * (10 as u64).pow(11 - i);
            i += 1;
        }
    }

    sum.try_into().unwrap()
}

fn find_max_digit(digits: &str) -> (u64, usize) {
    let mut max = 0;
    let mut i_max = 0;
    for (i, c) in digits.chars().enumerate() {
        let digit = c.to_digit(10).unwrap();

        if digit > max {
            max = digit;
            i_max = i;
        }
    }

    (max.into(), i_max)
}

#[derive(PartialEq, Clone)]
enum Char {
    Paper,
    Empty,
}

pub fn part1(input: &str) -> i64 {
    let map = parse_input(input);

    let mut count = 0;
    for (y, row) in map.iter().enumerate() {
        for (x, cell) in row.iter().enumerate() {
            if *cell == Char::Paper && count_neighbors(&map, x, y) < 4 {
                count += 1;
            }
        }
    }

    count
}

pub fn part2(input: &str) -> i64 {
    let mut map = parse_input(input);
    let mut removed_total = 0;
    let mut removed = 0;

    loop {
        removed_total += removed;
        removed = 0;

        for y in 0..map.len() {
            for x in 0..map[y].len() {
                if map[y][x] == Char::Paper && count_neighbors(&map, x, y) < 4 {
                    removed += 1;
                    map[y][x] = Char::Empty;
                }
            }
        }

        if removed == 0 {
            break;
        }
    }

    removed_total
}

fn count_neighbors(map: &Vec<Vec<Char>>, x: usize, y: usize) -> u8 {
    let mut neighbors = 0;

    for dy in -1i64..=1 {
        for dx in -1i64..=1 {
            if dx == 0 && dy == 0 {
                continue;
            }

            let yy = y as i64 + dy;
            let xx = x as i64 + dx;

            if let Some(row) = map.get(yy as usize)
                && let Some(cell) = row.get(xx as usize)
                && *cell == Char::Paper
            {
                neighbors += 1;
            }
        }
    }

    neighbors
}

fn parse_input(input: &str) -> Vec<Vec<Char>> {
    let lines: Vec<&str> = input.lines().collect();

    let mut map: Vec<Vec<Char>> = Vec::new();
    for line in lines {
        let mut row: Vec<Char> = Vec::new();

        for char in line.chars() {
            row.push(match char {
                '@' => Char::Paper,
                '.' => Char::Empty,
                c => {
                    panic!("Unknown character {}", c)
                }
            })
        }
        map.push(row);
    }

    map
}

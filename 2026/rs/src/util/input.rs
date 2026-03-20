use crate::util::strings::leftpad;
use std::{fs, path::Path};

pub fn read_input(filename: String) -> String {
    fs::read_to_string(Path::new("inputs").join(filename)).expect("Could not read file")
}

pub fn input_for_day(day: u8) -> String {
    let filename = format!("day{}.txt", leftpad(&day.to_string(), 2));
    read_input(filename)
}

pub fn sample_for_day(day: u8) -> String {
    let filename = format!("day{}.sample.txt", leftpad(&day.to_string(), 2));
    read_input(filename)
}

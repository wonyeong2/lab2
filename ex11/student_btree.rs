use std::collections::BTreeMap;
use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut students = BTreeMap::new();

    println!("학생 수를 입력하세요: ");
    let student_num: i32 = stdin.lock().lines().next().unwrap().unwrap().parse().unwrap();

    for _ in 0..student_num {
        println!("학생 정보 입력(이름 중간 기말): ");
        let input = stdin.lock().lines().next().unwrap().unwrap();
        let mut input_iter = input.trim().split_whitespace();

        if let (Some(name), Some(mid_score), Some(final_score)) = (
            input_iter.next(),
            input_iter.next(),
            input_iter.next(),
        ) {
            let mid_score: i32 = mid_score.parse().unwrap();
            let final_score: i32 = final_score.parse().unwrap();
            students.insert(name.to_string(), (mid_score, final_score));
        } else {
            println!("잘못된 입력 형식입니다.");
        }
    }

    println!("학생 정보 출력:");
    for (name, (mid_score, final_score)) in &students {
        println!("이름 = {}, 중간 점수 = {}, 기말 점수 = {}", name, mid_score, final_score);
    }
}

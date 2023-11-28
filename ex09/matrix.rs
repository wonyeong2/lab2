use std::io::{self, Write, stdin};

fn main() -> io::Result<()> {
    let mut buffer = String::new();

    print!("행과 열을 입력하세요 (row,col): ");
    io::stdout().flush()?;

    stdin().read_line(&mut buffer)?;

    let vec: Vec<usize> = buffer.trim().split_whitespace()
                                .map(|x| x.parse::<usize>().unwrap())
                                .collect();

    let (row, col) = (vec[0], vec[1]);

    let mut first_matrix: Vec<Vec<i32>> = vec![vec![0; col]; row];
    let mut second_matrix: Vec<Vec<i32>> = vec![vec![0; col]; row];

   println!("첫 번째 행렬:");
   for i in 0..row {
       let mut input_string = String::new();
       stdin().read_line(&mut input_string)?;
       first_matrix[i] = input_string.trim().split_whitespace()
                                      .map(|x| x.parse::<i32>().unwrap())
                                      .collect();
   }

   println!("두 번째 행렬:");
   for i in 0..row {
       let mut input_string = String::new();
       stdin().read_line(&mut input_string)?;
       second_matrix[i] = input_string.trim().split_whitespace()
                                       .map(|x| x.parse::<i32>().unwrap())
                                       .collect();
   }

   println!("두 행렬을 더한 결과:");
   
   for i in 0..row {
       for j in 0..col {
           print!("{} ", first_matrix[i][j] + second_matrix[i][j]);
       }
       println!("");
   }

   Ok(())
}

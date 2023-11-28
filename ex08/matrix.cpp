#include <iostream>
#include <vector>

int main() {
    int row, col;

    std::cout << "행과 열을 입력하세요 (row, col) : ";
    std::cin >> row >> col;

    std::vector<std::vector<int>> first_matrix(row, std::vector<int>(col));
    std::vector<std::vector<int>> second_matrix(row, std::vector<int>(col));

    std::cout << "첫 번째 행렬 : \n";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            std::cin >> first_matrix[i][j];
        }
    }

    std::cout << "두 번째 행렬 : \n";
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            std::cin >> second_matrix[i][j];
        }
    }

    std::cout << "두 행렬을 더한 결과 : \n";
     for(int i=0; i<row; i++){
        for(int j=0;j<col;j++) {
            printf("%d ", first_matrix[i][j] + second_matrix[i][j]);
        }
         printf("\n");
     }

     return 0;
}

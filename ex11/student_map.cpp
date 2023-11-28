#include <iostream>
#include <map>
#include <string>

struct Student {
    std::string name;
    int mid_score;
    int final_score;
};

int main() {
    std::map<std::string, Student> students;

    int student_num = 0; 
    std::cout << "학생 수를 입력하세요 : ";
    std::cin >> student_num;

    for(int i = 0; i < student_num; i++) {
        Student s;
        std::cout << "학생 정보 입력(이름, 중간, 기말) : ";
        std::cin >> s.name >> s.mid_score >> s.final_score;

        students[s.name] = s;
        std::cout << "학생 추가 완료\n";
    }

    for(auto& pair : students) {
        const Student& s = pair.second;
        std::cout << "이름 = " << s.name 
                  << ", 중간 점수 = " << s.mid_score 
                  << ", 기말 점수 = " << s.final_score
                  << "\n";
    }

}

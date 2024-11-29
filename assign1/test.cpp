#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";

struct Course {
  /* STUDENT TODO */std::string title;
  /* STUDENT TODO */int number_of_units;
  /* STUDENT TODO */std::string quarter;
};

#include "utils.cpp"

void parse_csv(std::string filename, std::vector<Course> &courses) {
  // 创建文件流
  std::ifstream ifs(filename);
  std::string course;
  // 获取标题行
  getline(ifs, course);
  // 临时存储分词后的数据
  std::vector<std::string> c;
  // 用于类型转换
  std::stringstream ss;
  int num;

  while(getline(ifs, course)) {
    c = split(course, ',');
    Course cou; //临时结构体
    cou.title = c[0];
    ss << c[1];
    ss >> num;
    cou.number_of_units = num;
    cou.quarter = c[2];
    courses.push_back(cou);
    // std::cout << c[0] << c[1] << c[2];
  }

}



int main() {
    std::string filename = "courses.csv";
    std::vector<Course> courses;
    parse_csv(filename, courses);
    for (auto& line : courses) {
        std::cout << line.title << '\n';
    }
    return 0;
}
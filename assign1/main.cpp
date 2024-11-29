/*
 * CS106L Assignment 1: SimpleEnroll
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 *
 * Welcome to Assignment 1 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 * Students must implement: parse_csv, write_courses_offered,
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";
const std::string n = "null";

/**
 * Represents a course a student can take in ExploreCourses.
 * You must fill in the types of the fields in this struct.
 * Hint: Remember what types C++ streams work with?!
 * 回想一下 C++ 流（streams）通常处理的数据类型。
 */
struct Course {
  /* STUDENT TODO */std::string title;
  /* STUDENT TODO */std::string number_of_units;
  /* STUDENT TODO */std::string quarter;
};

/**
 * (STUDENT TODO) Look at how the main function (at the bottom of this file)
 * calls `parse_csv`, `write_courses_offered`, and `write_courses_not_offered`.
 * Modify the signatures of these functions so that they work as intended, and then delete this
 * comment!
 */

/**
 * Note:
 * We need to #include utils.cpp _after_ we declare the Course struct above
 * so that the code inside utils.cpp knows what a Course is.
 * Recall that #include literally copies and pastes file contents.
 */
#include "utils.cpp"

/**
 * 这个函数应该用 `Course` 类型的结构体填充 `courses` 向量。我们希望用 courses.csv 文件中的记录来创建这些结构体，其中每一行都是一条记录！
 *
 * 提示：
 * 1) 看看我们在 utils.cpp 中提供的 split 函数
 * 2) 每一行都是一条记录！*这很重要，所以我们再说一遍 :>)*
 * 3) CSV 文件的第一行定义了列名，所以你可以忽略它！
 *
 * @param filename 要解析的文件名。
 * @param courses  要填充的课程向量。
 */
void parse_csv(std::string filename, std::vector<Course> &courses) {
  // 创建文件流
  std::ifstream ifs(filename);
  std::string course;
  std::string first_line;
  // 获取标题行
  getline(ifs, first_line);
  // 临时存储分词后的数据
  std::vector<std::string> c;

  // // 用于类型转换
  // std::stringstream ss;
  // int num;

  while(getline(ifs, course)) {
    c = split(course, ',');
    Course cou; //临时结构体
    cou.title = c[0];
    // ss << c[1];
    // ss >> num;
    cou.number_of_units = c[1];
    cou.quarter = c[2];
    courses.push_back(cou);
    // std::cout << c[0] << c[1] << c[2];
  }

}

/**
 * 这个函数有两个要求。
 *
 * 1) 将提供的课程写入文件 "student_output/courses_offered.csv"
 *
 * 2) 从 `all_courses` 向量中删除提供的课程。
 * 重要提示：在写入文件后执行此操作！
 *
 * 提示：
 * 1) 记录需要删除的课程！
 * 2) 使用我们提供的 delete_elem_from_vector 函数！
 * 3) 记得在输出的 CSV 文件开头写入列标题！
 *    参考 courses.csv 文件。
 *
 * @param all_courses 通过调用 `parse_csv` 获得的所有课程的向量。
 *                    这个向量将通过删除所有提供的课程进行修改。
 */
void write_courses_offered(std::vector<Course> &all_courses) {

  //创建输入文件流
  std::string filename = "courses.csv";
  std::ifstream ifs(filename);
  std::string first_line;
  //获取标题行
  getline(ifs, first_line);
  ifs.close();

  // std::vector<Course> courses;
  // parse_csv(filename, courses);
  std::vector<Course> course_null;


  for (auto line : all_courses) {
      if(line.quarter == n) {
        course_null.push_back(line);
      }
    }
  
  for (auto line : course_null) {
    delete_elem_from_vector(all_courses, line);
  }

  //创建输出文件流
  std::ofstream ofs(COURSES_OFFERED_PATH);
  if (ofs.is_open()) {
    ofs << first_line << '\n';
    for (auto line : all_courses) {
      ofs << line.title << ',' << line.number_of_units << ',' << line.quarter << '\n';
    }
  }

  all_courses = course_null;
  
  ofs.close();

  
}

/**
 * 这个函数将未提供的课程写入文件 "student_output/courses_not_offered.csv"。
 *
 * 这个函数总是在 `write_courses_offered` 函数之后调用。
 * `unlisted_courses` 将显然包含未提供的课程，因为你在 `write_courses_offered` 函数中删除了提供的课程。
 *
 * 提示：这应该与 `write_courses_offered` 非常相似。
 *
 * @param unlisted_courses 一个包含未提供课程的向量。
 */
void write_courses_not_offered(std::vector<Course> unlisted_courses) {

  //创建输入文件流
  std::string filename = "courses.csv";
  std::ifstream ifs(filename);
  std::string first_line;
  //获取标题行
  getline(ifs, first_line);

  ifs.close();

  //创建输出文件流
  std::ofstream ofs(COURSES_NOT_OFFERED_PATH);
  if (ofs.is_open()) {
    ofs << first_line << '\n';
    for (auto line : unlisted_courses) {
      ofs << line.title << ',' << line.number_of_units << ',' << line.quarter << '\n';
    }
  }

  ofs.close();

}

int main() {
  /* Makes sure you defined your Course struct correctly! */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* Uncomment for debugging... */
  // print_courses(courses);

  write_courses_offered(courses);
  
  // print_courses(courses);

  write_courses_not_offered(courses);

  return run_autograder();
}
/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

#include "utils.h"

std::string kYourName = "Zhang Bowen"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream ifs("students.txt");
  std::string line;
  std::unordered_set<std::string> name;
  if (ifs.is_open()) {
    // std::cout << "open" << std::endl;
    while (getline(ifs, line)) {
      // std::cout << line << std::endl;
      name.insert(line);
    }
  }
  // std::cout << *name.begin() <<std::endl;
  return name;
}

/**
 * 接受一个学生名字的集合，并返回一个包含匹配名字的队列。
 *
 * @param name      返回的名字队列应该与这个名字有相同的首字母。
 * @param students  学生名字的集合。
 * @return          一个包含每个匹配名字指针的队列。
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> q;
  // std::cout << students.empty() << std::endl;
  std::stringstream sname(name);
  std::string name_first, name_second;
  std::string student_first, student_second;
  sname >> name_first >> name_second;
  for(auto& student : students) {
      // std::cout << student <<".."<< std::endl;
      std::stringstream ss(student);
      ss >> student_first >> student_second;
      if(name_first[0] == student_first[0] && name_second[0] == student_second[0]){
        // std::cout << student << std::endl;
        q.push(&student);
      }
  }
  //std::cout << *q.front() << std::endl;

  return q;
}

/**
 * 接受一个指向可能匹配项的指针队列，并确定唯一的真爱！
 *
 * 你可以随意实现这个函数，但尝试做一些比简单的 `pop()` 更复杂的事情。
 *
 * @param matches 可能匹配项的队列。
 * @return        你神奇的唯一真爱。
 *                如果 `matches` 为空，将返回 "NO MATCHES FOUND."。
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.empty()) {
    std::cout << "yesss" << std::endl;
    return  "NO STUDENT FOUND.";
  }

  // 获取队列中的第一个元素
  const std::string* name_ptr = matches.front();
  std::string name = *name_ptr;
  std::cout << name << std::endl;

  return name;
}

/* #### Please don't modify this call to the autograder! #### */
int main() { return run_autograder(); }

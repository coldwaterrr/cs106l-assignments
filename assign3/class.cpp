#include "class.h"
#include <string>
#include <iostream>

Student::Student(std::string name, std::string sno, int age) {
    this->name = name;
    this->sno = sno;
    this->age = age;
}

int Student::getAge() {
    return this->age;
}

std::string Student::getName() {
    return this->name;
}

std::string Student::getSno() {
    return this->sno;
}

void Student::setAge(int age) {
    this->age = age;
}



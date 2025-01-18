/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include<iostream>

/* #### Please don't change this line! #### */
int run_autograder();

int main() {
  // STUDENT TODO: Construct an instance of your class!
    Student s1{"zbw","101",24};
    std::cout << s1.getAge() << std::endl;
    std::cout << s1.getName() << std::endl;
    std::cout << s1.getSno() << std::endl;
    s1.setAge(25);
    std::cout << s1.getAge() << std::endl;
    return 0;

  /* #### Please don't change this line! #### */
  return run_autograder();
}

/* #### Please don't change this line! #### */
#include "utils.hpp"
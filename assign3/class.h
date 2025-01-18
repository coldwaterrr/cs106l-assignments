#include<string>

class Student{
    private:
    std::string name;
    int age;
    std::string sno;
    void getall();

    public:
    int getAge();
    Student(std::string name, std::string sno, int age = 18);
    // Student();
    std::string getName();
    std::string getSno();
    void setAge(int age);
    void getAll(){getall();};
};
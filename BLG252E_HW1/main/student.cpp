#include <iostream>
#include "student.h"

Student::Student() : s_name(""), s_GPA(0), s_GRE(0), s_TOEFL(0), number_of_applications(0)
{
    std::cout << "Unnamed logged in to the system." << std::endl;
}; // default constructor

Student::Student(std::string name, double GPA, double GRE, double TOEFL, int number_of_applications)
{
    this->s_name = name;
    this->s_GPA = GPA;
    this->s_GRE = GRE;
    this->s_TOEFL = TOEFL;
    this->number_of_applications = number_of_applications;
    std::cout << this->s_name << " logged in to the system." << std::endl;
}; // constructor with parameters

Student::Student(std::string name, double GPA, double GRE, double TOEFL)
{
    this->s_name = name;
    this->s_GPA = GPA;
    this->s_GRE = GRE;
    this->s_TOEFL = TOEFL;
    this->number_of_applications = 0;
    std::cout << this->s_name << " logged in to the system." << std::endl;
}; // constructor with parameters

Student::Student(const Student& student) : s_name(student.s_name), s_GPA(student.s_GPA), s_GRE(student.s_GRE), s_TOEFL(student.s_TOEFL), number_of_applications(student.number_of_applications)
{
    std::cout << this->s_name << " logged in to the system." << std::endl;
}; // copy constructor

Student::~Student()
{
    std::cout << this->s_name << " logged out of the system with " << this->number_of_applications << " application(s)." << std::endl;
}; // destructor

std::string Student::get_s_name() const{
    return this->s_name;
}
void Student::set_name(std::string name)
{
    this->s_name = name;
};

double Student::get_s_GPA() const{
    return this->s_GPA;
}
void Student::set_s_GPA(double GPA) {
    this->s_GPA = GPA;
}

double Student::get_s_GRE() const{
    return this->s_GRE;
}
void Student::set_s_GRE(double GRE) {
    this->s_GRE = GRE;
}

double Student::get_s_TOEFL() const{
    return this->s_TOEFL;
}
void Student::set_s_TOEFL(double TOEFL) {
    this->s_TOEFL = TOEFL;
}

int Student::get_number_of_applications() const{
    return this->number_of_applications;
}
void Student::set_number_of_applications(int number_of_applications) {
    this->number_of_applications = number_of_applications;
}
void Student::set_number_of_applications(int number_of_applications) const{
    this->number_of_applications = number_of_applications;
}
#include <iostream>
#include <random>
#include "university.h"


University::University() : u_name(""), u_GPA(rand()), u_GRE(rand()), u_TOEFL(rand()), u_bias(rand()), u_country("") {};
// default constructor

University::University(std::string name, double GPA, double GRE, double TOEFL, double bias)
{
    this->u_name = std::string(name);
    this->u_GPA = GPA;
    this->u_GRE = GRE;
    this->u_TOEFL = TOEFL;
    this->u_bias = bias;
    this->u_country = "";
}; // constructor with parameters country is not specified

University::University(std::string name, double GPA, double GRE, double TOEFL, double bias, std::string country)
{
    this->u_name = std::string(name);
    this->u_GPA = GPA;
    this->u_GRE = GRE;
    this->u_TOEFL = TOEFL;
    this->u_bias = bias;
    this->u_country = std::string(country);
}; // constructor with parameters

const void University::evaluate_student(const Student& student)
{
    int z;
    z = this->u_GPA * student.get_s_GPA() + this->u_GRE * student.get_s_GRE() + this->u_TOEFL * student.get_s_TOEFL() + this->u_bias;
    if (z > 0)
    {
        std::cout << student.get_s_name() << " is admitted to " << this->u_name << "." << std::endl;
    }
    else
    {
        std::cout << student.get_s_name() << " is rejected from " << this->u_name << "." << std::endl;
    }
    student.set_number_of_applications(student.get_number_of_applications()+1);
}
void University::evaluate_student(Student& student)
{
    int z;
    z = this->u_GPA * student.get_s_GPA() + this->u_GRE * student.get_s_GRE() + this->u_TOEFL * student.get_s_TOEFL() + this->u_bias;
    if (z > 0)
    {
        std::cout << student.get_s_name() << " is admitted to " << this->u_name << "." << std::endl;
    }
    else
    {
        std::cout << student.get_s_name() << " is rejected from " << this->u_name << "." << std::endl;
    }
    student.set_number_of_applications(student.get_number_of_applications()+1);
}
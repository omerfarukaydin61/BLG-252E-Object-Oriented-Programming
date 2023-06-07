#pragma once
#include <string>
#include <iostream>
#include "student.h"

class University
{
public:
    University();                                                                                         // default constructor
    University(std::string name, double GPA, double GRE, double TOEFL, double bias);                      // constructor with parameters country is not specified
    University(std::string name, double GPA, double GRE, double TOEFL, double bias, std::string country); // constructor with parameters
    void const evaluate_student(const Student& student);
    void evaluate_student(Student& student);

private:
    std::string u_name;    // name of the university
    double u_GPA;          // GPA requirement
    double u_GRE;          // GRE requirement
    double u_TOEFL;        // TOEFL requirement
    double u_bias;         // bias of the university
    std::string u_country; // country of the university
};
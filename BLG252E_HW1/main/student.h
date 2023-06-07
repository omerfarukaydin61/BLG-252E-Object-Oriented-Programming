#pragma once
#include <string>

class Student
{
public:
    Student();                                                                                   // default constructor
    Student(std::string name, double GPA, double GRE, double TOEFL, int number_of_applications); // constructor with parameters
    Student(std::string name, double GPA, double GRE, double TOEFL);
    Student(const Student& student);                                                             // copy constructor
    ~Student();                                                                                  // destructor

    std::string get_s_name() const;
    void set_name(std::string name);

    double get_s_GPA() const;
    void set_s_GPA(double GPA);

    double get_s_GRE() const;
    void set_s_GRE(double GRE);

    double get_s_TOEFL() const;
    void set_s_TOEFL(double TOEFL);

    int get_number_of_applications() const;
    void set_number_of_applications(int number_of_applications);
    void set_number_of_applications(int number_of_applications) const;

private:
    mutable std::string s_name;         // name of the student
    double s_GPA;                       // GPA of the student
    double s_GRE;                       // GRE of the student
    double s_TOEFL;                     // TOEFL of the student
    mutable int number_of_applications; // number of applications of the student
};
#ifndef DSA3_STUDENT_H
#define DSA3_STUDENT_H

#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    int id;
    string name;
    double gpa;
    string department;

public:
    Student(int id, string name, double gpa, string department)
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->department = department;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    {
        return this->id;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void setGpa(double gpa)
    {
        this->gpa = gpa;
    }

    double getGpa()
    {
        return this->gpa;
    }

    void setDepartment(string department)
    {
        this->department = department;
    }

    string getDepartment()
    {
        return this->department;
    }

    friend ostream& operator<<(ostream& out, Student& student);

    friend istream& operator>>(istream &in, Student& student);

};

istream& operator>>(istream &in, Student& student) {
    int id;
    string name;
    double gpa;
    string department;

    in >> id;
    in.ignore(); // ignore the newline character after id
    getline(in, name);
    in >> gpa;
    in.ignore(); // ignore the newline character after gpa
    getline(in, department);

    student.setId(id);
    student.setName(name);
    student.setGpa(gpa);
    student.setDepartment(department);

    return in;
}

ostream& operator<<(ostream &out, Student& student) {
    out << "ID: " << student.getId() << endl;
    out << "Name: " << student.getName() << endl;
    out << "GPA: " << student.getGpa() << endl;
    out << "Department: " << student.getDepartment() << endl;
    out << "===========================================================\n";
    return out;
}


#endif //DSA3_STUDENT_H

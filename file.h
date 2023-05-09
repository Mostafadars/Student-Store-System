#ifndef STUDENT_H_FILE_H
#define STUDENT_H_FILE_H

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;

void readStudentsDataFromFile(string fileName, vector<Student>& students)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }

    int numStudents;
    file >> numStudents;

    for (int i = 0; i < numStudents; i++)
    {
        int id;
        string name;
        double gpa;
        string department;

        //file >> id >> name >> gpa >> department;
        file >> id;
        file.ignore(); // ignore the newline character after id
        getline(file, name);
        file >> gpa;
        file.ignore(); // ignore the newline character after gpa
        getline(file, department);

        students.push_back(Student(id, name, gpa, department));
    }

    file.close();
}


#endif //STUDENT_H_FILE_H

#ifndef STUDENT_H_MENUS_H
#define STUDENT_H_MENUS_H

#include <bits/stdc++.h>
#include "file.h"
#include "BST.h"
using namespace std;

int getUserChoice(int minChoice, int maxChoice) {
    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < minChoice || choice > maxChoice) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice < minChoice || choice > maxChoice);
    return choice;
}

void BSTMenu()
{
    int choose;
    cout << "##=============================================================================================##" << endl;
    cout << "\t\t\tStudent Store App With BST\t\t\t" << endl;
    cout << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Remove student" << endl;
    cout << "3. Search student" << endl;
    cout << "4. Print All (sorted by id)" << endl;
    cout << "5. Show Departments Report" << endl;
    cout << "6. Return to main menu" << endl;
    cout << "##=============================================================================================##" << endl;

    // cin >> choose;

    vector<Student> students;
    readStudentsDataFromFile("StudentsFile.txt", students);
    BST BinarySearchTree;

    for (int i = 0; i < students.size(); i++)
    {
        BinarySearchTree.add(students[i].getId(), students[i]);
    }

    while (cin >> choose && choose != 6)
    {
        if (choose == 1)
        {
            Student student(0, " ", 0.0, " ");
            cout << "Enter Student Data As Follow : (ID) (Name) (GPA) (Department)" << endl;
            cin >> student;
            BinarySearchTree.add(student.getId(), student);
            cout << "Student Added Successfully !" << endl;
        }
        else if (choose == 2)
        {
            int id;
            cout << "Enter Student ID That You Want to Remove It : " << endl;
            cin >> id;
            BinarySearchTree.remove(id);
            cout << "Student Removed Successfully !" << endl;
        }
        else if (choose == 3)
        {
            int id;
            cout << "Enter Student ID That You Want to Search About It : " << endl;
            cin >> id;
            BinarySearchTree.search(id);
        }
        else if (choose == 4)
        {
            BinarySearchTree.printAll();
        }
        else if (choose == 5)
        {
            cout << "Departments Report : " << endl;
            BinarySearchTree.departmentReport();
        }
    }
}

void AVLMenu()
{

}

void MinHeapMenu()
{

}

void MaxHeapMenu()
{

}

void MainMenu()
{
    int choose;
    cout << "##=============================================================================================##" << endl;
    cout << "\t\t\tHello In Student Store App With Data Structures\t\t\t" << endl;
    cout << endl;
    cout << "Choose Data Structure:" << endl;
    cout << "1. BST" << endl;
    cout << "2. AVL" << endl;
    cout << "3. Min Heap" << endl;
    cout << "4. Max Heap" << endl;
    cout << "5. Exit" << endl;
    cout << "##=============================================================================================##" << endl;

    cin >> choose;

    if (choose == 1)
        BSTMenu();
    else if (choose == 2)
        AVLMenu();
    else if (choose == 3)
        MinHeapMenu();
    else if (choose == 4)
        MaxHeapMenu();
    else
        return;
}

void mainMenu()
{
    int choice;
    do {
        cout << "##=============================================================================================##" << endl;
        cout << "\t\t\tHello In Student Store App With Data Structures\t\t\t" << endl;
        cout << endl;
        cout << "Choose Data Structure:" << endl;
        cout << "1. BST" << endl;
        cout << "2. AVL" << endl;
        cout << "3. Min Heap" << endl;
        cout << "4. Max Heap" << endl;
        cout << "5. Exit" << endl;
        cout << "##=============================================================================================##" << endl;
        choice = getUserChoice(1, 5);

        switch (choice) {
            case 1:
                BSTMenu();
                break;
            case 2:
                AVLMenu();
                break;
            case 3:
                MinHeapMenu();
                break;
            case 4:
                MaxHeapMenu();
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 2);
}

#endif //STUDENT_H_MENUS_H

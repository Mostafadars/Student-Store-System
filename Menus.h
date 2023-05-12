#ifndef STUDENT_H_MENUS_H
#define STUDENT_H_MENUS_H

#include <bits/stdc++.h>
#include "file.h"
#include "BST.h"
#include "AVL.h"
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
    vector<Student> students;
    readStudentsDataFromFile("StudentsFile.txt", students);
    BST BinarySearchTree;
    for (int i = 0; i < students.size(); i++)
    {
        BinarySearchTree.add(students[i].getId(), students[i]);
    }

    int choice;

    do {
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
        choice = getUserChoice(1, 6);

        if (choice == 1)
        {
            Student student(0, " ", 0.0, " ");
            cout << "Enter Student Data As Follow : (ID) (Name) (GPA) (Department)" << endl;
            cin >> student;
            BinarySearchTree.add(student.getId(), student);
            cout << "Student Added Successfully !" << endl;
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter Student ID That You Want to Remove It : " << endl;
            cin >> id;
            BinarySearchTree.remove(id);
            cout << "Student Removed Successfully !" << endl;
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Student ID That You Want to Search About It : " << endl;
            cin >> id;
            BinarySearchTree.search(id);
        }
        else if (choice == 4)
        {
            BinarySearchTree.printAll();
        }
        else if (choice == 5)
        {
            cout << "Departments Report : " << endl;
            BinarySearchTree.departmentReport();
        }
        else
        {
            cout << "Returning to main menu..." << endl;
            break;
        }
    } while (choice != 6);
}

void AVLMenu()
{
  vector<Student> students;
  readStudentsDataFromFile("StudentsFile.txt", students);
  AVL AVLtree;
  for (int i = 0; i < students.size(); i++)
  {
    AVLtree.insert_value(students[i].getId(), students[i]);
  }

  int choice;

  do {
    cout << "##=============================================================================================##" << endl;
    cout << "\t\t\tStudent Store App With AVL\t\t\t" << endl;
    cout << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Remove student" << endl;
    cout << "3. Search student" << endl;
    cout << "4. Print All (sorted by id)" << endl;
    cout << "5. Show Departments Report" << endl;
    cout << "6. Return to main menu" << endl;
    cout << "##=============================================================================================##" << endl;
    choice = getUserChoice(1, 6);

    if (choice == 1)
    {
      Student student(0, " ", 0.0, " ");
      cout << "Enter Student Data As Follow : (ID) (Name) (GPA) (Department)" << endl;
      cin >> student;
      AVLtree.insert_value(student.getId(), student);
      cout << "Student Added Successfully !" << endl;
    }
    else if (choice == 2)
    {
      int id;
      cout << "Enter Student ID That You Want to Remove It : " << endl;
      cin >> id;
      AVLtree.delete_value(id);
      cout << "Student Removed Successfully !" << endl;
    }
    else if(choice == 3){
      int id ;
      cout << "id: ";
      cin >> id;
      AVLtree.search(id);
    }
    else if (choice == 4){
      AVLtree.print_inorder();
    }
    else if(choice == 5)
      AVLtree.departmentreprot();
    else if(choice == 6)
      break;
  }while(true);

}

void MinHeapMenu()
{

}

void MaxHeapMenu()
{

}

void MainMenu()
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
    } while (choice != 5);
}

#endif //STUDENT_H_MENUS_H

#ifndef MAIN_CPP_BST_H
#define MAIN_CPP_BST_H

#include <bits/stdc++.h>
#include "Student.h"
using namespace std;


struct Node {
    int id;
    Student student;
    Node* left;
    Node* right;
    Node(int id, Student student) : id(id), student(student), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node *root;
    int size;

    void add(Node *&cur, int id, Student student) {
        if (cur == nullptr) {
            cur = new Node(id, student);
            size++;
            return;
        }
        if (id < cur->id) {
            add(cur->left, id, student);
        } else {
            add(cur->right, id, student);
        }
    }

    Node *remove(Node *&cur, int id) {
        if (cur == nullptr) {
            return nullptr;
        }
        if (id < cur->id) {
            cur->left = remove(cur->left, id);
        } else if (id > cur->id) {
            cur->right = remove(cur->right, id);
        } else {
            if (cur->left == nullptr) {
                Node *temp = cur->right;
                delete cur;
                cur = temp;
                size--;
            } else if (cur->right == nullptr) {
                Node *temp = cur->left;
                delete cur;
                cur = temp;
                size--;
            } else {
                Node *temp = findMin(cur->right);
                cur->id = temp->id;
                cur->student = temp->student;
                cur->right = remove(cur->right, temp->id);
            }
        }
        return cur;
    }

    Node *find(Node *cur, int id) {
        if (cur == nullptr || cur->id == id) {
            return cur;
        }
        if (id < cur->id) {
            return find(cur->left, id);
        } else {
            return find(cur->right, id);
        }
    }

    Node *findMin(Node *cur) {
        while (cur->left != nullptr) {
            cur = cur->left;
        }
        return cur;
    }

    void printAll(Node *cur) {
        if (cur == nullptr) {
            return;
        }
        printAll(cur->left);
        cout << cur->student << endl;
        printAll(cur->right);
    }

    void departmentReport(Node *cur, string department, int &count) {
        if (cur == nullptr) {
            return;
        }
        departmentReport(cur->left, department, count);
        if (cur->student.getDepartment() == department) {
            count++;
        }
        departmentReport(cur->right, department, count);
    }

public:
    BST() : root(nullptr), size(0) {}

    void add(int id, Student student) {
        add(root, id, student);
    }

    void remove(int id) {
        remove(root, id);
    }

    void search(int id) {
        Node *result = find(root, id);
        if (result == nullptr) {
            cout << "Student with ID " << id << " not found." << endl;
        } else {
            cout << result->student << endl;
        }
    }

    void printAll() {
        cout << "Printing all students:" << endl;
        printAll(root);
    }

    void departmentReport() {
        int count = 0;
        departmentReport(root, "CS", count);
        cout << "There are " << count << " students in the CS" << endl;
        count = 0;
        departmentReport(root, "IS", count);
        cout << "There are " << count << " students in the IS" << endl;
        count = 0;
        departmentReport(root, "IT", count);
        cout << "There are " << count << " students in the IT" << endl;
        count = 0;
        departmentReport(root, "DS", count);
        cout << "There are " << count << " students in the DS" << endl;

    }
};

#endif //MAIN_CPP_BST_H

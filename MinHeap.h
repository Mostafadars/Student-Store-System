#ifndef STUDENT_H_MINHEAP_H
#define STUDENT_H_MINHEAP_H

#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include "Student.h"
#include "file.h"
using namespace std;


class MinHeap
{
private:
    vector<Student> heap;

    int getParentIndex(int childIndex) {
        return (childIndex - 1) / 2;
    }

    int getLeftChildIndex(int parentIndex) {
        return (2 * parentIndex) + 1;
    }

    int getRightChildIndex(int parentIndex) {
        return (2 * parentIndex) + 2;
    }

    void heapifyUp(int index) {
        int parentIndex = getParentIndex(index);
        if (parentIndex >= 0 && heap[index].getGpa() < heap[parentIndex].getGpa()) {
            swap(heap[index], heap[parentIndex]);
            heapifyUp(parentIndex);
        }
    }

    void heapifyDown(int index) {
        int leftChildIndex = getLeftChildIndex(index);
        int rightChildIndex = getRightChildIndex(index);
        int smallestIndex = index;

        if (leftChildIndex < heap.size() && heap[leftChildIndex].getGpa() < heap[smallestIndex].getGpa()) {
            smallestIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex].getGpa() < heap[smallestIndex].getGpa()) {
            smallestIndex = rightChildIndex;
        }

        if (smallestIndex != index) {
            swap(heap[index], heap[smallestIndex]);
            heapifyDown(smallestIndex);
        }
    }

public:
    void addStudent(const Student &student) {
        heap.push_back(student);
        heapifyUp(heap.size() - 1);
    }

    void removeStudent(int id) {
        int index = -1;
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i].getId() == id) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }

        swap(heap[index], heap[heap.size() - 1]);
        heap.pop_back();

        if (index < heap.size()) {
            heapifyUp(index);
            heapifyDown(index);
        }
    }

    void searchStudent(int id)
    {
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i].getId() == id)
            {
                cout << heap[i] << endl;
                return;
            }
        }
        cout << "Student Dose Not Exist!" << endl;
    }

    void printAll()
    {
        if (heap.empty())
        {
            cout << "No students in the heap." << endl;
            return;
        }

        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << endl;
        }
    }

    void printDepartmentReport()
    {
        unordered_map<string, int> departmentCount;
        for (Student student : heap)
        {
            departmentCount[student.getDepartment()]++;
        }

        for (const auto& entry : departmentCount)
        {
            cout << "Department: " << entry.first << ", Count: " << entry.second << endl;
        }
    }
};

#endif //STUDENT_H_MINHEAP_H

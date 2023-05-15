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

        /*
        if (smallestIndex != index) { // this condition is always false it must be deleted
            swap(heap[index], heap[smallestIndex]);
            heapifyDown(smallestIndex);
        }*/
    }

public:
    void addStudent(const Student &student) {
        heap.push_back(student);
        heapifyUp(heap.size() - 1);
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

};

#endif //STUDENT_H_MINHEAP_H

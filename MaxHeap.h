#ifndef DSA3_MAXHEAP_H
#define DSA3_MAXHEAP_H
#include<iostream>
#include "Student.h"
using namespace std;

class MaxHeap
{
 private:
  vector<Student> data;

  int getParentIndex(int childIndex) {
    int result = (childIndex - 1) / 2;
    return result >= 0 ? result : -1;
  }

  void heapifyUp(int index) {
    int parentIndex = getParentIndex(index);
    if (parentIndex != -1 && data[index].getGpa() > data[parentIndex].getGpa()) {
      swap(data[index], data[parentIndex]);
      heapifyUp(parentIndex);
    }
  }

 public:
  void addStudent(const Student &student) {
    data.push_back(student);
    heapifyUp(data.size() - 1);
  }


  void printAll()
  {
    if (data.empty())
    {
      cout << "No students in the data." << endl;
      return;
    }

    for (int i = 0; i < data.size(); i++)
    {
      cout << data[i] << endl;
    }
  }

};

#endif //DSA3_MAXHEAP_H

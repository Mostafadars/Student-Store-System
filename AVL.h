//
// Created by hp on 5/12/2023.
//


#ifndef MENUS_H_AVL_H
#define MENUS_H_AVL_H
#include <iostream>
#include <queue>
#include <set>
#include "Student.h"
using namespace std;
class AVL {
 private:
  struct BinaryNode {
      int ID { };
      int height { };
      Student* info { };
      BinaryNode* left { };
      BinaryNode* right { };

      BinaryNode(int id , Student student) : ID(id){
        info = new Student(student.getId(),student.getName(),student.getGpa(),student.getDepartment());
      }
  };

  BinaryNode *root { };

  void report_departments(BinaryNode* node){
    if(!node)
      return;
    map<string,int> departments;
    fill(node,departments);
    cout << "Departments Report :\n";
    for(auto a : departments){
      cout << "There are " << a.second << " in the " << a.first << " department\n";
    }
  }
  void fill(BinaryNode* node, map<string,int> &qu){
    if(!node)
      return;
    fill(node->left,qu);
    if(qu[node->info->getDepartment()])
      qu[node->info->getDepartment()]++;
    else
      qu[node->info->getDepartment()] = 1;
    fill(node->right,qu);
  }
  ///////////////////////////
  bool search(int target, BinaryNode* node) {
    if(!node)
      return false;

    if (target == node->ID){
      cout << *node->info;
      return true;
    }

    if (target < node->ID)
      return search(target, node->left);

    return search(target, node->right);
  }

  void insert_node(int target, BinaryNode* node , Student info) {
    if (target < node->ID) {
      if (!node->left)
        node->left = new BinaryNode(target,info);
      else
        insert_node(target, node->left,info);
    } else if (target > node->ID) {
      if (!node->right)
        node->right = new BinaryNode(target,info);
      else
        insert_node(target, node->right,info);
    }
    update_height(node);
  }


  BinaryNode* min_node(BinaryNode* cur) {
    while (cur && cur->left)
      cur = cur->left;
    return cur;
  }

  BinaryNode* delete_node(int target, BinaryNode* node) {
    if (!node || !search(target,node)){
      return nullptr;
    }
    if (target < node->ID)
      node->left = delete_node(target, node->left);
    else if (target > node->ID)
      node->right = delete_node(target, node->right);
    else {
      BinaryNode* tmp = node;

      if (!node->left && !node->right)	{
        node = nullptr;
      }// case 1: no child
      else if (!node->right){
        cout << node->info;
        node = node->left;		// connect with child
      } 	// case 2: has left only
      else if (!node->left){
        cout << node->info;
        node = node->right;
      }	// case 2: has right only
      else {	// 2 children: Use successor
        BinaryNode* mn = min_node(node->right);
        node->ID = mn->ID; // copy & go delete
        cout << node->info;
        node->info = mn->info;
        node->right = delete_node(node->ID, node->right);
        tmp = nullptr;	// Don'int delete me. Successor will be deleted
      }
      if (tmp)
        delete tmp;
    }
    return node;
  }

  void print_inorder(BinaryNode* node) {
    if(!node)
      return;

    print_inorder(node->left);
    cout << *node->info;
    print_inorder(node->right);
  }




  int ch_height(BinaryNode* node){
    if(!node)
      return -1;
    return node->height;
  }
  void update_height(BinaryNode* node){
    if(node)
      node->height = 1+ max(ch_height(node->left), ch_height(node->right));
  }
  int balance_factor(BinaryNode* node){
    return ch_height(node->left) - ch_height(node->right);
  }
  BinaryNode* right_rotation(BinaryNode* &Q){
    BinaryNode* p = Q->left;
    if(p->right){
      Q->left = p->right;
    }
    else
      Q->left = nullptr;
    p->right = Q;
    update_height(Q);
    update_height(p);
    return p;
  }
  BinaryNode* lift_rotation(BinaryNode* &P){
    BinaryNode* q = P->right;
    if(q->left)
      P->right = q->left;
    else
      P->right = nullptr;
    q->left = P;
    update_height(P);
    update_height(q);
    return q;
  }
  BinaryNode* balance(BinaryNode* &node){
    if(balance_factor(node) == 2){
      if(balance_factor(node->left) == -1)
        node->left = lift_rotation(node->left);
      node = right_rotation(node);
    }
    if(balance_factor(node) == -2){
      if(balance_factor(node->right) == 1)
        node->right = right_rotation(node->right);
      node = lift_rotation(node);
    }
    return node;
  }

 public:


  void insert_value(int target, Student stu) {
    if (!root)
      root = new BinaryNode(target,stu);
    else
      insert_node(target, root,stu);
    root = balance(root);
  }

  void delete_value(int target) {
    if (root && search(target,root)) {
      cout << "Student is found\n";
      root = delete_node(target, root);
      update_height(root);
      root = balance(root);
      return;
    }
    cout << "Not found\n";
  }

  void search(int target) {
   if(!search(target,root))
     cout << "Not found\n";
  }

  void print_inorder() {
    print_inorder(root);
  }

  void departmentreprot(){
    report_departments(root);
  }

};
#endif //MENUS_H_AVL_H

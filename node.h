//#pragma once
#include <iostream>
#ifndef _LIST_UTILITY_H_
#define _LIST_UTILITY_H_

struct Node {
	Node *prev_ = nullptr, *next_ = nullptr;
	int data_ = 0;
};

struct List {
	Node *head_ = nullptr, *tail_ = nullptr;
};

struct ListNode {
	List * plist_ = nullptr;
	ListNode * next_ = nullptr;
};

struct ReturnState {
	Node *ptr;
	int   code;
	ReturnState() : ptr(nullptr), code(0)
	{}
	ReturnState(Node *p, int c) : ptr(p), code(c)
	{}
};

int is_empty(const List &list);
bool is_equal(const List &list1, const List &list2);
bool list_find(const List &list, const Node *node_ptr);
int compare(const Node &node1, const Node &node2);

void print_list1(const List &list);
void print_list2(const List &list);

Node* delete_front(List &);
Node* delete_back(List &list);
void delete_list(List &li);
ReturnState delete_inside(List &list, Node *node_ptr);

void push_front(List &list, int x);
void push_back(List &, int);
int insert_after(List &list, Node *node_ptr, int x);
int insert_after(List &list, Node *node_ptr, Node * ptr, bool dir);
// If the parameter dir is true, insert *ptr, *ptr->next, ..., and so on.
// If the parameter dir is false, insert ...  *ptr->prev,  *ptr. 
int insert_before(List &list, Node *node_ptr, int x);
void set_data(Node &node, int x);
void exchange(Node &node_ptr1, Node &node_ptr2);


bool copy_list(const List &src, List &target, const Node *node_ptr1, const Node *node_ptr2);
bool copy_list(const List &src, List &target);
List& cat_list(List &list1, const List &list2);
int slice_list(const List &src, List &list1, List &list2, Node *node_ptr);
bool merge_lists(List& li, const ListNode& beg);

void init_list(List& li, std::initializer_list<int> il);

#endif

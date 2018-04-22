#include "stdafx.h"
#include "list_utility.h"

void init_list(List& li, std::initializer_list<int> il)
{
	if (!is_empty(li))
		delete_list(li);
	for (auto beg = il.begin(); beg != il.end(); ++beg) {
		push_back(li, *beg);
	}
}
//bool init_list( List& list )
//{
//	try{
//		Node * node = new Node;
//		list.head_ = node;
//		list.tail_ = node;
//		return true;
//	}catch(...){
//		return false;
//	}
//}

int is_empty(const List &list)
{
	return list.head_ == nullptr;
}

bool is_equal(const List &list1, const List &list2)
{
	const Node *p1 = list1.head_ ,*p2 =list2.head_;
	while(p1 != nullptr && p2 != nullptr)
	{
		if(p1->data_ != p2->data_) return false;
		p1 = p1->next_;
		p2 = p2->next_;
	}
	if((p1 == nullptr && p2 == nullptr) || (p1 != nullptr && p2 != nullptr)) 
		return true;
	else 
		return false;
}

bool list_find(const List &list, const Node *node_ptr)
{	
	if (node_ptr == nullptr)
	{
		return false;
	}
	for( Node *p = list.head_; p != nullptr; p = p->next_ )
		if( p == node_ptr ) return true;
	return false;
}

int compare(const Node & node1, const Node & node2)
{
	if (node1.data_ == node2.data_)
	{
		return 0;
	}
	if (node1.data_ > node2.data_)
	{
		return 1;
	}
	if (node1.data_ < node2.data_)
	{
		return -1;
	}
}

void delete_list(List &li)
{
	while(! is_empty(li))
	{
		delete_front(li);
	}
}

bool copy_list(const List &src, List &target)
{
	return copy_list(src, target, src.head_, src.tail_);
	//if(! is_empty(target))
	//	delete_list(target);
	//for( Node *p = src.head_; p != nullptr; p = p->next_ )
	//{
	//	push_back(target, p->data_);
	//}
}
void set_data( Node &node,int x)
{
	node.data_ = x;
}

void exchange(Node &node1, Node &node2)
{
	int t;
	t = node1.data_;
	node1.data_ = node2.data_;
	node2.data_ = t;
}

void push_back(List &list,int x)
{
	if(list.tail_ == nullptr)
	{
		Node * node = new Node;
		list.head_ = node;
		list.tail_ = node;
		node->data_ = x;
	}
	else
	{
		Node *node = new Node;
		node->data_ = x;
		list.tail_->next_ = node;
		node->prev_ = list.tail_;
		list.tail_ = node;
	}
}

void push_front(List &list,int x)
{
	if(list.head_ == nullptr)
	{
		Node * node = new Node;
		list.head_ = node;
		list.tail_ = node;
		node->data_ = x;
	}
	else
	{
		Node *node = new Node;
		node->data_ = x;
		list.head_->prev_ = node;
		node->next_ = list.head_;
		list.head_ = node;
	}
}

void print_list1( const List &list)
{
	Node *node_ptr = list.head_;
	while( node_ptr != nullptr)
	{
		std::cout<< node_ptr->data_ <<" ";
		node_ptr = node_ptr->next_;
	}
	std::cout<<std::endl;
}

void print_list2( const List &list)
{
	Node *node_ptr = list.tail_;
	while( node_ptr != nullptr)
	{
		std::cout<< node_ptr->data_ <<" ";
		node_ptr = node_ptr->prev_;
	}
	std::cout<<std::endl;
}

int insert_after(List &list,Node *node_ptr,int x)
{
	if(list.tail_ == nullptr)
	{
		push_back(list,x);
		return 0;
	}
	if(node_ptr == nullptr)
	{
		std::cout<<"Error!"<<std::endl<<"input point is null!"<<std::endl;
		return -1;
	}
	if(node_ptr->next_ == nullptr)
	{
		push_back(list,x);
		return 0;
	}
	else
	{
		Node *node = new Node;
		node->data_ = x;
		node->next_ = node_ptr->next_;
		node_ptr->next_->prev_ = node;
		node_ptr->next_ = node;
		node->prev_ = node_ptr;
		return 0;
	}
}

int insert_after(List & list, Node * node_ptr, Node * ptr, bool dir)
{
	return 0;
}

int insert_before(List &list,Node *node_ptr,int x)
{
	if(list.head_ == nullptr)
	{
		push_front(list,x);
		return 0;
	}
	if(node_ptr == nullptr)
	{
		std::cout<<"Error!"<<std::endl<<"input point is null!"<<std::endl;
		return -1;
	}
	if(node_ptr->prev_ == nullptr)
	{
		push_front(list,x);
		return 0;
	}
	else
	{
		Node *node = new Node;
		node->data_ = x;
		node->prev_ = node_ptr->prev_;
		node_ptr->prev_->next_ = node;
		node_ptr->prev_ = node;
		node->next_ = node_ptr;
		return 0;
	}
}

Node* delete_front( List &list)
{
	if(is_empty(list))
	{
		return nullptr;
	}
	if (list.head_->next_ == nullptr)
	{
		delete list.head_;
		list.head_ = nullptr;
		list.tail_ = nullptr;
		return nullptr;
	}
	list.head_ = list.head_->next_;
	delete list.head_->prev_;
	list.head_->prev_ = nullptr;
	return list.head_;
}

Node* delete_back( List &list)
{
	if(is_empty(list))
	{
		return nullptr;
	}
	if (list.tail_->prev_ == nullptr)
	{
		delete list.tail_;
		list.tail_ = nullptr;
		list.head_ = nullptr;
		return nullptr;
	}
	list.tail_ = list.tail_->prev_;
	delete list.tail_->next_;
	list.tail_->next_ = nullptr;
	return list.tail_;
}

ReturnState delete_inside( List &list,Node *node_ptr)
{
	if(node_ptr == nullptr)
	{
		return ReturnState();
	}
	if(node_ptr->prev_ == nullptr && node_ptr->next_ == nullptr)
	{
		return ReturnState();
	}
	if(node_ptr->prev_ == nullptr)
	{
		if(list.head_ == node_ptr)
		{
			list.head_ = list.head_->next_;
			list.head_->prev_ = nullptr;
			delete node_ptr;
			return ReturnState(list.head_, 1);
		}
		else
		{
			return ReturnState();
		}
	}
	if(node_ptr->next_ == nullptr)
	{
		if(list.tail_ == node_ptr)
		{
			list.tail_ = list.tail_->prev_;
			list.tail_->next_ = nullptr;
			delete node_ptr;
			return ReturnState(nullptr, 1);
		}
		else
		{
			return ReturnState();
		}
	}
	if(list_find(list,node_ptr))
	{
		Node *p = node_ptr->next_; 
		node_ptr->prev_->next_ = node_ptr->next_;
		node_ptr->next_->prev_ = node_ptr->prev_;
		delete node_ptr;
		return ReturnState(p,1);
	}
	else return ReturnState();
}

List& cat_list(List &list1, const List &list2)
{
	if(list1.tail_ == nullptr)
	{
		list1.head_=list2.head_;
		list1.tail_=list2.tail_;
		return list1;
	}
	if(list2.head_ == nullptr)
		return list1;
	list1.tail_->next_ = list2.head_;
	list1.tail_->next_->prev_ =list1.tail_;
	list1.tail_ =list2.tail_;
	return list1;
}

int slice_list(const List &src ,List &list1, List &list2, Node *node_ptr)
{
	if (!is_empty(list1)) {
		delete_list(list1);
	}
	if (!is_empty(list2)) {
		delete_list(list2);
	}
	if(!list_find(src, node_ptr)){
		return 1;
	}
	if(is_empty(src)){
		return 1;
	}
	if(node_ptr == src.head_){
		copy_list(src, list2);
		return 0;
	}
	if(node_ptr == src.tail_){
		copy_list(src, list1);
		list2.head_ = src.tail_;
		list2.tail_ = src.tail_;
		list1.tail_ = list1.tail_->prev_;
		list1.tail_->next_ = nullptr;
		return 0;
	}
	list1.head_ = src.head_;
	list1.tail_ = node_ptr->prev_;
	list1.tail_->next_ = nullptr;
	list2.head_ = node_ptr;
	list2.tail_ = src.tail_;
	list2.head_->prev_ = nullptr;
	return 0;
}

bool copy_list(const List &src, List &target, const Node *node_ptr1, const Node *node_ptr2 )
{
	if (!list_find(src, node_ptr1))
	{
		return false;
	}
	if (!list_find(src, node_ptr2))
	{
		return false;
	}
	if (!is_empty(target))
	{
		delete_list(target);
	}
	const Node *p = node_ptr1;
	for (; p != node_ptr2 && p != nullptr; p = p->next_)
	{
		push_back(target, p->data_);
	}
	if (p == node_ptr2) push_back(target, node_ptr2->data_);
	return true;
}

bool merge_lists(List& li, const ListNode& beg)
{
	if (!is_empty(li)) {
		delete_list(li);
	}
	for (const ListNode *p = &beg; p != nullptr; p = p->next_) {
		if (p->plist_)
		{
			cat_list(li, *(p->plist_));
		}
	}
	return true;
}

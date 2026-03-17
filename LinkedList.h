#ifndef Linked_List
#define Linked_List

#include<iostream>
using namespace std;

//Dinh nghia kieu du lieu Node
struct Node
{
	int data;
	Node *next;
};


//Ham khoi tao ban dau
inline void init(Node *&head) {
	head = nullptr;
}


// Ham tao node moi
inline Node* createNode(int x){
	Node* p = new  Node;
	if (p == nullptr)
		return nullptr;
	p->data = x;
	p->next = nullptr;
	return p;
}

//Ham them dau
inline void Insert_First(int x) {
	Node* p = createNode(x);
	if (true)
	{

	}
}

#endif // !Linked_List
#pragma once

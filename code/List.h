#include<iostream>
using namespace std;
#pragma once
template <typename T>
class Node{
	public:
		T data;
		Node* next;
	public:
		Node();
		Node(T);
		Node(const Node&);
		Node& operator = (const Node&);
		~Node();
};
template <typename T>
class List{
	private:
		Node<T>* head;
	public:
		List();
		List(const List&);
		List& operator = (const List&);
		~List();
		void addHead(const T&);
		void addTail(const T&);
		void remove(const T&);
		void display();
		void mergeSort(bool type);
		Node<T>* getHead() const;
		Node<T>* find(const T& findData);
	private:
		Node<T>* merge(Node<T>* left, Node<T>* right, bool type);
		Node<T>* findMiddle(Node<T>* head);
		Node<T>* mergeSortRec(Node<T>* head, bool type);
}; 



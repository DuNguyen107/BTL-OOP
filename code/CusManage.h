#include"Customer.h"
#include"List.cpp"
#include"Manage.h"
#pragma once

class CusManage: public Manage<Customer>{
	protected:
		List<Customer> Cus;
	public:
		CusManage();
		~CusManage();
		void readFile(string file);
		void writeFile(string file);
		void add(const Customer& cus);
		void remove(Customer& cus);
		void update(Customer& cus);
		void display();
		Node<Customer>* find(int& ID);
		Node<Customer>* find(string& name, string& phone);
		int getNewID();
};
#include"Employee.h"
#include"List.cpp"
#include"Manage.h"
#pragma once

class EmpManage: public Manage<Employee>{
	protected:
		List<Employee> Emp;
	public:
		EmpManage();
		~EmpManage();
		void readFile(string file);
		void writeFile(string file);
		void add(const Employee& emp);
		void add(); // nhap thong tin
		void remove(Employee& emp);
		void update(Employee& emp);
		void display();
		Node<Employee>* find(int& ID);
		Node<Employee>* find(string& name, string& phone);
		int getNewID();
};
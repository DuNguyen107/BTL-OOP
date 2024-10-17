#include"Product.h"
#include"List.h"
#include"Manage.h"
#pragma once
class ProdManage: public Manage<Product>{
	protected:
		List<Product> Prod;
	public:
		ProdManage();
		~ProdManage();
		void readFile(string file);
		void writeFile(string file);
		void add(const Product& prod);
		void add(); // nhap thong tin
		void remove(Product& prod);
		void update(Product& prod);
		void display();
		void display(bool type); // true: tang dan, false: giam dan
		void displayOption();
		Node<Product>* find(string& ID);
};
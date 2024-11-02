#include"invoice.h"
#include"List.h"
#include"Manage.h"
#include"CusManage.h"
#include"EmpManage.h"
#include"ProdManage.h"
#include<iomanip>
#pragma once

class InvManage: public Manage<Invoice>{
	protected:
		List<Invoice> Inv;
	public:
		InvManage();
		~InvManage();
		void add(const Invoice& inv);
		void remove(Invoice& inv);
		void update(Invoice& inv);
		void display();
		List<Invoice> find(int& day, int month, int year);
		List<Invoice> find(int& month, int& year);
		List<Invoice> find(int& year);
		List<Invoice> find(Customer& cus); // tim theo khach hang
		Node<Invoice>* findID(int& ID); // mỗi ID là duy nhất
		void statistic(List<Invoice> list); // thống kê dựa trên danh sách hóa đơn
		void printInvoice(int invID, CusManage cusM);
		void printInvoice(Invoice& inv, CusManage cusM);
		void findtoShow(int& ID); // tìm ID va in thông tin của ID
		int getNewID();
		void updateCart(Invoice& newInv, ProdManage& prodM, CusManage& cusM, EmpManage& empM);
		void sell(CusManage& cusM, ProdManage& prodM, EmpManage& empM);
		void readFile(string file, string detail_file);
		void writeFile(string file, string detail_file);
};
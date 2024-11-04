#include"Date.h"
#include"List.h"
#include"Order.h"
#pragma once

class Invoice{
	private:
		int cusID;
		int invID;
		double total;
		string payment;
		Date date;
		List<order> listOfOrder;
		bool status; //trang thai thanh toan
	public:
		Invoice();
		Invoice(int cusID,int invID,double total,string payment,const Date& date);
		Invoice(const Invoice& p);
		~Invoice();
		Invoice& operator = (const Invoice& p);
		void show();
		friend ostream& operator << (ostream& os, const Invoice& p);
		bool operator != (const Invoice& p);
		bool operator == (const Invoice& p);
		void updateTotal();
		//getter
		int getCusID();
		int getInvID();
		double getTotal();
		double getProfit();
		double productSales();
		Date getDate();
		string getPayment();
		//setter
		void setCusID(int& cusID);
		void setInvID(int& invID);
		void setPayment(string& payment);
		//method
		void addOrder(order& p);
		List<order>& getOrder();
		void removeOrder(const string& p);
		Node<order>* findOrder(const string& p);
		void updateDate();
		void complete();
};
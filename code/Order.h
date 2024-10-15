#include"Product.h"
#pragma once
//using namespace std;
class order: public Product{
	private:
		double total;
	public:
		order();
		order(const string& ID, const string& name, double price, double total);
		order(const order& p);
		order& operator = (const order& p);
		~order();
		
		void updateTotal();
		double getTotal();
		friend ostream& operator << (ostream &os, const order& p);
		bool operator != (const order& p) const;
		bool operator == (const order& p ) const;
};


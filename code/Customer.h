#include"Person.h"
#pragma once
class Customer: public Person{
	public:
		Customer(string = "", string = "", string = "", string = "", int = 0, bool = true);
        ~Customer();
        void Show();
        friend ostream& operator<<(ostream&, const Customer&);
};
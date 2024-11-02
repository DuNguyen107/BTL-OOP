#include "Customer.h"
Customer::Customer(string name, string phone, string email, string address, int id, bool gender){
	this->name = name;
	this->phone = phone;
	this->email = email;
	this->address = address;
	this->id = id;
	this->gender = gender;
}
Customer::~Customer(){}
void Customer::Show(){
	cout << endl << endl;
    cout << "                                                                       THÔNG TIN KHÁCH HÀNG\n";
	cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+\n";
	cout << "  |  Mã khách hàng  |  Họ và tên                   |  Số điện thoại       |   Giới tính    |  Email                       |  Địa chỉ                        |\n"; 
	cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+\n";
    cout << endl;
    cout << "  |" << setw(2) << " " << this->id;
//	cout << "Ma khach hang: " << this->id << endl;
	Person::Show();
//	cout << "***********" << endl;
}

ostream& operator<<(ostream& os, const Customer& cus){
    Person *p = new Customer();
    *p = cus;
	cout << "  |" << setw(2) << " " << cus.id;
    p->Person::Show();
    delete p;
    return os;
}
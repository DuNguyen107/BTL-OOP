#include "Employee.h"
Employee::Employee(string name, string phone, string email, string address, int id, bool gender, Position position, double salary, string password){
	this->name = name;
	this->phone = phone;
	this->email = email;
	this->address = address;
	this->id = id;
	this->gender = gender;
	this->position = position;
	this->salary = salary;
	this->password = password;
}
Employee::~Employee(){}
Position Employee::getPosition(){
	return this->position;
}
double Employee::getSalary(){
	return this->salary;
}
string Employee::getPassword(){
	return this->password;
}
void Employee::setPosition(Position position){
	this->position = position;
}
void Employee::setSalary(double salary){
	this->salary = salary;
}
void Employee::setPassword(string password){
	this->password = password;
}
ostream& operator<<(ostream& os, const Employee& emp){
    Person *p = new Employee();
    *p = emp;
    os << "Ma Nhan vien: " << emp.id << "; ";
    os << "Chuc vu: ";
    if (emp.position == manager) os << "quan li; ";
    if (emp.position == sales) os << "nhan vien; ";
    p->Person::Show();
    os << "; Luong: " << emp.salary << "; ";
    delete p;
    return os;
}
void Employee::Show(){
	cout << setw(20) << " " << "+-----------------"<< "-----------------+";
	cout << setw(20) << " " << "| Mã nhân viên:  |"<< this->id << setw(10) << "|"; 
	cout << setw(20) << " " << "+----------------+"<< "+----------------+";
	cout << "Chức vụ: ";
	if(this->position == manager) 
		cout << "Quản lý" << endl;
	else
		cout << "Nhân viên" << endl;
	Person::Show();
	cout << "Lương: " << this->salary << endl;
}
	
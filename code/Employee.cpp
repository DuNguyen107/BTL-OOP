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
void Employee::Show(){
	cout << "Ma Nhan Vien: " << this->id << endl;
	cout << "Chuc vu: ";
	if(this->position == manager) 
		cout << "Quan ly" << endl;
	else
		cout << "Nhan vien" << endl;
	Person::Show();
	cout << "Luong: " << this->salary << endl;
	cout << "**********\n";
}
bool Employee::changePassword(){
	string old_pass, new_pass;
	do{
		cout << "Nhap mat khau cu: ";
		cin >> old_pass;
		if(old_pass != this->password){
			cout << "SAI MAT KHAU, VUI LONG NHAP LAI !!" << endl;
			cout << "NHAP X DE TRO VE MENU CHINH" << endl;
		}
	}while(old_pass != this->password && old_pass != "x");
	if(old_pass == "x") return false;
	do{
		cout << "Nhap mat khau moi: ";
		cin >> new_pass;
		if(new_pass.size() < 6)
			cout << "Mat khau phai tren 6 ki tu" << endl;
	}while(new_pass.size() < 6);
	this->setPassword(new_pass);
	cout << "Doi mat khau thanh cong" << endl;
	return true;
	
}
		
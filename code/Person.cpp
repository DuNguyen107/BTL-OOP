#include"Person.h"

Person::Person(string name, string phone, string email, string address, int id, bool gender){
	this->name = name;
	this->phone = phone;
	this->email = email;
	this->address = address;
	this->id = id;
	this->gender = gender;
}
Person::~Person(){
}
string Person::getName(){
	return this->name;
}
string Person::getPhone(){
	return this->phone;
}
string Person::getEmail(){
	return this->email;
}
string Person::getAddress(){
	return this->address;
}
int Person::getID(){
	return this->id;
}
bool Person::getGender(){
	return this->gender;
}
void Person::setName(string name){
	this->name = name;
}
void Person::setPhone(string phone){
	this->phone = phone;
}
void Person::setEmail(string email){
	this->email = email;
}
void Person::setAddress(string address){
	this->address = address;
}
void Person::setID(int id){
	this->id = id;
}
void Person::setGender(bool gender){
	this->gender = gender;
}
bool Person::operator != (const Person& p){
	return (this->id != p.id);
}
bool Person::operator == (const Person& p){
	return (this->id == p.id);
}
void Person::Show(){
	cout << "Họ và tên: " << this->name << endl;
	cout << "Số điện thoại: " << this->phone << endl;
    cout << "Giới tính: ";
    if(this->gender) cout << "Nam\n";
    else cout << "Nữ\n";
    cout << "Email: " << this->email << endl;
	cout << "Địa chỉ: " << this->address << endl;
}
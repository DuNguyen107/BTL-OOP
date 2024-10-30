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
	int n1 = 30 - (this->name.size()+1);
	cout << setw(10) << " " << "|" << "  " << this->name << setw(n1) << "|" ;
	cout << setw(2)  << " " << this->phone << " ";
    if(this->gender){ cout << setw(10) << "|" << setw(3) << " " << "Nam"; }
    else { cout << setw(10) << "|" << setw(3) << " " << "Nữ "; }
	cout << setw(11) << "|" << setw(2) << " " << this->email;
	int n2 = 30 - (this->email.size()+1), n3 = 31 - (this->address.size()); 
	cout << setw(n2) << "|" << setw(2) << " " << this->address << setw(n3) << " " << "|" << endl;
	cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+";	
}
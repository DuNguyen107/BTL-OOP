#include"Person.h"
#include<iostream>

Person::Person(){
	name = "";
	idCard = "";
	phone = "";
}
Person::Person(string name, string idCard, string phone){
	this->name = name;
	this->idCard = idCard;
	this->phone = phone;
}
string Person::getName() const{
	return name;
}
string Person::getIdCard() const{
	return idCard;
}
string Person::getPhone() const{
	return phone;
}
void Person::setName(string name){
	this->name = name;
}
void Person::setIdCard(string idCard){
	this->idCard = idCard;
}
void Person::setPhone(string phone){
	this->phone = phone;
}
void Person::display_info() const{
	cout << "Ten: " << name << ", CMND: " << idCard << ", SDT: " << phone << endl;
}
Person::~Person(){
}
#include"Room.h"
#include<iostream>

Room::Room(){
	id = 0;
	type = "";
	state = false;
	price = 0.0;
}
Room::Room(int id,string type,bool state,double price){
	this->id = id;
	this->type = type;
	this->state = state;
	this->price = price;
}
int Room::getID() const{
	return id;
}
string Room::getType() const{
	return type;
}
bool Room::getState() const{
	return state;
}
double Room::getPrice() const{
	return price;
}
void Room::setID(int id){
	this->id = id;
}
void Room::setType(string type){
	this->type = type;
}
void Room::setState(bool state){
	this->state = state;
}
void Room::setPrice(double price){
	this->price = price;
}
void Room::display_info() const{
	cout << "So phong: " << id <<"\nLoai phong: " << type
		 << "\nTinh trang phong: " << (state?"Con trong":"Da thue")
		 << "\nGia phong: " << price << endl;
}
Room::~Room(){
}
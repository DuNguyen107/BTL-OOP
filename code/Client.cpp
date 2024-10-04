#include"Client.h"

Client::Client(){
	address = "";
	idRoom = 0;
}
Client::Client(string name,string idCard,string phone,string address,int idRoom){
	this->address = address;
	this->idRoom = idRoom;
}
string Client::getAddress() const{
	return address;
}
int Client::getIdRoom() const{
	return idRoom;
}
void Client::setAddress(string address){
	this->address = address;
}
void Client::setIdRoom(int room){
	this->idRoom = idRoom;
}
Client::~Client(){
}
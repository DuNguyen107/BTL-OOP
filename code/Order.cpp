#include"Order.h"
order::order(){
	this->total = 0;
}
order::order(const string& ID, const string& name, double price, double total){
	this->productID = ID;
	this->name = name;
	this->price = price;
	this->total = total;
}
order::order(const order& p){
	*this = p;
}
order& order::operator = (const order& p){
	if(this != &p){
		this->productID = p.productID;
		this->name = p.name;
		this->price = p.price;
		this->quantity = p.quantity;
		this->serial = p.serial;
		this->total = p.total;
	}
	return *this;
}
order::~order(){}
void order::updateTotal(){
	this->total = this->quantity * this->price;
}
double order::getTotal(){
	this->updateTotal();
	return this->total;
}
ostream& operator << (ostream &os, const order& p){
	os << setw(70) << " " << "Mã sản phẩm: " << p.productID << endl;
    os << setw(70) << " " << "Tên sản phẩm: " << p.name << endl;
    os << setw(70) << " " << "Đơn giá: " << p.price << endl;
    os << setw(70) << " " << "Số lượng sản phẩm: " << p.quantity << endl;
    os << setw(70) << " " << "Tổng tiền: " << p.total << endl;
    os << "Số serial sản phẩm: ";
    Node<string>* currentNode = p.serial.getHead();
    while (currentNode != nullptr) 
    {
        os << currentNode->data;
        if(currentNode != nullptr) os << ", ";
        currentNode = currentNode->next;
    }
    os << endl;
    return os;
}
bool order::operator != (const order& p) const{
	return this->getID() != p.getID();
}
bool order::operator == (const order& p ) const{
	return this->getID() == p.getID();
}
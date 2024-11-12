#include"Order.h"
order::order(){
	this->total = 0;
	this->quantity = 0;
    this->productID = "0";
    this->name = "";
    this->price = 0;  
}
order::order(const string& ID, const string& name, double price, double total){
	this->productID = ID;
	this->name = name;
	this->price = price;
	this->total = total;
    this->quantity = 0;
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
    os << setw(70) << " " << "Đơn giá: " << fixed << setprecision(0) << p.price << " VNĐ" << endl;
    os << setw(70) << " " << "Số lượng sản phẩm: " << p.quantity << endl;
    os << setw(70) << " " << "Tổng tiền: " << fixed << setprecision(0) << p.total << " VND" << endl;
    os << setw(70) << " " << "Số serial sản phẩm: ";
    Node<string>* currentNode = p.serial.getHead();
    int count = 0;
    while (currentNode != nullptr) 
    {
    	count++;
    	if(count % 3 == 0){
    		cout << endl;
    		cout << setw(90) << " ";
		}
        os << currentNode->data;
        if(currentNode != nullptr);
        currentNode = currentNode->next;
        if(currentNode != nullptr) os << ", ";
    }
    os << endl;
    os << setw(60) << " " << string(60, '-') << endl;
    os << endl;
    return os;
}
bool order::operator != (const order& p) const{
	return this->getID() != p.getID();
}
bool order::operator == (const order& p ) const{
	return this->getID() == p.getID();
}
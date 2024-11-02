#include"invoice.h"

Invoice::Invoice(){
	invID = 0;
	empID = 0;
	cusID = 0;
	total = 0;
	payment = "";
	status = false;
}
Invoice::Invoice(int cusID,int empID,int invID,double total,string payment,const Date& date){
	this->invID = invID;
	this->empID = empID;
	this->cusID = cusID;
	this->total = total;
	this->payment = payment;
	this->date = date;
}
Invoice::Invoice(const Invoice& p){
	this->invID = p.invID;
	this->empID = p.empID;
	this->cusID = p.cusID;
	this->total = p.total;
	this->payment = p.payment;
	this->date = p.date;
	this->listOfOrder = p.listOfOrder;
	this->status = p.status;
}
Invoice::~Invoice(){}
Invoice& Invoice::operator = (const Invoice& p){
	if(this != &p){
		this->invID = p.invID;
		this->empID = p.empID;
		this->cusID = p.cusID;
		this->total = p.total;
		this->payment = p.payment;
		this->date = p.date;
		this->listOfOrder = p.listOfOrder;
		this->status = p.status;
	}
	return *this;
}
void Invoice::show(){
	cout << "Ma hoa don: " << this->invID << endl;
    cout << "Ma khach hang: " << this->cusID << endl;
    cout << "Ma nhan vien: " << this->empID << endl;
    cout << "Phuong thuc thanh toan: " << this->payment << endl;
    cout << "Tong tien: " << this->total << endl;
    this->listOfOrder.display();
}
ostream& operator << (ostream& os, const Invoice& p){
	os << setw(70) << " " << "Mã hóa đơn: " << p.invID << endl;
    os << setw(70) << " " << "Mã khách hàng: " << p.cusID << endl;
    os << setw(70) << " " << "Mã nhân viên: " << p.empID << endl;
    os << setw(70) << " " << "Phương thức thanh toán: " << p.payment << endl;
    os << setw(70) << " " << "Tổng tiền: " << p.total << endl;
    Invoice *temp = new Invoice();
    *temp = p;
    temp->listOfOrder.display();
    cout << setw(50) << " " << string(60, '_') << endl;
    delete temp;
    return os;
}
bool Invoice::operator != (const Invoice& p){
	return this->invID != p.invID;
}
bool Invoice::operator == (const Invoice& p){
	return this->invID == p.invID;
}
void Invoice::updateTotal(){
	this->total = 0;
	Node<order>* tempNode = this->listOfOrder.getHead();
	while(tempNode != nullptr){
		this->total += tempNode->data.getTotal();
		tempNode = tempNode->next;
	}
}
//getter
int Invoice::getCusID(){
	return this->cusID;
}
int Invoice::getEmpID(){
	return this->empID;
}
int Invoice::getInvID(){
	return this->invID;
}
double Invoice::getTotal(){
	this->updateTotal();
	return this->total;
}
double Invoice::getProfit(){
	double res = 0;
	Node<order>* p = this->listOfOrder.getHead();
	while(p != nullptr){
		res += p->data.Profit();
		p = p->next;
	}
	return res;
}
double Invoice::productSales(){
	double res = 0;
	Node<order>* p = this->listOfOrder.getHead();
	while(p != nullptr){
		res += p->data.getQuantity();
		p = p->next;
	}
	return res;
}
Date Invoice::getDate(){
	return this->date;
}
string Invoice::getPayment(){
	return this->payment;
}
//setter
void Invoice::setCusID(int& cusID){
	if(status == false) 
		this->cusID = cusID;
}
void Invoice::setEmpID(int& empID){
	if(status == false) 
		this->empID = empID;
}
void Invoice::setInvID(int& invID){
	if(status == false) 
		this->invID = invID;
}
void Invoice::setPayment(string& payment){
	if(status == false) 
		this->payment = payment;
}
//method
void Invoice::addOrder(order& p){
	if(status == false) 
		this->listOfOrder.addHead(p);
}
List<order>& Invoice::getOrder(){
	return this->listOfOrder;
}
void Invoice::removeOrder(const string& ID){
	if(status == false){
		Node<order>* p = this->findOrder(ID);
		if(p != nullptr){
			listOfOrder.remove(p->data);
		}else 
			cout << "\nChưa có sản phẩm này trong giỏ hàng !!";
	}	
}
Node<order>* Invoice::findOrder(const string& ID){
	order tempOrder;
	tempOrder.setID(ID);
	return this->listOfOrder.find(tempOrder);
}
void Invoice::updateDate(){
	if(status == false) getCurrent(this->date);
}
void Invoice::complete(){
	this->status = true;
}
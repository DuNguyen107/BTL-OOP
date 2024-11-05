#include "Database.h"
using namespace std;

Database Database::instance; //khoi tao database truoc tien

Database::Database() {}

Database::~Database() {}

Database& Database::DB_Instance() {
    return instance;
}

ProdManage& Database::getProdManage(){
    return this->productM;
}

CusManage& Database::getCusManage(){
    return this->customerM;
}

InvManage& Database::getInvManage(){
    return this->invoiceM;
}

void Database::readData(){
    instance.customerM.readFile("customer.txt");
    instance.productM.readFile("product.txt");    
    instance.invoiceM.readFile("invoice.txt", "invoice_detail.txt");
}

void Database::saveData(){
    instance.customerM.writeFile("customer.txt");
    instance.productM.writeFile("product.txt");
    instance.invoiceM.writeFile("invoice.txt", "invoice_detail.txt");
}


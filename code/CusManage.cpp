#include "CusManage.h"

CusManage::CusManage()
{ }
CusManage::~CusManage()
{ }
void CusManage::readFile(string file){
    int ID; bool gender;
    string temp, name, phone, email, address;
    ifstream inputFile(file);
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line))
        {
            istringstream iss(line);
            iss >> ID;
            iss.ignore(); 
            getline(iss, name, '|');
            getline(iss, phone, '|');
            getline(iss, email, '|');
            getline(iss, temp, '|');
            if(temp == "Nu") gender = true;
            else gender = false;
            getline(iss, address, '|');
            Customer newcus(name, phone, email, address, ID, gender);
            this->Cus.addTail(newcus);
        }
        inputFile.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }
}

void CusManage::writeFile(string file){
    ofstream outputFile(file, ios::out | ios::trunc);
    if (outputFile.is_open()) 
    {
        for (Node<Customer>* current = this->Cus.getHead(); current != nullptr; current = current->next) {
            outputFile << current->data.getID() << "|";
            outputFile << current->data.getName() << "|";
            outputFile << current->data.getPhone() << "|";
            outputFile << current->data.getEmail() << "|";
            if (current->data.getGender() == true) outputFile << "Nu|";
            else outputFile << "Nam|";
            outputFile << current->data.getAddress() << "|";
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cerr << "Khong the ghi du lieu" << endl;
    }
}

void CusManage::add(const Customer& cus) {
    this->Cus.addHead(cus);
}
void CusManage::remove(Customer& cus){
    this->Cus.remove(cus); 
}
void CusManage::display(){
    this->Cus.display();
}
void CusManage::update(Customer& cus) {

    int ID = cus.getID();
    Customer& _customer = this->find(ID)->data;
    string name, phone, mail, adress;
    bool gender;
    system("cls");
    cout << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
	cout << setw(60) << " " << "NHẬP THÔNG TIN KHÁCH MUA HÀNG" << endl;
	cout << setw(50) << " " << string(60, '=') << endl;
	cout << string(55, ' ') << "Tên: "; cin.ignore(); getline(cin, name); _customer.setName(name);
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << string(55, ' ') << "Số điện thoại: "; getline(cin, phone); _customer.setPhone(phone);
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << string(55, ' ') << "Email: "; getline(cin, mail); _customer.setEmail(mail);
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << string(55, ' ') << "Giới tính ( 0:Nam - 1:Nữ ): ";cin >> gender; cin.ignore(); _customer.setGender(gender);
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << string(55, ' ') << "Địa chỉ: "; getline(cin, adress); _customer.setAddress(adress);
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << setw(60) << " " << "NHẬP THÀNH CÔNG THÔNG TIN KHÁCH HÀNG" << endl;
	cout << setw(50) << " " << string(60, '=') << endl;
	system("pause");
}

Node<Customer>* CusManage::find(int& ID)
{
    Customer tempCus;
    tempCus.setID(ID);
    return this->Cus.find(tempCus);
}
Node<Customer>* CusManage::find(string& name, string& phone)
{
    Node<Customer>* Found = nullptr;
    if( name == "x" && phone == "x" ) return Found;
    Node<Customer>* tempNode;
    tempNode = this->Cus.getHead();
    while (tempNode != nullptr) 
    {
        if ( ( tempNode->data.getName() == name || name == "x" ) && ( tempNode->data.getPhone() == phone || phone == "x" ) ) 
            Found = tempNode;
        tempNode = tempNode->next;
    }
    return Found;
}

int CusManage::getNewID()
{
    Node<Customer>* Ncus = this->Cus.getHead();
    if(Ncus == nullptr) return 10000;
    return Ncus->data.getID() + 1;
}

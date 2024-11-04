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
    int gender;
    bool check;
    system("cls");
    cout << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
	cout << setw(60) << " " << "NHẬP THÔNG TIN KHÁCH MUA HÀNG" << endl;
	cout << setw(50) << " " << string(60, '=') << endl;
	cout << string(55, ' ') << "Tên: "; cin.ignore(); getline(cin, name); _customer.setName(name);
	//
	do{
		check = true;
    	cout << setw(50) << " " << string(60, '-') << endl;
    	cout << string(55, ' ') << "Số điện thoại: "; getline(cin, phone); 
		string s = phone.substr(0,2);
		if(phone.length() != 10 || (s != "03" && s != "05" && s != "07" && s != "08" && s != "09") ){
			check = false;
		}
		for(int i=0; i<phone.length(); i++){
			if(phone[i] == ' ' || !isdigit(phone[i])){
				check = false;
			}
		}
		if(!check) cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
	}while(!check);
	_customer.setPhone(phone);
    //
    do{
    	check = true;
    	cout << setw(50) << " " << string(60, '-') << endl;
    	cout << string(55, ' ') << "Email: "; getline(cin, mail);
    	if(mail.length() < 11 || (mail[0] == '@' || mail[mail.length()-1] == '@')){
			check = false;
		}
		for(int i=0; i<mail.length(); i++){
			if(mail[i] == ' '){
				check = false;
			}
		}
		if(!check) cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
	}while(!check);
	_customer.setEmail(mail);
    //
    do{
    	cout << setw(50) << " " << string(60, '-') << endl;
    	cout << string(55, ' ') << "Giới tính ( 0:Nam - 1:Nữ ): ";cin >> gender; cin.ignore(); 
		if(gender != 0 && gender != 1){
			cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
		}
	}while(gender != 0 && gender != 1);
	_customer.setGender(gender);
    cout << setw(50) << " " << string(60, '-') << endl;

    cout << string(55, ' ') << "Địa chỉ: "; getline(cin, adress); _customer.setAddress(adress);
    cout << setw(50) << " " << string(60, '=') << endl;
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

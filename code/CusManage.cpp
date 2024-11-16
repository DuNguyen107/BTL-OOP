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

// them vao dau danh sach
void CusManage::add(const Customer& cus) {
    this->Cus.addHead(cus);
}
void CusManage::remove(Customer& cus){
    this->Cus.remove(cus); 
}
void CusManage::display(){
	cout << endl;
	cout << "                                                                       THÔNG TIN KHÁCH HÀNG\n";
	cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+\n";
	cout << "  |  Mã khách hàng  |  Họ và tên                   |  Số điện thoại       |   Giới tính    |  Email                       |  Địa chỉ                        |\n"; 
	cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+";
	cout << endl;
    this->Cus.display();
}
// them thong tin
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
	cin.ignore(); 
	do{
		check = true;
		cout << string(55, ' ') << "Tên: "; getline(cin, name); 
		for(int i=0; i<name.size(); i++){
			if((!isalpha(name[i]) && name[i] != ' ') || name[0] == ' '){
				check = false;
			}
		}
		if(!check){
			cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
			cout << setw(50) << " " << string(60, '-') << endl;
		}
	}while(!check);
	_customer.setName(name);
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
		if(mail.length() > 10){
	    	string s = mail.substr(mail.size()-10,10);
	    	if(s != "@gmail.com") check = false;
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
    	cout << string(55, ' ') << "Giới tính ( 0:Nữ - 1:Nam ): ";cin >> gender; cin.ignore(); 
		if(gender != 0 && gender != 1){
			cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
		}
	}while(gender != 0 && gender != 1);
	_customer.setGender(gender);
    cout << setw(50) << " " << string(60, '-') << endl;

	do{
		check = true;
    	cout << string(55, ' ') << "Địa chỉ: "; getline(cin, adress); 
		for(int i=0; i<adress.size(); i++){
			if((!isalpha(adress[i]) && adress[i] != ' ') || adress[0] == ' '){
				check = false;
			}
		}
		if(!check){
			cout << setw(60) << " " << "Nhập sai định dạng !!" << endl;
			cout << setw(50) << " " << string(60, '-') << endl;
		}
	}while(!check);
	_customer.setAddress(adress);
    cout << setw(50) << " " << string(60, '=') << endl;
    cout << setw(60) << " " << "NHẬP THÀNH CÔNG THÔNG TIN KHÁCH HÀNG" << endl;
	cout << setw(50) << " " << string(60, '=') << endl;
	system("pause");
}
void CusManage::edit(Customer& cus){
	int ID = cus.getID();
    Customer& customer = this->find(ID)->data;
    bool over = false, check;
    int option;
    do{
    	check = true;
        system("cls");
        customer.Show();
        cout << setw(60) << " " << string(37, '-') << endl;
		cout << setw(60) << " " << "|\t\t1.Tên          \t\t|\n";
        cout << setw(60) << " " << "|\t\t2.Số điện thoại\t\t|\n";
        cout << setw(60) << " " << "|\t\t3.Giới tính    \t\t|\n";
        cout << setw(60) << " " << "|\t\t4.Email        \t\t|\n";
        cout << setw(60) << " " << "|\t\t5.Địa chỉ      \t\t|\n";
        cout << setw(60) << " " << "|\t\t6.Quay lại     \t\t|\n";
        cout << setw(60) << " " << string(37, '-') << endl;
		cout << setw(60) << " " << "Nhập chức năng (thông tin) muốn thay đổi: "; cin >> option; cin.ignore();
		if(option < 1 || option > 11){
			cout << endl << setw(60) << " " << "Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 6. \n"; 
			system("pause");
		}
		switch (option){
            case 1:{
            	cout << setw(60) << " " << string(40, '-') << endl;
                string name;
            	cout << setw(60) << " " << "Chỉnh sửa tên khách hàng: ";
                getline(cin, name);
				for(int i=0; i<name.size(); i++){
					if((!isalpha(name[i]) && name[i] != ' ') || name[0] == ' '){
						check = false;
					}
				}
				if(check) customer.setName(name);
				break;
			}
            case 2:{
            	cout << setw(60) << " " << string(40, '-') << endl;
            	string phone;
                cout << setw(60) << " " << "Chỉnh sửa số điện thoại: ";
                getline(cin,phone);
                string s = phone.substr(0,2);
				if(phone.length() != 10 || (s != "03" && s != "05" && s != "07" && s != "08" && s != "09") ){
					check = false;
				}
				for(int i=0; i<phone.length(); i++){
					if(phone[i] == ' ' || !isdigit(phone[i])){
						check = false;
					}
				}
                if(check) customer.setPhone(phone);
				break;
			}   
            case 3:{
				cout << setw(60) << " " << string(40, '-') << endl;
                bool gender;
                cout << setw(60) << " " << "Chỉnh sửa giới tính (0-Nữ : 1-Nam): ";
                cin >> gender;
                if(cin.fail()){
                	check = false;
                	cin.clear();
                	cin.ignore(1000, '\n');
				}
                customer.setGender(gender);
				break;
			}
            case 4:{
            	cout << setw(60) << " " << string(40, '-') << endl;
	            string mail;
	            cout << setw(60) << " " << "Chỉnh sửa Email : ";
                getline(cin,mail);
                if(mail.length() < 11 || (mail[0] == '@' || mail[mail.length()-1] == '@')){
					check = false;
				}
				if(mail.length() > 10){
			    	string s = mail.substr(mail.size()-10,10);
			    	if(s != "@gmail.com") check = false;
				}
				for(int i=0; i<mail.length(); i++){
					if(mail[i] == ' '){
						check = false;
					}
				}
                if(check) customer.setEmail(mail);
				break;
			}
            case 5:{
            	cout << setw(60) << " " << string(40, '-') << endl;
                string address;
                cout << setw(60) << " " << "Chỉnh sửa địa chỉ: ";
                getline(cin,address);
                for(int i=0; i<address.size(); i++){
					if((!isalpha(address[i]) && address[i] != ' ') || address[0] == ' '){
						check = false;
					}
				}
                customer.setAddress(address);
				break;
			}                                      
            case 6:
                over = true;
                break;
            default: 
				cout << setw(50) << " " << "Lỗi dữ liệu !!\n";
        }
        if(!check){
        	cout << setw(60) << " " << string(40, '-') << endl;
        	cout << setw(70) << " " << "Nhập sai định dạng !!\n";	
        	system("pause");
		}else if(check && option != 6){
			cout << setw(60) << " " << string(40, '-') << endl;
			cout << setw(70) << " " << "CẬP NHẬT THÀNH CÔNG !!\n";
        	system("pause");
		}
    }while (over != true);
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
    if(Ncus == nullptr) return 100;
    return Ncus->data.getID() + 1;
}

#include "CusManage.h"

CusManage::CusManage()
{ }
CusManage::~CusManage()
{ }
void CusManage::readFile(string file)
{
    ifstream inputFile(file);
    int ID; bool gender;
    string temp, name, phone, email, address;
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

void CusManage::writeFile(string file)
{
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
    int input;
    int choice = 1;
    int MaxChoice = 6;

    do {
        system("cls");
        cout << "Nhap thong tin khach hang:" << endl;
        cout << (choice == 1 ? "->" : "  ") << "Ten: " << _customer.getName() << endl;
        cout << (choice == 2 ? "->" : "  ") << "SDT: " << _customer.getPhone() << endl;
        cout << (choice == 3 ? "->" : "  ") << "Email: " << _customer.getEmail() << endl;
        cout << (choice == 4 ? "->" : "  ") << "Gioi tinh: " << (_customer.getGender() ? "Nu" : "Nam") << endl;
        cout << (choice == 5 ? "->" : "  ") << "Dia chi: " << _customer.getAddress() << endl;
        cout << (choice == 6 ? "->" : "  ") << "Thoat" << endl;
        input = getch();

        if (input == 80) {
            if (choice == MaxChoice) choice = 1;
            else choice++;
        } else if (input == 72) {
            if (choice == 1) choice = MaxChoice;
            else choice--;
        }
        string name, phone, mail, adress;
        bool gender;

        if (input == 13) {
            switch (choice) {
                case 1:
                    cout << "Nhap ten moi: ";
                    getline(cin, name);
                    _customer.setName(name);
                    break;
                case 2:
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, phone);
                    _customer.setPhone(phone);
                    break;
                case 3:
                    cout << "Nhap email moi: ";
                    getline(cin, mail);
                    _customer.setEmail(mail);
                    break;
                case 4:
                    cout << "Nhap gioi tinh (1: Nu, 0: Nam): ";
                    cin >> gender;
                    cin.ignore(); 
                    _customer.setGender(gender);
                    break;
                 case 5:
                    cout << "Nhap dia chi moi: ";
                    getline(cin, adress);
                    _customer.setAddress(adress);
                    break;    
                case 6:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                default:
                    cout << "Loi du lieu" << endl;
            }
        }
    } while (input != '0');
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

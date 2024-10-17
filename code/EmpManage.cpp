#include"EmpManage.h"

EmpManage::EmpManage()
{ }
EmpManage::~EmpManage()
{ }
void EmpManage::readFile(string file)
{
    ifstream inputFile(file);
    int ID; bool gender;
    string temp, name, phone, email, address, pass;
    double salary;
    Position pos;
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
            iss >> salary;
            iss.ignore();
            getline(iss, temp, '|');
            if(temp == "manager") pos = manager;
            else pos = sales;
            getline(iss, pass, '|');
            Employee newEmp(name, phone, email, address, ID, gender, pos, salary, pass);
            this->Emp.addTail(newEmp);
        }
        inputFile.close();
    } else {
        cerr << "Khong the mo file" << file << endl; //bao loi
    }
}

void EmpManage::writeFile(string file)
{
    ofstream outputFile(file, ios::out | ios::trunc);
    if (outputFile.is_open()) 
    {
        for (Node<Employee>* current = this->Emp.getHead(); current != nullptr; current = current->next) {
            outputFile << current->data.getID() << "|";
            outputFile << current->data.getName() << "|";
            outputFile << current->data.getPhone() << "|";
            outputFile << current->data.getEmail() << "|";
            if (current->data.getGender() == true) outputFile << "Nu|";
            else outputFile << "Nam|";
            outputFile << current->data.getAddress() << "|";
            outputFile << current->data.getSalary() << "|";
            if(current->data.getPosition() == manager)
            	outputFile << "manager|";
            else
            	outputFile << "sales|";
            outputFile << current->data.getPassword() << "|";
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cerr << "Khong the ghi du lieu" << endl;
    }
}

void EmpManage::add(const Employee& emp) {
    this->Emp.addHead(emp);
}
void EmpManage::add(){
	int ID; bool gender; double salary;
	string name, phone, email, address, pos, pass;
	Position position;
	cout << "NHAP THONG TIN\n";
	ID = this->getNewID(); cin.ignore();
	cout << "Ten nhan vien: "; getline(cin, name);
	cout << "So dien thoai: "; getline(cin, phone);
	cout << "Email: "; getline(cin, email);
	cout << "Gioi tinh (0.Nam , 1.Nu): "; cin >> gender; 
	cin.ignore();
	cout << "Vi tri cong viec (manager hay sales): "; getline(cin, pos);
	if(pos == "manager") position = manager;
	else position = sales;
	// cho them vong lap neu nhap sai
	cout << "Dat mat khau: "; getline(cin,pass);
	Employee newEmp(name,phone,email,address,ID,gender,position,salary,pass);
	this->Emp.addHead(newEmp);
}
void EmpManage::remove(Employee& emp){
    this->Emp.remove(emp); 
}
void EmpManage::display(){
    this->Emp.display();
}
void EmpManage::update(Employee& emp) {

    int ID = emp.getID();
    Employee& _employee = this->find(ID)->data;
    int input;
    int choice = 1;
    int MaxChoice = 7;

    do {
        system("cls");
        cout << "Nhap thong tin nhan vien:" << endl;
        cout << (choice == 1 ? "->" : "  ") << "Ten: " << _employee.getName() << endl;
        cout << (choice == 2 ? "->" : "  ") << "SDT: " << _employee.getPhone() << endl;
        cout << (choice == 3 ? "->" : "  ") << "Email: " << _employee.getEmail() << endl;
        cout << (choice == 4 ? "->" : "  ") << "Gioi tinh: " << (_employee.getGender() ? "Nu" : "Nam") << endl;
        cout << (choice == 5 ? "->" : "  ") << "Dia chi: " << _employee.getAddress() << endl;
        cout << (choice == 6 ? "->" : "  ") << "Luong: " << _employee.getSalary() << endl;
        cout << (choice == 7 ? "->" : "  ") << "Thoat" << endl;
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
        double salary;

        if (input == 13) {
            switch (choice) {
                case 1:
                    cout << "Nhap ten moi: ";
                    getline(cin, name);
                    _employee.setName(name);
                    break;
                case 2:
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, phone);
                    _employee.setPhone(phone);
                    break;
                case 3:
                    cout << "Nhap email moi: ";
                    getline(cin, mail);
                    _employee.setEmail(mail);
                    break;
                case 4:
                    cout << "Nhap gioi tinh (1: Nu, 0: Nam): ";
                    cin >> gender;
                    cin.ignore(); 
                    _employee.setGender(gender);
                    break;
                 case 5:
                    cout << "Nhap dia chi moi: ";
                    getline(cin, adress);
                    _employee.setAddress(adress);
                    break;    
                case 6:
                	cout << "Nhap luong: ";
                	cin >> salary;
                	_employee.setSalary(salary);
                	break;
                case 7:
                    cout << "Da thoat khoi cap nhat" << endl;
                    return;
                default:
                    cout << "Loi du lieu" << endl;
            }
        }
    } while (input != '0');
}

Node<Employee>* EmpManage::find(int& ID)
{
    Employee tempEmp;
    tempEmp.setID(ID);
    return this->Emp.find(tempEmp);
}
Node<Employee>* EmpManage::find(string& name, string& phone)
{
    Node<Employee>* Found = nullptr;
    if( name == "x" && phone == "x" ) return Found;
    Node<Employee>* tempNode;
    tempNode = this->Emp.getHead();
    while (tempNode != nullptr) 
    {
        if ( ( tempNode->data.getName() == name || name == "x" ) && ( tempNode->data.getPhone() == phone || phone == "x" ) ) 
            Found = tempNode;
        tempNode = tempNode->next;
    }
    return Found;
}

int EmpManage::getNewID()
{
    Node<Employee>* Nemp = this->Emp.getHead();
    if(Nemp == nullptr) return 10000;
    return Nemp->data.getID() + 1;
}


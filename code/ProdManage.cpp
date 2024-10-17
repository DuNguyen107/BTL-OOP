#include"ProdManage.h"

ProdManage::ProdManage(){}
ProdManage::~ProdManage(){}
void ProdManage::readFile(string file){
	string ID, name, CPU, screen, GPU, OS, brand, serial;
	double price, importPrice;
	int RAM, hardDisk, quantity;
	ifstream inputFile(file);
	if(inputFile.is_open()){
		string line;
		while(getline(inputFile, line)){
			istringstream iss(line);
            getline(iss, ID, '|');
            getline(iss, name, '|');
            getline(iss, brand, '|');
            iss >> price;
            iss.ignore(); 
            iss >> importPrice;
            iss.ignore(); 
            getline(iss, CPU, '|');
            iss >> RAM;
            iss.ignore(); 
            getline(iss, screen, '|');
            iss >> hardDisk;
            iss.ignore(); 
            getline(iss, GPU, '|');
            getline(iss, OS, '|');
			Product newProd(ID, name, price, importPrice, CPU, RAM, screen, hardDisk, GPU , OS, brand);
			iss >> quantity;
            iss.ignore(); 
            for (int i = 0; i < quantity; i++){
                getline(iss, serial, ',');
                newProd.addSerial(serial);
            }
            this->Prod.addTail(newProd);
		}
		inputFile.close();
	}else
		cerr << "Khong the mo file" << file << endl;
}
void ProdManage::writeFile(string file){
	ofstream outputFile(file, ios::out | ios::trunc);
	if (outputFile.is_open()){
        for (Node<Product>* current = this->Prod.getHead(); current != nullptr; current = current->next) {
            Product currentProd = current->data;
            outputFile << currentProd.getID() << "|";
            outputFile << currentProd.getName() << "|";
            outputFile << currentProd.getBrand() << "|";
            outputFile << currentProd.getPrice() << "|";
            outputFile << currentProd.getImportPrice() << "|";
            outputFile << currentProd.getCPU() << "|";
            outputFile << currentProd.getRAM() << "|";
            outputFile << currentProd.getScreen() << "|";
            outputFile << currentProd.getHardDisk() << "|";
            outputFile << currentProd.getGPU() << "|";
            outputFile << currentProd.getOS() << "|";
            outputFile << currentProd.getQuantity() << "|";

            Node<string>* serials = current->data.getSerial().getHead();
            while (serials != nullptr) {
                outputFile << serials->data << ",";
                serials = serials->next;
            }
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cerr << "Khong the ghi du lieu" << endl;
    }
}
void ProdManage::add(const Product& prod){
	this->Prod.addHead(prod);
}
void ProdManage::add(){
	Product prod;
    string ID, name, CPU, screen, GPU, OS, brand;
	double price, importPrice;
	int RAM, hardDisk;
    cout << "Nhap thong tin san pham:" << endl;
    cout << "Ma san pham: "; cin >> ID; 
	prod.setID(ID); cin.ignore();
    cout << "Ten san pham: "; getline(cin, name);
	prod.setName(name);
    cout << "Hang: "; getline(cin, brand);
	prod.setBrand(brand);
    cout << "Gia ban: "; cin >> price;
	prod.setPrice(price); cin.ignore();
    cout << "Gia nhap: "; cin >> importPrice;
	prod.setImportPrice(importPrice); cin.ignore();
    cout << "CPU: "; getline(cin, CPU);
	prod.setCPU(CPU);
    cout << "Ram: "; cin >> RAM;
	prod.setRAM(RAM); cin.ignore();
    cout << "Man hinh: "; getline(cin, screen);
	prod.setScreen(screen);
    cout << "O cung: "; cin >> hardDisk;
	prod.setHardDisk(hardDisk); cin.ignore();
    cout << "GPU: "; getline(cin, GPU); 
	prod.setGPU(GPU);
    cout << "He dieu hanh: "; getline(cin, OS); 
	prod.setOS(OS);
    this->Prod.addHead(prod);
}
void ProdManage::remove(Product& prod){
	this->Prod.remove(prod);
}
void ProdManage::update(Product& prod){
	string ID = prod.getID();
    Product& product = this->find(ID)->data;
    bool over = false;
    int input, option = 1, MaxOption = 11;
    do{
        system("cls");
        cout<<"Chon thong tin muon thay doi:"<< endl;
            cout << (option == 1 ? "->":"  ") << "Ten san pham: " << product.getName() << endl;
            cout << (option == 2 ? "->":"  ") << "Hang: " << product.getBrand() << endl;
            cout << (option == 3 ? "->":"  ") << "Gia ban: " << product.getPrice() << endl;
            cout << (option == 4 ? "->":"  ") << "Gia nhap: " << product.getImportPrice() << endl;
            cout << (option == 5 ? "->":"  ") << "CPU: " << product.getCPU() << endl;
            cout << (option == 6 ? "->":"  ") << "RAM: " << product.getRAM() << " GB" << endl;
            cout << (option == 7 ? "->":"  ") << "Man hinh: " << product.getScreen() << endl;
            cout << (option == 8 ? "->":"  ") << "O cung: " << product.getHardDisk() << " GB" << endl;
            cout << (option == 9 ? "->":"  ") << "GPU: " << product.getGPU() << endl;
            cout << (option == 10 ? "->":"  ") << "He Dieu Hanh: " << product.getOS() << endl;
            cout << (option == 11 ? "->":"  ") << "Thoat! " << endl;
            input = getch();

            if (input == 80) //phim mui ten xuong
            { 
                if (option == MaxOption) option = 1; // quay tro lai dau danh sach
                else option++;
            }else if (input == 72) //phim mui ten len
            {
                if (option == 1) option = MaxOption; //chay vong xuong cuoi danh sach
                else option--;
            }

        if(input == 13)  //phim enter
        {
            string _name;
            unsigned int _price;
            unsigned int _iprice;
            string _CPU;
            int _RAM = 0;
            string _Screen;
            int _Disk;
            string _GPU;
            string _OS;
            string _brand;
            switch (option)
            {
                case 1:
                    cout << "Nhap ten san pham: ";
                    getline(cin, _name);
                    product.setName(_name);
                    break;
                case 2:
                    cout << "Nhap hang: ";
                    cin >> _brand;
                    product.setBrand(_brand);
                    break;    
                case 3:
                    cout << "Nhap gia ban : ";
                    cin >> _price;
                    product.setPrice(_price);
                    break;
                case 4:
                    cout << "Nhap gia nhap: ";
                    cin >> _iprice;
                    product.setImportPrice(_iprice);
                    break;
                case 5:
                    cout << "Cap nhat CPU: ";
                    getline(cin,_CPU);
                    product.setCPU(_CPU);
                    break;
                case 6:
                    cout << "Cap nhat dung luong RAM (GB): ";
                    cin >> _RAM;
                    product.setRAM(_RAM);
                    break; 
                case 7:
                    cout << "Cap nhat thong so man hinh: ";
                    getline(cin,_Screen);
                    product.setScreen(_Screen);
                    break;                      
                case 8:
                    cout << "Cap nhat dung luong o cung (GB): ";
                    cin >> _Disk;
                    product.setHardDisk(_Disk);
                    break;                      
                case 9:
                    cout << "Cap nhat GPU moi: ";
                    getline(cin,_GPU);
                    product.setGPU(_GPU);
                    break;
                case 10:
                    cout << "Cap nhat He dieu hanh: ";
                    getline(cin,_OS);
                    product.setOS(_OS);
                    break;                                                   
                case 11:
                    over = true;
                    break;
                default: 
					cout << "Loi du lieu";
            }
        }
    }while (over != true);
}
void ProdManage::display(){
	this->Prod.display();
}
void ProdManage::display(bool type){  // true: tang dan, false: giam dan
	List<Product> sortPrice = this->Prod;
	sortPrice.mergeSort(type);
	sortPrice.display();
} 
void ProdManage::displayOption(){
	int input;
    int option = 1;
    do{
        system("cls");
        cout << ((option == 1) ? "->" : "  ") << "Tat ca san pham" << endl;
        cout << ((option == 2) ? "->" : "  ") << "Xem theo gia tang" << endl;
        cout << ((option == 3) ? "->" : "  ") << "Xem theo gia giam" << endl;
        cout << ((option == 4) ? "->" : "  ") << "Huy" << endl;
        input = getch();
        if (input == 72) option--;
        else if (input == 80) option++;
        if (option < 1) option = 4;
        if (option > 4) option = 1;
    }while(input != 13);
    switch (option){
        case 1: 
            this->display();
            break;
        case 2:
            this->display(true);
            break;
        case 3:
            this->display(false);
            break;
    }
}
Node<Product>* ProdManage::find(string& ID){
	Product temp;
    temp.setID(ID);
    return this->Prod.find(temp);
}
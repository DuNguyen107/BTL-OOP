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
            outputFile << currentProd.getID() << "|"
            << currentProd.getName() << "|"
            << currentProd.getBrand() << "|"
            << fixed << setprecision(0) << currentProd.getPrice() << "|"
            << fixed << setprecision(0) << currentProd.getImportPrice() << "|"
            << currentProd.getCPU() << "|"
            << currentProd.getRAM() << "|"
            << currentProd.getScreen() << "|"
            << currentProd.getHardDisk() << "|"
            << currentProd.getGPU() << "|"
            << currentProd.getOS() << "|"
            << currentProd.getQuantity() << "|";

            Node<string>* serials = current->data.getSerial().getHead();
            while (serials != nullptr) {
                outputFile << serials->data << ",";
                serials = serials->next;
            }
            outputFile << endl;
        }
        outputFile.close();
    } else {
        cerr << "Không thể ghi dữ liệu" << endl;
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
	cout << setw(50) << " " << string(60, '=') << endl;
    cout << setw(70) << " " << "NHẬP THÔNG TIN SẢN PHẨM" << endl;
    cout << setw(50) << " " << string(60, '-') << endl;
    cout << string(55, ' ') << "Mã sản phẩm: "; cin >> ID; 
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setID(ID); cin.ignore();
    cout << string(55, ' ') << "Tên sản phẩm: "; getline(cin, name);
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setName(name);
    cout << string(55, ' ') << "Thương hiệu: "; getline(cin, brand);
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setBrand(brand);
    cout << string(55, ' ') << "Giá bán: "; cin >> price;
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setPrice(price); cin.ignore();
    cout << string(55, ' ') << "Giá nhập: "; cin >> importPrice;
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setImportPrice(importPrice); cin.ignore();
    cout << string(55, ' ') << "CPU: "; getline(cin, CPU);
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setCPU(CPU);
    cout << string(55, ' ') << "RAM: "; cin >> RAM;
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setRAM(RAM); cin.ignore();
    cout << string(55, ' ') << "Màn hính: "; getline(cin, screen);
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setScreen(screen);
    cout << string(55, ' ') << "Ổ cứng: "; cin >> hardDisk;
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setHardDisk(hardDisk); cin.ignore();
    cout << string(55, ' ') << "GPU: "; getline(cin, GPU); 
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setGPU(GPU);
    cout << string(55, ' ') << "Hệ điều hành: "; getline(cin, OS); 
    cout << setw(50) << " " << string(60, '-') << endl;
	prod.setOS(OS);
	cout << setw(70) << " " << "THÊM SẢN PHẨM THÀNH CÔNG" << endl;
	cout << setw(50) << " " << string(60, '=') << endl;
    this->Prod.addHead(prod);
}
Node<Product>* ProdManage::find(string& ID){
	Product temp;
    temp.setID(ID);
    return this->Prod.find(temp);
}
void ProdManage::remove(Product& prod){
	this->Prod.remove(prod);
}
void ProdManage::update(Product& prod){
	string ID = prod.getID();
    Product& product = this->find(ID)->data;
    bool over = false;
    int option;
    do{
        system("cls");
        cout << setw(50) << " " << string(60, '=') << endl;
        cout << setw(50) << " " << " 1. Tên sản phẩm - " << product.getName() << endl;
        cout << setw(50) << " " << " 2. Thương hiệu - " << product.getBrand() << endl;
        cout << setw(50) << " " << " 3. Giá bán - " << product.getPrice() << endl;
        cout << setw(50) << " " << " 4. Giá nhập - " << product.getImportPrice() << endl;
        cout << setw(50) << " " << " 5. CPU - " << product.getCPU() << endl;
        cout << setw(50) << " " << " 6. RAM - " << product.getRAM() << " GB" << endl;
        cout << setw(50) << " " << " 7. Màn hình - " << product.getScreen() << endl;
        cout << setw(50) << " " << " 8. Ổ cứng - " << product.getHardDisk() << " GB" << endl;
        cout << setw(50) << " " << " 9. GPU - " << product.getGPU() << endl;
        cout << setw(50) << " " << "10. Hệ điều hành - " << product.getOS() << endl;
        cout << setw(50) << " " << "11. Hủy" << endl;
        cout << setw(50) << " " << string(60, '=') << endl;
        
		cout << setw(50) << " " << "Nhập chức năng (thông tin) muốn thay đổi: "; cin >> option; cin.ignore();
		if(option < 1 || option > 11)
			cout << setw(50) << " " << "Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 11. \n"; 
		switch (option){
            case 1:{
            	cout << setw(50) << " " << string(60, '-') << endl;
                string _name;
            	cout << setw(50) << " " << "Chỉnh sửa tên sản phẩm: ";
                getline(cin, _name);
                product.setName(_name);
				break;
			}
            case 2:{
            	cout << setw(50) << " " << string(60, '-') << endl;
            	string _brand;
                cout << setw(50) << " " << "Chỉnh sửa thương hiệu: ";
                cin >> _brand;
                product.setBrand(_brand);
				break;
			}   
            case 3:{
            	cout << setw(50) << " " << string(60, '-') << endl;
	            double _price;
	            cout << setw(50) << " " << "Chỉnh sửa giá bán : ";
                cin >> _price;
                product.setPrice(_price);
				break;
			}
            case 4:{
            	cout << setw(50) << " " << string(60, '-') << endl;
                double _iprice;
                cout << setw(50) << " " << "Chỉnh sửa giá nhập: ";
                cin >> _iprice;
                product.setImportPrice(_iprice);
				break;
			}
            case 5:{
                string _CPU;
                cout << setw(50) << " " << "Chỉnh sửa CPU: ";
                getline(cin,_CPU);
                product.setCPU(_CPU);
				break;
			}
            case 6:{
                int _RAM = 0;
                cout << setw(50) << " " << "Cập nhật dung lượng RAM (GB): ";
                cin >> _RAM;
                product.setRAM(_RAM);
				break;
			}
            case 7:{
                string _Screen;
                cout << setw(50) << " " << "Cập nhật thông số màn hình: ";
                getline(cin,_Screen);
                product.setScreen(_Screen);
				break;
			}                     
            case 8:{
                int _Disk;
                cout << setw(50) << " " << "Cập nhật dung lượng ổ cứng (GB): ";
                cin >> _Disk;
                product.setHardDisk(_Disk);
				break;
			}                     
            case 9:{
                string _GPU;
                cout << setw(50) << " " << "Cập nhật GPU mới: ";
                getline(cin,_GPU);
                product.setGPU(_GPU);
				break;
			}
            case 10:{
                string _OS;
                cout << setw(50) << " " << "Cập nhật hệ điều hành: ";
                getline(cin,_OS);
                product.setOS(_OS);
				break;
			}                                                   
            case 11:
                over = true;
                break;
            default: 
				cout << setw(50) << " " << "Lỗi dữ liệu !!\n";
        }
    }while (over != true);
}
void ProdManage::display(){
	this->Prod.display();
}
void ProdManage::display(bool type){  // true: tang dan, false: giam dan
	List<Product> sort = this->Prod;
	sort.mergeSort(type);
	sort.display();
} 
void ProdManage::displayOption(int option){
    switch (option){
        case 1: 
            this->display();
            break;
        case 2:
            this->display(false);
            break;
        case 3:
            this->display(true);
            break;
        case 4:
        	break;
    }
}


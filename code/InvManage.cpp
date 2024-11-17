#include"InvManage.h"

InvManage::InvManage()
{ }
InvManage::~InvManage()
{ }
void InvManage::add(const Invoice& inv){
	this->Inv.addHead(inv);
}
void InvManage::remove(Invoice& inv){
	cout << endl << endl;
	cout << setw(60) << " " << "Không thể xóa hóa đơn !!" << endl;
}
void InvManage::update(Invoice& inv){
	cout << endl << endl;
	cout << setw(60) << " " << "Không thể chỉnh sửa hóa đơn !!" << endl;
}
void InvManage::display(){
	this->Inv.display();
}
List<Invoice>* InvManage::find(int& day, int& month, int& year){
	List<Invoice>* tempList = new List<Invoice>();
    Node<Invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getDay() == day
			&& tempNode->data.getDate().getMonth() == month
			&& tempNode->data.getDate().getYear() == year)   
            tempList->addHead(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList->getHead() == nullptr ){
    	delete tempList;
    	return nullptr;
	}
    return tempList;
}
List<Invoice>* InvManage::find(int& month, int& year){
	List<Invoice>* tempList = new List<Invoice>();
    Node<Invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getMonth() == month
		&& tempNode->data.getDate().getYear() == year)   
            tempList->addHead(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList->getHead() == nullptr ){
    	delete tempList;
    	return nullptr;
	}
    return tempList;
}
List<Invoice>* InvManage::find(int& year){
	List<Invoice>* tempList = new List<Invoice>();
    Node<Invoice>* tempNode;
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getDate().getYear() == year)   
            tempList->addHead(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList->getHead() == nullptr ){
    	delete tempList;
    	return nullptr;
	}
    return tempList;
}
List<Invoice>* InvManage::find(Customer& cus){ // tim theo khach hang
	List<Invoice>* tempList = new List<Invoice>();
    Node<Invoice>* tempNode;
    int cusID = cus.getID();
    tempNode = this->Inv.getHead();
    while (tempNode != nullptr) 
    {
        if (tempNode->data.getCusID() == cusID)   
            tempList->addHead(tempNode->data);
        tempNode = tempNode->next;
    }
    if ( tempList->getHead() == nullptr ) {
    	delete tempList;
    	return nullptr;
	}
    return tempList;
}
Node<Invoice>* InvManage::findID(int& ID){ // mỗi ID là duy nhất
	Invoice tempInv; 
    tempInv.setInvID(ID);
    return this->Inv.find(tempInv);
}
void InvManage::statistic(List<Invoice>* list, ProdManage& prodM){ // thống kê dựa trên danh sách hóa đơn
	if(list == nullptr) return;
	double revenue = 0; //doanh thu
    double profit = 0; //loi nhuan
    double sales = 0; //so luong san pham ban duoc 
	Node<Invoice>* tempNode;
    tempNode = list->getHead();
    while (tempNode != nullptr){
        revenue += tempNode->data.getTotal();
        profit += tempNode->data.getProfit(prodM);
        sales += tempNode->data.productSales();
        tempNode = tempNode->next;
    }
	cout << setw(50) << " " << string(60, '=') << endl;
    cout << left << setw(60) << " " << "Doanh thu: " << fixed << setprecision(0) << revenue << " VND" <<endl;
    cout << setw(50) << " " << string(60, '=') << endl;
    cout << left << setw(60) << " " << "Lợi nhuận: " << fixed << setprecision(0) << profit << " VND" << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
    cout << left << setw(60) << " " << "Sản phẩm bán được: " << fixed << setprecision(0) << sales << endl;
    cout << setw(50) << " " << string(60, '=') << endl;
    delete tempNode;
}
void InvManage::printInvoice(int invID, CusManage cusM){
	string filePath = "invoice/";
    filePath += "invoice_" + to_string(invID) + ".txt";
    ofstream outfile(filePath);
    if (!outfile.is_open()) {
        cerr << "Lỗi khi mở file !!" << endl;
        return;
    }

    Invoice inv = this->findID(invID)->data;
    int cusID = inv.getCusID();
    Customer cus = cusM.find(cusID)->data;

	outfile << setw(8) << " " << setfill('-') << setw(152) << "" << endl << setfill(' ');
	outfile << setw(8) << " " << "|" << setw(83) << right << "HÓA ĐƠN BÁN HÀNG" << setw(73) << right << "|" << endl;
 
    outfile << setw(8) << " " << "|Mã hóa đơn: " << setw(138) << left << inv.getInvID() << "|" << endl;
    string date = to_string(inv.getDate().getDay()) + "/" + to_string(inv.getDate().getMonth()) + "/" + to_string(inv.getDate().getYear());
	outfile << setw(8) << " " << "|Ngày bán: " << setw(140) << date <<"|" << endl;
    outfile << setw(8) << " " << "|Mã khách hàng: " << setw(135) << left << inv.getCusID() << "|" << endl;
    outfile << setw(8) << " " << "|Tên khách hàng: " << setw(134) << left << cus.getName() << "|" << endl;
    outfile << setw(8) << " " << "|Số điện thoại: " << setw(135) << left << cus.getPhone() << "|" << endl;
    outfile << setw(8) << " " << "|Email: " << setw(143) << left << cus.getEmail() << "|" << endl;
    outfile << setw(8) << " " << "|Địa chỉ: " << setw(141) << left << cus.getAddress() << "|" << endl;
    outfile << setw(8) << " " << "|" << setw(150) << " " << "|"  << endl;
    outfile << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    outfile << setw(8) << " " << "|" << setw(3) << left << "STT";
    outfile << setw(23) << left << "|Mã sản phẩm";
    outfile << setw(56) << left << "|Tên sản phẩm";
    outfile << setw(3) << left << "|SL";
    outfile << setw(51) << left << "|Số serial";
    outfile << setw(16) << left << "|Đơn giá";
    outfile << setw(16) << left << "|Thành tiền" << "|"<< endl;
    outfile << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    int i = 0;
    string serial = "";
    for (Node<order>* Norder = inv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next){
        outfile << setw(8) << " " << "|" << setw(3) << left << ++i;
        outfile << "|" << setw(17) << left << Norder->data.getID();
        outfile << "|" << setw(50) << left << Norder->data.getName();
        outfile << "|" << setw(2) << left << Norder->data.getQuantity();
        serial = "";
        for (Node<string>* Nstring = Norder->data.getSerial().getHead(); Nstring != nullptr; Nstring = Nstring->next)
        {
            serial += Nstring->data;
            serial += ",";
        }
        outfile << "|"<< setw(48) << left << serial;
        outfile << "|" << setw(12) << left << fixed << setprecision(0) << Norder->data.getPrice();
        outfile << "|" << setw(12) << left << fixed << setprecision(0) << Norder->data.getTotal() << "|"<< endl;
        outfile << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    }
    outfile << setw(8) << " " << "|" << setw(142) << right << "Tổng tiền: " << setw(8) << left << inv.getTotal() << " VNĐ" << "|"<< endl;
    outfile << setw(8) << " " << "|" << "Thanh toán: " << setw(138) << left << inv.getPayment() << "|" << endl;
    outfile << setw(8) << " " << setfill('-') << setw(152) << "" << endl << setfill(' ') ;
    outfile.close();
    //in hoa don ra ma hinh
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << "Không thể mở file để đọc !!" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
void InvManage::printInvoice(Invoice& inv, CusManage cusM){
	int cusID = inv.getCusID();
    Customer cus = cusM.find(cusID)->data;
	cout << setw(8) << " " << setfill('-') << setw(152) << "" << endl << setfill(' ') ;
	cout << setw(8) << " " << "|" << setw(83) << right << "HÓA ĐƠN BÁN HÀNG" << setw(73) << right << "|" << endl;
    
    cout << setw(8) << " " << "|Mã hóa đơn: " << setw(138) << left << inv.getInvID() << "|" << endl;
    string date = to_string(inv.getDate().getDay()) + "/" + to_string(inv.getDate().getMonth()) + "/" + to_string(inv.getDate().getYear());
    cout << setw(8) << " " << "|Ngày bán: " << setw(140) << date <<"|" << endl;
    cout << setw(8) << " " << "|Mã khách hàng: " << setw(135) << left << inv.getCusID() << "|" << endl;
    cout << setw(8) << " " << "|Tên khách hàng: " << setw(134) << left << cus.getName() << "|" << endl;
    cout << setw(8) << " " << "|Số điện thoại: " << setw(135) << left << cus.getPhone() << "|" << endl;
    cout << setw(8) << " " << "|Email: " << setw(143) << left << cus.getEmail() << "|" << endl;
    cout << setw(8) << " " << "|Địa chỉ: " << setw(141) << left << cus.getAddress() << "|" << endl;
    cout << setw(8) << " " << "|" << setw(150) << " " << "|"  << endl;
    cout << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    cout << setw(8) << " " << "|" << setw(3) << left << "STT";
    cout << setw(23) << left << "|Mã sản phẩm";
    cout << setw(56) << left << "|Tên sản phẩm";
    cout << setw(3) << left << "|SL";
    cout << setw(51) << left << "|Số serial";
    cout << setw(16) << left << "|Đơn giá";
    cout << setw(16) << left << "|Thành tiền" << "|"<< endl;
    cout << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    int i = 0;
    string serial = "";
    for (Node<order>* Norder = inv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next)
    {
        cout << setw(8) << " " << "|" << setw(3) << left << ++i;
        cout << "|" << setw(17) << left << Norder->data.getID();
        cout << "|" << setw(50) << left << Norder->data.getName();
        cout << "|" << setw(2) << left << Norder->data.getQuantity();
        serial = "";
        for (Node<string>* Nstring = Norder->data.getSerial().getHead(); Nstring != nullptr; Nstring = Nstring->next)
        {
            serial += Nstring->data;
            serial += ",";
        }
        cout << "|"<< setw(48) << left << serial;
        cout << "|" << setw(12) << left << fixed << setprecision(0) << Norder->data.getPrice();
        cout << "|" << setw(12) << left << fixed << setprecision(0) << Norder->data.getTotal() << "|"<< endl;
        cout << setw(8) << " " << "|" << setfill('-') << setw(151) << right << "|" << endl << setfill(' ') ;
    }
    cout << setw(8) << " " << "|" << setw(142) << right << "Tổng tiền: " << setw(9) << left << fixed << setprecision(0) <<  inv.getTotal() << "VNĐ" << "|"<< endl;
    cout << setw(8) << " " << "|" << "Thanh toán: " << setw(140) << left << "Chưa thanh toán" << "|" << endl;
    cout << setw(8) << " " << setfill('-') << setw(152) << "" << endl << setfill(' ');
}
void InvManage::findtoShow(int& ID){ // tìm ID va in thông tin của ID
	string filePath = "invoice/";
    filePath += "invoice_" + to_string(ID) + ".txt";
    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cerr << setw(60) << " " << " (!) Không tìm thấy hóa đơn (!)" << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}
int InvManage::getNewID(){
	Node<Invoice>* Ninv = this->Inv.getHead();
    if(Ninv == nullptr) return 200;
    return Ninv->data.getInvID() + 1;
}
void InvManage::updateCart(Invoice& newInv, ProdManage& prodM, CusManage& cusM){
    int option;
    bool over = false;
    List<order> cart = newInv.getOrder();
    ProdManage temp;
    do 
    {
        do{
        	system("cls");
	        cart.display();   
	        cout << endl;
	        cout << setw(60) << " " << "+------------+" << endl;
	        cout << setw(60) << " " << "|  Giỏ hàng  | " << endl; 
	        cout << setw(60) << " " << "+--------------------------------------------+" << endl;
	        cout << setw(60) << " " << "|\t\t1. Thêm sản phẩm           	 |" << endl;
			cout << setw(60) << " " << "|\t\t2. Xóa sản phẩm            	 |" << endl;
			cout << setw(60) << " " << "|\t\t3. Thanh toán, xuất hóa đơn	 |" << endl;
			cout << setw(60) << " " << "|\t\t4. Quay lại                   	 |" << endl;
	        cout << setw(60) << " " << "+--------------------------------------------+\n" << endl;
			cout << setw(60) << " " << ">> Nhập chức năng cho giỏ hảng << ";
			cin >> option;	
			cout << endl;
			if(option < 1 || option > 4){
			    cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
				cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	
				cout << setw(60) << " " << "+---------------------------------+\n";
				cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				cout << setw(60) << " " << "+---------------------------------+\n";
				getch();
			}
		}while(option < 1 || option > 4);
        string prodID, pay;
        Node<Product>* Nprod;
        Node<order>* Norder;
        Node<string>* Nstring;
        order newOrder;
        int newQuantity, i;
        bool isSerial, check;
        string newSerial;
        switch (option){
            case 1:
            	prodM.displayOption(1);
                cout << endl << setw(60) << " " << ">> Nhập mã sản phẩm cần bán: ";
                cin >> prodID;
                Nprod = prodM.find(prodID);
                if(Nprod == nullptr){
                    cout << endl;
					cout << setw(60) << " " << "!! Không tìm thấy sản phẩm !! " << endl;
                    system("pause");
                    break;
                }
                if(Nprod->data.getQuantity() < 1){
                    cout << endl;
					cout << setw(60) << " " << "!! Sản phẩm này đã hết hàng !! "<< endl;
                    system("pause");
                    break;
                } 
                Norder = newInv.findOrder(prodID);
                //neu loai san pham chua co trong hoa don thi tao neworder
                if(Norder == nullptr)
                {   
                    newOrder.setID(prodID);
                    newOrder.setName(Nprod->data.getName());
                    newOrder.setPrice(Nprod->data.getPrice());
                }
                do{
                	cout << endl;
                	cout << setw(60) << " "  << "Nhập số lượng sản phẩm cần bán: ";
                    cin >> newQuantity;
                    if(newQuantity > Nprod->data.getQuantity()){
                    	cout << endl ;
						cout << setw(60) << " " << "Không đủ sản phẩm để bán !!" << endl;
					}
					if(newQuantity <= 0){
						cout << endl;
						cout << setw(60) << " " << "Vui lòng nhập đúng số lượng !!" << endl;
					}
                }while (newQuantity > Nprod->data.getQuantity() || newQuantity <= 0);
                for (int i = 1; i <= newQuantity ; i++){
                    do{
	                    cout << endl;
						cout << setw(60) << " " << "Nhập serial sản phẩm thứ " << i << ": ";
                    //kiem tra serial co ton tai trong database khong?
                        cin >> newSerial;
                        isSerial = Nprod->data.isSerial(newSerial);
                        if(!isSerial){
                        	cout << endl;
                        	cout << setw(60) << " "  << "Không tồn tại serial này !! " << endl;
						}
                    }while(!isSerial);
                    //dua serial tu san pham ra gio hang
                    Nprod->data.removeSerial(newSerial); 
                    if(Norder == nullptr){
                        newOrder.addSerial(newSerial);
                        newOrder.updateTotal();
                    }
                    else{
                        Norder->data.addSerial(newSerial);
                        Norder->data.updateTotal();
                    }
                    cout << setw(60) << " " << string(46, '-') << endl;
                    cout << setw(60) << " " <<"THÊM THÀNH CÔNG SẢN PHẨM " << newSerial << endl;
                    cout << setw(60) << " " << string(46, '-') << endl;
                }
                if(Norder == nullptr) newInv.addOrder(newOrder);
                system("pause");
                break;
            case 2:
				cout << setw(60) << " " << "Nhập mã sản phẩm cần xóa: ";
	            cin >> prodID;
	            Norder = newInv.findOrder(prodID);
	            if(Norder == nullptr){
		            cout << endl ;
					cout << setw(60) << " " << "Không có sản phẩm này trong giỏ hàng\n";
		            system("pause");
		            break;
	            }
	            Nprod = prodM.find(prodID);
	            cout << endl ;
				cout << setw(60) << " " << "Nhập 0 để xóa tất cả sản phẩm " << Norder->data.getName() << endl;
	            cout << setw(60) << " " << "Hoặc nhập vào số serial của sản phẩm cần xóa: ";
	            cin >> newSerial;
	            if (newSerial == "0"){   
	                Nstring = Norder->data.getSerial().getHead();
	                while (Nstring != nullptr) {
	                    Nprod->data.addSerial(Nstring->data);
	                    Nstring = Nstring->next;
	                }
	                newInv.getOrder().remove(Norder->data);
	                cout << endl;
	                cout << setw(60) << " " << "XÓA THÀNH CÔNG" << endl;
	                system("pause");
	            }    
	            else{
	                if(Norder->data.isSerial(newSerial)){
	                    Norder->data.removeSerial(newSerial);
	                    cout << setw(60) << " " << "XÓA THÀNH CÔNG" << endl;
	                        // thêm lại seri vừa xóa vào sản phẩm
	                    Nprod->data.addSerial(newSerial);
	                }
	                else{
	                    cout << endl ;
						cout << setw(60) << " " << "Không có sản phẩm mang số serial " << newSerial << " trong giỏ hảng !!\n";
	                    system("pause");
	                }  
				}
				// xoa hoa don vua tao khi xoa het san pham 
	            if(Norder->data.getQuantity() == 0) newInv.getOrder().remove(Norder->data);
                break;
            case 3:{
            	int option;
                if(newInv.getOrder().getHead() == nullptr){
                    cout << setw(70) << " " << "HÓA ĐƠN RỖNG"; 
                    cout << endl;
                    system("pause");
                }
                else{
                    newInv.updateTotal();
//                    this->printInvoice(newInv, cusM);
                    cout << endl << endl << endl;
                    do{
                    	system("cls");
                    	cout << endl;
                    	cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                        cout << setw(60) << " " << "|\t\t1. Xác nhận thanh toán          |" << endl;
                        cout << setw(60) << " " << "|\t\t2. Trở về                       |" << endl;
                        cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                        cout << setw(60) << " " << ">> Nhập chức năng << "; cin >> option;
                        cout << endl;
                        if(option < 1 || option > 2)
                            cout << setw(60) << " " << "Vui lòng nhập đúng chức năng !!" << endl;
                    }while(option < 1 || option > 2);
                    if(option == 1){
                        cout << setw(60) << " " << "Tổng giá trị đơn hàng là: " << fixed << setprecision(0) << newInv.getTotal() << " VNĐ" << endl ;
						cout << setw(60) << " " << "Phương thức thanh toán" << endl;
						int next_option;
						do{
							cout << setw(60) << " " << "+" << string(25, '-') << endl;
							cout << setw(60) << " " << "|\t1. Tiền mặt          |\n";
							cout << setw(60) << " " << "|\t2. Chuyển khoản      |\n";
							cout << setw(60) << " " << "|\t3. Hủy thanh toán    |\n";
							cout << setw(60) << " " << "+" << string(25, '-') << endl;
							cout << setw(60) << " " << ">> Chọn phương thức thanh toán << ";
							cin >> next_option;
							if(next_option < 1 || next_option > 3){
								cout << setw(60) << " "   << "Vui lòng nhập đúng chức năng !! \n";
								system("pause");
							}
						}while(next_option < 1 || next_option > 3);
						if(next_option == 3) break;
						if(next_option == 1) pay = "tien mat";
						else pay = "chuyen khoan";
                        newInv.setPayment(pay);
                        newInv.complete();
                        this->add(newInv);
                        system("cls");
                        cout << endl << setw(70) << " "   << "THANH TOÁN THÀNH CÔNG" << endl;
                        this->printInvoice(newInv.getInvID(),cusM);
                        cout << endl << endl;
                        system("pause");
                    }
                }
				break;
			}
            case 4:
                over = true;
                break;
                default: cout << "Lỗi dữ liệu\n";
            }
    } while(!over);
}
void InvManage::sell(CusManage& cusM, ProdManage& prodM,int& option){
	Invoice newInvoice;
    int cusID;
    int id = this->getNewID();
    newInvoice.setInvID(id);
    //lay thong tin khach hang
    Customer newcus;
	char t;
//	CusManage& customerManage = myDatabase.getCusManage();
	if(option == 1){
		newcus = Customer(); //lam moi gia tri cua newcus
	    newcus.setID(cusM.getNewID());
	    cusM.add(newcus);
	    cusID = newcus.getID();
	    cusM.update(newcus);
	}else{
		do{
			system("cls");
			cout << endl;
			cusM.display(); 
			cout << endl;
			cout << setw(30) << " " << "- Nhấn ESC để quay lại\n" << endl;
			cout << setw(30) << " " << "- Nhấn Enter để nhập\n" << endl;
			t = getch();
			if(t == 27){
				option = 0;
				break;
			}else if (t == 13){
				cout << setw(60) << " " << ">> Nhập mã khách hàng: ";
				cin >> cusID;
				if(cin.fail()){
					cin.clear(); 
        			cin.ignore(1000, '\n');
				}
			}
			if(cusM.find(cusID) == nullptr){
                cout << endl << setw(60) << " " << "Không có thông tin khách hàng này !! " << endl;
                system("pause");
            }else{
            	break;
			}
		}while(1);
	}
	if(t != 27){
		newInvoice.setCusID(cusID);
		newInvoice.updateDate(); //cap nhat thoi gian cho hoa don
		    //Tuong tac voi gio hang
		this->updateCart(newInvoice,prodM,cusM);
	}
}
void InvManage::readFile(string file, string detail_file){
	ifstream inputFile(file);
    int ID, cusID, day, month, year;
    double total;
    Date date;
    string temp, payment;
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line)){
            istringstream iss(line);
            getline(iss, temp, '|');
            ID = stoi(temp);
            getline(iss, temp, '|');
            cusID = stoi(temp);
            getline(iss, temp, '/');
            day = stoi(temp);
            getline(iss, temp, '/');
            month = stoi(temp);
            getline(iss, temp, '|');
            year = stoi(temp);
            getline(iss, temp, '|');
            total = stod(temp);
            getline(iss, payment, '|');
            date.setDay(day); date.setMonth(month); date.setYear(year);
            Invoice newInv(ID, cusID, total, payment, date);
            this->Inv.addTail(newInv);
        }
        inputFile.close();
    } else {
        cerr << "Không thể mở file " << file << endl; //bao loi
    }
    ifstream inputFileOrder(detail_file);
    string productID, name, serial;
    double price;
    int quantity;
    if (inputFileOrder.is_open()) 
    {
        string line;
        while (getline(inputFileOrder, line))
        {
            istringstream iss(line);
            iss >> ID;
            iss.ignore(); 
            getline(iss, productID, '|');
            getline(iss, name, '|');
            iss >> price;
            iss.ignore(); 
            iss >> total;
            iss.ignore(); 
            order neworder(productID, name, price, total);
            iss >> quantity;
            iss.ignore(); 
            for(int i = 0; i < quantity; i++)
            {
                getline(iss, serial, ',');
                neworder.addSerial(serial);
            }
            Node<Invoice>* found = this->findID(ID);
            if(found != nullptr) 
            {
                found->data.getOrder().addTail(neworder);
            }
            else cout << endl << "Lỗi dữ liệu! Không tìm thấy hóa đơn " << ID << endl;
        }
        for( Node<Invoice>* Ninv = this->Inv.getHead(); Ninv != nullptr; Ninv = Ninv->next)
        {
            Ninv->data.complete(); //dua hoa don ve trang thai hoan thanh;
        }
        inputFileOrder.close();
    } else {
        cerr << "Không thể mở file " << file << endl; //bao loi
    }
}
void InvManage::writeFile(string file, string detail_file){
	ofstream outputInvoice(file, ios::out | ios::trunc);
    ofstream outputOrderDetail(detail_file, ios::out | ios::trunc);
    if (outputInvoice.is_open() && outputOrderDetail.is_open())
    {
        for (Node<Invoice>* current = this->Inv.getHead(); current != nullptr; current = current->next) 
        {
            Invoice currentInv = current->data;
            outputInvoice << currentInv.getInvID() << "|";
            outputInvoice << currentInv.getCusID() << "|";
            outputInvoice << currentInv.getDate() << "|";
            outputInvoice << fixed << setprecision(0) << currentInv.getTotal() << "|";
            outputInvoice << currentInv.getPayment() << "|";
            outputInvoice << endl;
            for (Node<order>* Norder = currentInv.getOrder().getHead(); Norder != nullptr; Norder = Norder->next)
            {
               order currentOrder = Norder->data;
               outputOrderDetail << currentInv.getInvID() << "|";
               outputOrderDetail << currentOrder.getID() << "|";
               outputOrderDetail << currentOrder.getName() << "|";
               outputOrderDetail << fixed << setprecision(0) << currentOrder.getPrice() << "|";
               outputOrderDetail << fixed << setprecision(0) << currentOrder.getTotal() << "|";
               outputOrderDetail << currentOrder.getQuantity() << "|";
               Node<string>* serial = currentOrder.getSerial().getHead();
               while(serial != nullptr)
               {
                    outputOrderDetail << serial->data << ",";
                    serial = serial->next;
               }
                outputOrderDetail << endl;
            }
        }
        outputInvoice.close();
        outputOrderDetail.close();       
    } else
    {
        cerr << "Không thể ghi dữ liệu !!" << endl;
    }
}
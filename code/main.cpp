#include<string>
#include"windows.h"
#include <cstdlib> 
#include "CusManage.h"
#include "EmpManage.h"
#include "InvManage.h"
#include "ProdManage.h"
#include "Database.h"
using namespace std;
Database& myDatabase = Database::DB_Instance();
CusManage& customerManage = myDatabase.getCusManage();
EmpManage& employeeManage = myDatabase.getEmpManage();
ProdManage& productManage = myDatabase.getProdManage();
InvManage& invoiceManage = myDatabase.getInvManage();
void MenuManage();
void title();
int userID = 200;
Employee* user;
Node<Employee>* temp;

int main(){
	SetConsoleOutputCP(CP_UTF8);
    Database::readData();
    Database::saveData();
	MenuManage();	    
}
void title() {
	system("cls");
    cout << "+--------------------------------------------------------------------------------------+" << endl;
	cout << "|          ___                                                                         |" << endl;
    cout << "|  ______ (__ )         _      __                  _                 _                 |" << endl;
    cout << "| / ____/  (_/_        | |     \\_\\                | |               | |                |" << endl;
    cout << "|| |     _   ) )__,_   | |__   __,_ _,__   __,_   | |     __,_ _,__ | |_,___  _,__     |" << endl;
    cout << "|| |    | | | |/ _  |  |  _ \\ / _  |  _ \\ / _  |  | |    / _  |  _ \\| __/ _ \\|  _ \\    |" << endl;
    cout << "|| |____| |_| | (_| |  | | | | (_| | | | | (_| |  | |___| (_| | |_) | || (_) | |_) |   |" << endl;
    cout << "| \\_____ \\____|\\___,|  |_| |_|\___,_|_| |_|\___, |  |_____ \\__,_|  __/ \\__\\___/|  __/    |" << endl;
    cout << "|                                           _/ |              | |            | |       |" << endl;
    cout << "|                                          |__/               |_|            |_|       |" << endl;
    cout << "+--------------------------------------------------------------------------------------+" << endl;
    cout << setw(20) << " " << "|\t\t1. Thông tin cá nhân \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t2. Thống kê bán hàng \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t3. Quản lí sản phẩm  \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t4. Quản lí khách hàng \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t5. Bán hàng          \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t6. Lịch sử bán hàng  \t\t|" << endl;
    cout << setw(20) << " " << "|\t\t7. Thoát             \t\t|" << endl;
    cout << "+--------------------------------------------------------------------------------------+" << endl;
}
void MenuManage(){
    int option;
    bool over = false;
	int d, m, y;
    do{
    	title();
    	cout << setw(20) << " " << "+------------------------+----+\n";
    	cout << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
    	cout << setw(20) << " " << "+------------------------+----+\n";
    	gotoxy(48,21);
    	cin >> option;
    	if(option < 1 || option > 8){
    		cout << endl;
    		cout << setw(20) << " " << "+----------------------------------------------------------+\n";
	    	cout << setw(20) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 8. |\n"; 
	    	cout << setw(20) << " " << "+----------------------------------------------------------+\n";
	    	
	    	cout << setw(20) << " " << "+---------------------------------+\n";
	    	cout << setw(20) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
	    	cout << setw(20) << " " << "+---------------------------------+\n";
	    	gotoxy(57,27);
	    	getch();
		}
		switch(option){
			case 1:{
				system("cls");
                temp = employeeManage.find(userID);
				temp->data.getPassword();
				user = &(temp->data);
                user->Show();
                system("pause");
				break;
			}
			case 2:{
				int option;
                do{
                    system("cls");
                    cout << setw(20) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(20) << " " << "|\t\t1. Thống kê theo năm            |" << endl;
				    cout << setw(20) << " " << "|\t\t2. Thống kê theo tháng          |" << endl;
				    cout << setw(20) << " " << "|\t\t3. Thống kê theo ngày           |" << endl;
				    cout << setw(20) << " " << "|\t\t4. Quay lại                     |" << endl;
				    cout << setw(20) << " " << "+-------------------------------------------+\n" << endl;
				    cout << setw(20) << " " << "+------------------------+----+\n";
			    	cout << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(20) << " " << "+------------------------+----+\n";
			    	gotoxy(48,9);
			    	cin >> option;
                    if(option < 1 || option > 4){
			    		cout << endl;
			    		cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(20) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
				    	cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	cout << setw(20) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	gotoxy(57,15);
				    	getch();
					}
                }while(option < 1 || option > 4);
                switch (option){
                    case 1:
                        cout << "Nhap nam: "; cin >> y;
                        invoiceManage.statistic(invoiceManage.find(y));
                        system("pause");
                        break;
                    case 2:
                        cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        invoiceManage.statistic(invoiceManage.find(m, y));
                        system("pause");
                        break;
                    case 3:
                        cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        invoiceManage.statistic(invoiceManage.find(d, m, y));
                        system("pause");
                        break;
                    case 4:
                        break;
                }
				break;
			}	
			case 3:{
				int option;
                do{
                    system("cls");
                    cout << setw(20) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(20) << " " << "|\t\t1. Danh sách sản phẩm           |" << endl;
				    cout << setw(20) << " " << "|\t\t2. Tìm sản phẩm                 |" << endl;
				    cout << setw(20) << " " << "|\t\t3. Thêm mẫu sản phẩm mới        |" << endl;
				    cout << setw(20) << " " << "|\t\t4. Cập nhật sản phẩm            |" << endl;
				    cout << setw(20) << " " << "|\t\t5. Xóa sản phẩm	                |" << endl;
				    cout << setw(20) << " " << "|\t\t6. Thêm sản phẩm mới            |" << endl;
				    cout << setw(20) << " " << "|\t\t7. Quay lại  	                |" << endl;
                    cout << setw(20) << " " << "+-------------------------------------------+\n" << endl;
                    cout << setw(20) << " " << "+------------------------+----+\n";
			    	cout << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(20) << " " << "+------------------------+----+\n";
			    	gotoxy(48,12);
			    	cin >> option;
                    if(option < 1 || option > 7){
			    		cout << endl;
			    		cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(20) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
				    	cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	cout << setw(20) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	gotoxy(57,18);
				    	getch();
					}
                }while(option < 1 || option > 7);
                switch(option){
                    case 1:
                        productManage.displayOption();
                        system("pause");
                        break;
                    case 2:{
                    	system("cls");
                    	string id;
                        cout << "Nhap ID san pham: "; cin >> id;
                        if(productManage.find(id) == nullptr) cout << endl << "Khong tim thay san pham nay" << endl;
                        else productManage.find(id)->data.show();
                        system("pause");
						break;
					}
                    case 3:
                        system("cls");
                        productManage.add();
                        break;
                    case 4:{
                    	system("cls");
                    	string id;
                        cout << "Nhap ID san pham can cap nhat: "; cin >> id;
                        productManage.update(productManage.find(id)->data);
                        system("pause");
						break;
					}
                    case 5:{
                    	system("cls");
                    	string id;
                        cout << "Nhap ID mau san pham can xoa: "; cin >> id;
                        productManage.remove(productManage.find(id)->data);
                        system("pause");
						break;
					}
                    case 6:{
                    	system("cls");
                    	string id;
                        string seri;
                        int count;
                        cout << "Nhap ma san pham can them: "; 
                        cin >> id;
                        Node<Product>* prod = productManage.find(id);
                        if (prod == nullptr)
                        {
                            cout << "Ma san pham nhap vao khong ton tai!" << endl;
                        }
                        else
                        {
                            cout << "Nhap so luong can them: "; cin >> count;
                            for (int i = 0; i < count; i++)
                            {
                                cout << "Nhap so serial thu " << i+1 << ": "; cin >> seri;
                                prod->data.addSerial(seri);
                                cout << endl << "Them thanh cong san pham co so serial: " << seri << endl;
                            }
                        }
                        cout << endl << endl << endl;
                        system("pause");
						break;
					}
                }
                break;
			}
			case 4:{
				int option;
                do{
                    system("cls");
                    cout << setw(20) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(20) << " " << "|\t\t1. Danh sách khách hàng         |" << endl;
				    cout << setw(20) << " " << "|\t\t2. Tìm khách hàng               |" << endl;
				    cout << setw(20) << " " << "|\t\t3. Quay lại                     |" << endl;
				    cout << setw(20) << " " << "+-------------------------------------------+\n" << endl;
				    cout << setw(20) << " " << "+------------------------+----+\n";
			    	cout << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(20) << " " << "+------------------------+----+\n";
			    	gotoxy(48,8);
			    	cin >> option;
                    if(option < 1 || option > 3){
			    		cout << endl;
			    		cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(20) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 3. |\n"; 
				    	cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	cout << setw(20) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	gotoxy(57,14);
				    	getch();
					}
                }while(option < 1 || option > 3);
                switch (option){
                    case 1:
                        customerManage.display();
                        system("pause");
                        break;
                    case 2:
                        int find_option = 1;
                        do {
                            system("cls");
                            cout << ((find_option == 1) ? "->" : "  ") << "Tim theo ma khach hang" << endl;
                            cout << ((find_option == 2) ? "->" : "  ") << "Tim theo ten va so dien thoai" << endl;
                        } while (find_option != 13);
                        if (find_option == 1) {
                            system("cls");
                            int id;
                            cout << "Nhap ma khach hang: "; cin >> id;
                            Node<Customer>* fcus = customerManage.find(id);
                            if(fcus!= nullptr)
                            {
                                cout << "__________________________________________________________________________" << endl;
                                fcus->data.Show();
                                cout << endl << "Lich su mua hang: " << endl << endl;
                                invoiceManage.find(fcus->data).display();
                            }
                            else
                            {
                                cout << "Khong tim thay khach hang nay!" << endl;
                            }
                            system("pause");
                        }
                        else {
                            system("cls");
                            string name, phone;
                            cin.ignore();
                            cout << "Ten khach hang: "; getline(cin, name);
                            cout << "So dien thoai: "; cin >> phone;
                            Node<Customer>* fcus = customerManage.find(name, phone);
                            if(fcus!= nullptr)
                            {
                                cout << "__________________________________________________________________________" << endl;
                                fcus->data.Show();
                                cout << endl << "Lich su mua hang: " << endl << endl;
                                invoiceManage.find(fcus->data).display();
                            }
                            else
                            {
                                cout << "Khong tim thay khach hang nay!" << endl;
                            }
                            system("pause");
                        }
                        break;
                }
                break;
			}
			case 5:{
				invoiceManage.sell(user->getID(), customerManage, productManage, employeeManage);
				break;
			}
			case 6:{
				int option;
                do{
                    system("cls");
                    cout << setw(20) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(20) << " " << "|\t\t1. Tìm theo mã sản phẩm         |" << endl;
				    cout << setw(20) << " " << "|\t\t2. Tìm theo năm                 |" << endl;
				    cout << setw(20) << " " << "|\t\t3. Tìm theo tháng               |" << endl;
				    cout << setw(20) << " " << "|\t\t4. Tìm theo ngày                |" << endl;
				    cout << setw(20) << " " << "|\t\t5. Quay lại	                |" << endl;
                    cout << setw(20) << " " << "+-------------------------------------------+\n" << endl;
                    cout << setw(20) << " " << "+------------------------+----+\n";
			    	cout << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(20) << " " << "+------------------------+----+\n";
			    	gotoxy(48,10);
			    	cin >> option;
                    if(option < 1 || option > 5){
			    		cout << endl;
			    		cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(20) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 5. |\n"; 
				    	cout << setw(20) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	cout << setw(20) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(20) << " " << "+---------------------------------+\n";
				    	gotoxy(57,16);
				    	getch();
					}
                }while(option < 1 || option > 5);
                switch (option){
                    case 1:{
                    	int id;
                    	cout << "Nhap ma hoa don: "; cin >> id;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.findtoShow(id);
                        system("pause");
						break;
					}
                    case 2:{
                    	int y;
                    	cout << "Nhap nam: "; cin >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(y).display();
                        system("pause");
						break;
					}
                    case 3:{
                    	int m,y;
                    	cout << "Nhap lan luot thang, nam: "; cin >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(m, y).display();
                        system("pause");
						break;
					}
                    case 4:{
                    	int d,m,y;
                    	cout << "Nhap lan luot ngay, thang, nam: "; cin >> d >> m >> y;
                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
						break;
					}
                    case 5:
                        break;
                }
                break;
			}
			case 7:{
				int Close = 2;
				cout << endl;
				cout << setw(20) << " " << "+--------------------------------------------+\n";
		    	cout << setw(20) << " " << "| Bạn có chắc chắn muốn thoát chương trình ? |\n"; 
		    	cout << setw(20) << " " << "+--------------------------------------------+\n";
		    	cout << setw(20) << " " << "+-----------------------+\n";
		    	cout << setw(20) << " " << "|  1. Có  |  2. Không   |\n"; 
		    	cout << setw(20) << " " << "+-----------------------+\n";
		    	gotoxy(48,27);
		    	cin >> Close;
		    	if(Close == 1) over = true;
				break;
			}
		}
	}while(over != true);
}
 
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
	setConsoleFullScreen(); // full màn
    Database::readData();
    Database::saveData();
	MenuManage();	    
}
void title() {
	system("cls");
//	textcolor(11);
    cout << setw(40) << " " << "+--------------------------------------------------------------------------------------+" << endl;
	cout << setw(40) << " " << "|          ___                                                                         |" << endl;
    cout << setw(40) << " " << "|  ______ (__ )         _      __                  _                 _                 |" << endl;
    cout << setw(40) << " " << "| / ____/  (_/_        | |     \\_\\                | |               | |                |" << endl;
    cout << setw(40) << " " << "|| |     _   ) )__,_   | |__   __,_ _,__   __,_   | |     __,_ _,__ | |_,___  _,__     |" << endl;
    cout << setw(40) << " " << "|| |    | | | |/ _  |  |  _ \\ / _  |  _ \\ / _  |  | |    / _  |  _ \\| __/ _ \\|  _ \\    |" << endl;
    cout << setw(40) << " " << "|| |____| |_| | (_| |  | | | | (_| | | | | (_| |  | |___| (_| | |_) | || (_) | |_) |   |" << endl;
    cout << setw(40) << " " << "| \\_____ \\____|\\___,|  |_| |_|\___,_|_| |_|\___, |  |_____ \\__,_|  __/ \\__\\___/|  __/    |" << endl;
    cout << setw(40) << " " << "|                                           _/ |              | |            | |       |" << endl;
    cout << setw(40) << " " << "|                                          |__/               |_|            |_|       |" << endl;
    cout << setw(40) << " " << "+--------------------------------------------------------------------------------------+" << endl;
    cout << setw(60) << " " << "|\t\t                     \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t1. Thống kê bán hàng \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t2. Quản lí sản phẩm  \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t3. Quản lí khách hàng \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t4. Bán hàng          \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t5. Lịch sử bán hàng  \t\t|" << endl;
    cout << setw(60) << " " << "|\t\t6. Thoát             \t\t|" << endl;
    cout << setw(40) << " " << "+--------------------------------------------------------------------------------------+" << endl;
}
void MenuManage(){
    int option;
    bool over = false;
    do{
    	title();
    	cout << setw(40) << " " << setw(20) << " " << "+------------------------+----+\n";
    	cout << setw(40) << " " << setw(20) << " " << "| Mời bạn nhập chức năng |    |\n"; 
    	cout << setw(40) << " " << setw(20) << " " << "+------------------------+----+\n";
    	gotoxy(88,21);
    	cin >> option;
    	if(option < 1 || option > 6){
    		cout << endl;
    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
	    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 6. |\n"; 
	    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
	    	
	    	cout << setw(60) << " " << "+---------------------------------+\n";
	    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
	    	cout << setw(60) << " " << "+---------------------------------+\n";
	    	gotoxy(97,27);
	    	getch();
		}
		switch(option){
			case 1:{
				int option;
                do{
                    system("cls");
                    cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(60) << " " << "|\t\t1. Thống kê theo năm            |" << endl;
				    cout << setw(60) << " " << "|\t\t2. Thống kê theo tháng          |" << endl;
				    cout << setw(60) << " " << "|\t\t3. Thống kê theo ngày           |" << endl;
				    cout << setw(60) << " " << "|\t\t4. Quay lại                     |" << endl;
				    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
				    cout << setw(60) << " " << "+------------------------+----+\n";
			    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(60) << " " << "+------------------------+----+\n";
			    	gotoxy(88,9);
			    	cin >> option;
                    if(option < 1 || option > 4){
			    		cout << endl;
			    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
				    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	gotoxy(97,15);
				    	getch();
					}
                }while(option < 1 || option > 4);
                switch (option){
                    case 1:{
                    	int y;
                    	cout << endl;
                    	do{
                    		system("cls");
                    		cout << setw(60) << " " << "+------------------------+------+\n";
					    	cout << setw(60) << " " << "| Nhập năm cần thống kê  |      |\n"; 
					    	cout << setw(60) << " " << "+------------------------+------+\n" << endl;
					    	gotoxy(88,2);
	                        cin >> y;
	                        if(y < 2020 || y > 2024){
	                        	cout << endl;
					    		cout << setw(60) << " " << "+---------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không có thống kê của năm vừa nhập !! |\n"; 
						    	cout << setw(60) << " " << "+---------------------------------------+\n";
	                        	system("pause");
							}
						}while(y < 2020 || y > 2024);
                        system("cls");
                        invoiceManage.statistic(invoiceManage.find(y));
                        system("pause");
						break;
					}
                    case 2:{
                    	int m,y;
                    	cout << endl;
                    	do{
                    		system("cls");
                    		cout << setw(60) << " " << "+---------------------------+----+------+\n";
					    	cout << setw(60) << " " << "| Nhập lần lượt tháng, năm  |    |      |\n"; 
					    	cout << setw(60) << " " << "+---------------------------+----+------+\n" << endl;
					    	gotoxy(91,2); cin >> m;
							gotoxy(96,2); cin >> y;
							if(m < 1 || m > 12 || y < 2020 || y > 2024){
								cout << endl;
					    		cout << setw(60) << " " << "+----------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không có thống kê của tháng, năm vừa nhập !! |\n"; 
						    	cout << setw(60) << " " << "+----------------------------------------------+\n";
	                        	system("pause");
							}
						}while(m < 1 || m > 12 || y < 2020 || y > 2024);
                        system("cls");
                    	invoiceManage.statistic(invoiceManage.find(m, y));
                        system("pause");
						break;
					}
                    case 3:{
                    	int d,m,y;
                    	cout << endl;
						do{
							system("cls");
							cout << setw(60) << " " << "+---------------------------------+----+----+------+\n";
					    	cout << setw(60) << " " << "| Nhập lần lượt ngày, tháng, năm  |    |    |      |\n"; 
					    	cout << setw(60) << " " << "+---------------------------------+----+----+------+\n" << endl;
					    	gotoxy(97,2); cin >> d;
							gotoxy(102,2); cin >> m; 
							gotoxy(107,2); cin >> y;
							if((d < 1 || d > 31 || m < 1 || m > 12 || y < 2020 || y > 2024) || (m==2 && (d==30 || d==31))){
								cout << endl;
					    		cout << setw(60) << " " << "+----------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không có thống kê của tháng, năm vừa nhập !! |\n"; 
						    	cout << setw(60) << " " << "+----------------------------------------------+\n";
	                        	system("pause");
							}
						}while((d < 1 || d > 31 || m < 1 || m > 12 || y < 2020 || y > 2024) || (m==2 && (d==30 || d==31)));
                        system("cls");
                        invoiceManage.statistic(invoiceManage.find(d, m, y));
                        system("pause");
						break;
					}
                    case 4:
                        break;
                }
				break;
			}	
			case 2:{
				int option;
                do{
                    system("cls");
                    cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(60) << " " << "|\t\t1. Danh sách sản phẩm           |" << endl;
				    cout << setw(60) << " " << "|\t\t2. Tìm sản phẩm                 |" << endl;
				    cout << setw(60) << " " << "|\t\t3. Thêm mẫu sản phẩm mới        |" << endl;
				    cout << setw(60) << " " << "|\t\t4. Cập nhật sản phẩm            |" << endl;
				    cout << setw(60) << " " << "|\t\t5. Xóa sản phẩm	                |" << endl;
				    cout << setw(60) << " " << "|\t\t6. Thêm số lượng laptop         |" << endl;
				    cout << setw(60) << " " << "|\t\t7. Quay lại  	                |" << endl;
                    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
                    cout << setw(60) << " " << "+------------------------+----+\n";
			    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(60) << " " << "+------------------------+----+\n";
			    	gotoxy(88,12);
			    	cin >> option;
                    if(option < 1 || option > 7){
			    		cout << endl;
			    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 7. |\n"; 
				    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	gotoxy(97,18);
				    	getch();
					}
                }while(option < 1 || option > 7);
                switch(option){
                    case 1:{
	                    int option;
					    do{
					    	system("cls");
					        cout << setw(60) << " " << "+-------------------------------------------+" << endl;
					        cout << setw(60) << " " << "|\t\t1. Xem tất cả sản phẩm          |" << endl;
							cout << setw(60) << " " << "|\t\t2. Xem theo giá tăng dần        |" << endl;
							cout << setw(60) << " " << "|\t\t3. Xem theo giá giảm dần        |" << endl;
							cout << setw(60) << " " << "|\t\t4. Quay lại                     |" << endl;
					        cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
					        cout << setw(60) << " " << "+------------------------+----+\n";
							cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
							cout << setw(60) << " " << "+------------------------+----+\n";
							gotoxy(88,9);
							cin >> option;
					        if(option < 1 || option > 4){
								cout << endl;
								cout << setw(60) << " " << "+----------------------------------------------------------+\n";
								cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
								cout << setw(60) << " " << "+----------------------------------------------------------+\n";
									    	
								cout << setw(60) << " " << "+---------------------------------+\n";
								cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
								cout << setw(60) << " " << "+---------------------------------+\n";
								gotoxy(97,15);
								getch();
							}
					        system("cls");
					    }while(option < 1 || option > 4);
					    productManage.displayOption(option);
                        system("pause");
						break;
					}
                    case 2:{
                    	string id;
                    	cout << endl;
                    	cout << setw(60) << " " << "+------------------------+-----------+\n";
				    	cout << setw(60) << " " << "|    Nhập ID sản phẩm    |           |\n"; 
				    	cout << setw(60) << " " << "+------------------------+-----------+\n" << endl;
				    	gotoxy(88,15);
                        cin >> id;
                        system("cls");
                        if(productManage.find(id) == nullptr) {
                        	cout << setw(60) << " " << "+------------------------------+\n";
					    	cout << setw(60) << " " << "| Không tìm thấy sản phẩm !!   |\n"; 
					    	cout << setw(60) << " " << "+------------------------------+\n" << endl;
						}
                        else productManage.find(id)->data.show();
                        system("pause");
						break;
					}
                    case 3:
                        system("cls");
                        productManage.add();
                        system("pause");
                        break;
                    case 4:{
                    	string id;
                    	cout << endl;
                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
				    	cout << setw(60) << " " << "| Nhập ID sản phẩm cần cập nhật |           |\n"; 
				    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
				    	gotoxy(95,15);
                        cin >> id;
                        system("cls");
                        productManage.update(productManage.find(id)->data);
                        system("pause");
						break;
					}
                    case 5:{
                    	string id;
                    	cout << endl;
                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
				    	cout << setw(60) << " " << "|    Nhập ID sản phẩm cần xóa   |           |\n"; 
				    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
				    	gotoxy(95,15);
                        cin >> id;
                        system("cls");
                        if(productManage.find(id) == nullptr) {
                        	cout << "Không tìm thấy sản phẩm\n";
                        	system("pause");
                        	break;
						}
                        productManage.remove(productManage.find(id)->data);
                        system("pause");
						break;
					}
                    case 6:{
                    	string id, seri;
                        int count;
                        cout << endl;
                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
				    	cout << setw(60) << " " << "|    Nhập mã sản phẩm cần thêm  |           |\n"; 
				    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
                        gotoxy(95,15);
                        cin >> id;
                        Node<Product>* prod = productManage.find(id);
                        if (prod == nullptr)
                        {
                        	system("cls");
                        	cout << setw(60) << " " << "+------------------------------------+\n";
					    	cout << setw(60) << " " << "|      Mã sản phẩm không tồn tại     |\n"; 
					    	cout << setw(60) << " " << "+------------------------------------+\n" << endl;
                        }
                        else
                        {
                        	system("cls");
                        	cout << setw(60) << " " << "+-------------------------------+----+\n";
				    		cout << setw(60) << " " << "|    Nhập số lượng cần thêm     |    |\n"; 
				    		cout << setw(60) << " " << "+-------------------------------+----+\n" << endl;
                            gotoxy(95,2); cin >> count;
                            for (int i = 0; i < count; i++){
                            	cout << endl << setw(60) << " " << string(38, '-') << endl;
                                cout << setw(60) << " " << "  Nhập seri thứ " << i+1 << ": "; cin >> seri;
                                prod->data.addSerial(seri);
                            }
                            cout << endl << setw(60) << " " << string(38, '-') << endl;
                            cout << setw(60) << " " << "+------------------------------------+\n";
						    cout << setw(60) << " " << "|     Thêm số lượng thành công       |\n"; 
						    cout << setw(60) << " " << "+------------------------------------+\n" << endl;
                        }
                        cout << endl << endl << endl;
                        system("pause");
						break;
					}
                }
                break;
			}
			case 3:{
				int option;
                do{
                    system("cls");
                    cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(60) << " " << "|\t\t1. Danh sách khách hàng         |" << endl;
				    cout << setw(60) << " " << "|\t\t2. Tìm khách hàng               |" << endl;
				    cout << setw(60) << " " << "|\t\t3. Quay lại                     |" << endl;
				    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
				    cout << setw(60) << " " << "+------------------------+----+\n";
			    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(60) << " " << "+------------------------+----+\n";
			    	gotoxy(88,8);
			    	cin >> option;
                    if(option < 1 || option > 3){
			    		cout << endl;
			    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 3. |\n"; 
				    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	gotoxy(97,14);
				    	getch();
					}
                }while(option < 1 || option > 3);
                switch (option){
                    case 1:
                    	system("cls");
                    	cout << endl;
                    	cout << "                                                                       THÔNG TIN KHÁCH HÀNG\n";
		    			cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+\n";
		    			cout << "  |  Mã khách hàng  |  Họ và tên                   |  Số điện thoại       |   Giới tính    |  Email                       |  Địa chỉ                        |\n"; 
						cout << "  +-----------------+------------------------------+----------------------+----------------+------------------------------+---------------------------------+\n";
                        cout << endl;
						customerManage.display(); 
                        system("pause");
                        break;
                    case 2:
                        int option;
                        do {
                        	system("cls");
                        	cout << setw(60) << " " << "+-------------------------------------------+" << endl;
		                    cout << setw(60) << " " << "|\t  1. Tìm theo mã khách hàng             |" << endl;
						    cout << setw(60) << " " << "|\t  2. Tìm theo tên và số điện thoại      |" << endl;
						    cout << setw(60) << " " << "|\t  3. Quay lại                           |" << endl;
						    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
						    cout << setw(60) << " " << "+------------------------+----+\n";
					    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
					    	cout << setw(60) << " " << "+------------------------+----+\n";
					    	gotoxy(88,8);
					    	cin >> option;
					    	if (option == 1) {
	                            system("cls");
	                            int id;
	                            cout << setw(60) << " " << "+------------------------+--------+\n";
						    	cout << setw(60) << " " << "|   Nhập mã khách hàng   |        |\n"; 
						    	cout << setw(60) << " " << "+------------------------+--------+\n";
						    	gotoxy(88,2);
						    	cin >> id;
	                            Node<Customer>* fcus = customerManage.find(id);
	                            if(fcus!= nullptr){
	                                fcus->data.Show();
	                                cout << endl << "Lịch sử mua hàng: " << endl << endl;
	                                invoiceManage.find(fcus->data).display();
	                            }
	                            else{
	                            	cout << endl;
	                            	cout << setw(60) << " " << "+--------------------------------------+\n";
							    	cout << setw(60) << " " << "|   Không tìm thấy mã khách hàng này!  |\n"; 
							    	cout << setw(60) << " " << "+--------------------------------------+\n";
	                            }
	                            system("pause");
	                        }
	                        else if (option == 2){
	                            system("cls");
	                            string name, phone;
	                            cin.ignore();
	                            cout << setw(60) << " " << "+--------------------------+--------------------------------+\n";
						    	cout << setw(60) << " " << "|    Nhập tên khách hàng   |                                |\n"; 
						    	cout << setw(60) << " " << "+--------------------------+--------------------------------+\n";
						    	gotoxy(90,2);
								getline(cin, name);
								cout << endl;
								cout << setw(60) << " " << "+--------------------------+-------------+\n";
						    	cout << setw(60) << " " << "|    Nhập số điện thoại    |             |\n"; 
						    	cout << setw(60) << " " << "+--------------------------+-------------+\n";
						    	gotoxy(90,5);
								cin >> phone;
	                            Node<Customer>* fcus = customerManage.find(name, phone);
	                            if(fcus!= nullptr){
	                            	system("cls");
	                                fcus->data.Show();
	                                cout << endl << "  Lịch sử mua hàng: " << endl << endl;
	                                invoiceManage.find(fcus->data).display();
	                            }
	                            else{
	                                cout << endl << endl;
	                            	cout << setw(60) << " " << "+---------------------------------+\n";
							    	cout << setw(60) << " " << "|  Không tìm thấy khách hàng này!   |\n"; 
							    	cout << setw(60) << " " << "+---------------------------------+\n";
	                            }
	                            system("pause");
	                        }else if(option == 3) break;
                            if(option < 1 || option > 3){
					    		cout << endl;
					    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 3. |\n"; 
						    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
						    	
						    	system("pause");
							}
                        } while (option < 1 || option > 3);
                }
                break;
			}
			case 4:{
				invoiceManage.sell(customerManage, productManage, employeeManage);
				break;
			}
			case 5:{
				int option;
                do{
                    system("cls");
                    cout << setw(60) << " " << "+-------------------------------------------+" << endl;
                    cout << setw(60) << " " << "|\t\t1. Tìm theo mã sản phẩm         |" << endl;
				    cout << setw(60) << " " << "|\t\t2. Tìm theo năm                 |" << endl;
				    cout << setw(60) << " " << "|\t\t3. Tìm theo tháng               |" << endl;
				    cout << setw(60) << " " << "|\t\t4. Tìm theo ngày                |" << endl;
				    cout << setw(60) << " " << "|\t\t5. Quay lại	                |" << endl;
                    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
                    cout << setw(60) << " " << "+------------------------+----+\n";
			    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(60) << " " << "+------------------------+----+\n";
			    	gotoxy(88,10);
			    	cin >> option;
                    if(option < 1 || option > 5){
			    		cout << endl;
			    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 5. |\n"; 
				    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	gotoxy(97,16);
				    	getch();
					}
                }while(option < 1 || option > 5);
                switch (option){
                    case 1:{
                    	int id;
                    	cout << endl;
                    	cout << setw(60) << " " << "+------------------------+---------+\n";
				    	cout << setw(60) << " " << "|    Nhập mã hóa đơn     |         |\n"; 
				    	cout << setw(60) << " " << "+------------------------+---------+\n";
				    	gotoxy(88,13);
				    	cin >> id;
//                        cout << "_________________________________________________________________________________" << endl;
                        invoiceManage.findtoShow(id);
                        system("pause");
						break;
					}
                    case 2:{
                    	int y;
                    	cout << setw(60) << " " << "+-----------------------------+-------+\n";
				    	cout << setw(60) << " " << "|    Nhập năm cần tìm kiếm    |       |\n"; 
				    	cout << setw(60) << " " << "+-----------------------------+-------+\n";
				    	gotoxy(92,13);
				    	cin >> y;
				    	cout << endl;
                        invoiceManage.find(y).display();
                        system("pause");
						break;
					}
                    case 3:{
                    	int m,y;
                    	system("cls");
                    	cout << endl;
                    	cout << setw(60) << " " << "+---------------------------+----+------+\n";
				    	cout << setw(60) << " " << "| Nhập lần lượt tháng, năm  |    |      |\n"; 
				    	cout << setw(60) << " " << "+---------------------------+----+------+\n" << endl;
				    	gotoxy(91,3); cin >> m;
						gotoxy(96,3); cin >> y;
                        invoiceManage.find(m, y).display();
                        system("pause");
						break;
					}
                    case 4:{
                    	int d,m,y;
                    	system("cls");
                    	cout << endl;
                    	cout << setw(60) << " " << "+---------------------------------+----+----+------+\n";
				    	cout << setw(60) << " " << "| Nhập lần lượt ngày, tháng, năm  |    |    |      |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+----+----+------+\n" << endl;
				    	gotoxy(57,3); cin >> d;
						gotoxy(102,3); cin >> m; 
						gotoxy(107,3); cin >> y;
                        invoiceManage.find(d, m, y).display();
                        system("pause");
						break;
					}
                    case 5:
                        break;
                }
                break;
			}
			case 6:{
				int Close = 2;
				cout << endl;
				cout << setw(60) << " " << "+--------------------------------------------+\n";
		    	cout << setw(60) << " " << "| Bạn có chắc chắn muốn thoát chương trình ? |\n"; 
		    	cout << setw(60) << " " << "+--------------------------------------------+\n";
		    	cout << setw(60) << " " << "+-----------------------+----+\n";
		    	cout << setw(60) << " " << "|  1. Có  |  2. Không   |    |\n"; 
		    	cout << setw(60) << " " << "+-----------------------+----+\n";
		    	gotoxy(87,27);
		    	cin >> Close;
		    	if(Close == 1) {
		    		cout << endl;
		    		cout << setw(60) << " " << "+--------------------------------------------+\n";
			    	cout << setw(60) << " " << "|   Bạn đã thoát chương trình thành công !!  |\n"; 
			    	cout << setw(60) << " " << "+--------------------------------------------+\n";
		    		over = true;
				}
				break;
			}
		}
	}while(over != true);
}
 
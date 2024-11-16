#include<string>
#include"windows.h"
#include <cstdlib> 
#include "CusManage.h"
#include "InvManage.h"
#include "ProdManage.h"
#include "Database.h"
using namespace std;
Database& myDatabase = Database::DB_Instance();
CusManage& customerManage = myDatabase.getCusManage();
ProdManage& productManage = myDatabase.getProdManage();
InvManage& invoiceManage = myDatabase.getInvManage();
void MenuManage();

int main(){
	SetConsoleOutputCP(CP_UTF8);
	setConsoleFullScreen(); // full màn
	textcolor(224);
    Database::readData();
	MenuManage();	    
    Database::saveData();
}
void title() {
	system("cls");
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
    		textcolor(228);
    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
	    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 6. |\n"; 
	    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
	    	textcolor(224);
	    	cout << setw(60) << " " << "+---------------------------------+\n";
	    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
	    	cout << setw(60) << " " << "+---------------------------------+\n";
	    	gotoxy(97,27);
	    	getch();
		}
		switch(option){
			case 1:{
				bool over = true;
				int option;
				do{
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
				    		textcolor(228);
				    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
					    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	textcolor(224);
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
		                        	textcolor(228);
						    		cout << setw(60) << " " << "+----------------------------------------+\n";
							    	cout << setw(60) << " " << "| Chỉ có thống kê từ năm 2020 đến nay !! |\n"; 
							    	cout << setw(60) << " " << "+----------------------------------------+\n";
							    	textcolor(224);
		                        	system("pause");
								}
							}while(y < 2020 || y > 2024);
							if(invoiceManage.find(y) == nullptr) {
								cout << endl;
								textcolor(228);
								cout << setw(60) << " " << "+----------------------+\n";
							    cout << setw(60) << " " << "| Không có thống kê !! |\n"; 
							    cout << setw(60) << " " << "+----------------------+\n";
							    textcolor(224);
	                        	system("pause");
	                        	break;
							}
	                        system("cls");
	                        cout << setw(50) << " " << string(60, '=') << endl;
	                        cout << setw(60) << " " << "THỐNG KÊ CỦA NĂM " << y << "" << endl;
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
									textcolor(228);
						    		cout << setw(60) << " " << "+----------------------------------------+\n";
							    	cout << setw(60) << " " << "| Chỉ có thống kê từ năm 2020 đến nay !! |\n"; 
							    	cout << setw(60) << " " << "+----------------------------------------+\n";
							    	textcolor(224);
		                        	system("pause");
								}
							}while(m < 1 || m > 12 || y < 2020 || y > 2024);
							if(invoiceManage.find(m, y) == nullptr) {
								cout << endl;
								textcolor(228);
								cout << setw(60) << " " << "+----------------------+\n";
							    cout << setw(60) << " " << "| Không có thống kê !! |\n"; 
							    cout << setw(60) << " " << "+----------------------+\n";
							    textcolor(224);
	                        	system("pause");
	                        	break;
							}
	                        system("cls");
	                        cout << setw(50) << " " << string(60, '=') << endl;
	                        cout << setw(60) << " " << "THỐNG KÊ CỦA THÁNG " << m << " NĂM " << y << endl;
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
									textcolor(228);
						    		cout << setw(60) << " " << "+----------------------------------------+\n";
							    	cout << setw(60) << " " << "| Chỉ có thống kê từ năm 2020 đến nay !! |\n"; 
							    	cout << setw(60) << " " << "+----------------------------------------+\n";
							    	textcolor(224);
		                        	system("pause");
								}
							}while((d < 1 || d > 31 || m < 1 || m > 12 || y < 2020 || y > 2024) || (m==2 && (d==30 || d==31)));
							if(invoiceManage.find(d, m, y) == nullptr) {
								cout << endl;
								textcolor(228);
								cout << setw(60) << " " << "+----------------------+\n";
							    cout << setw(60) << " " << "| Không có thống kê !! |\n"; 
							    cout << setw(60) << " " << "+----------------------+\n";
							    textcolor(224);
	                        	system("pause");
	                        	break;
							}
	                        system("cls");
	                        cout << setw(50) << " " << string(60, '=') << endl;
	                        cout << setw(60) << " " << "THỐNG KÊ CỦA NGÀY " << d << " THÁNG " << m << " NĂM " << y << endl;
	                        invoiceManage.statistic(invoiceManage.find(d, m, y));
	                        system("pause");
							break;
						}
	                    case 4:
	                        over = false;
	                        break;
	                }
				}while(over);
				break;
			}	
			case 2:{
				int option;
				bool over = true;
				do{
					do{
	                    system("cls");
	                    cout << setw(60) << " " << "+-------------------------------------------------+" << endl;
	                    cout << setw(60) << " " << "|\t\t1. Danh sách sản phẩm                 |" << endl;
					    cout << setw(60) << " " << "|\t\t2. Xem thông tin chi tiết sản phẩm    |" << endl;
					    cout << setw(60) << " " << "|\t\t3. Thêm mẫu sản phẩm mới              |" << endl;
					    cout << setw(60) << " " << "|\t\t4. Cập nhật sản phẩm                  |" << endl;
					    cout << setw(60) << " " << "|\t\t5. Xóa sản phẩm	                      |" << endl;
					    cout << setw(60) << " " << "|\t\t6. Thêm số lượng laptop               |" << endl;
					    cout << setw(60) << " " << "|\t\t7. Quay lại  	                      |" << endl;
	                    cout << setw(60) << " " << "+-------------------------------------------------+\n" << endl;
	                    cout << setw(60) << " " << "+------------------------+----+\n";
				    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
				    	cout << setw(60) << " " << "+------------------------+----+\n";
				    	gotoxy(88,12);
				    	cin >> option;  
	                    if(option < 1 || option > 7){
				    		cout << endl;
				    		textcolor(228);
				    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 7. |\n"; 
					    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	textcolor(224);
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
						    bool over = true;
						    do{
						    	do{
							    	system("cls");
							        cout << setw(60) << " " << "+-------------------------------------------+" << endl;
							        cout << setw(60) << " " << "|\t\t1. Xem tất cả sản phẩm          |" << endl;
									cout << setw(60) << " " << "|\t\t2. Xem theo giá giảm dần        |" << endl;
									cout << setw(60) << " " << "|\t\t3. Xem theo số lượng tăng dần   |" << endl;
									cout << setw(60) << " " << "|\t\t4. Quay lại                     |" << endl;
							        cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
							        cout << setw(60) << " " << "+------------------------+----+\n";
									cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
									cout << setw(60) << " " << "+------------------------+----+\n";
									gotoxy(88,9);
									cin >> option;  
							        if(option < 1 || option > 4){
										cout << endl;
										textcolor(228);
										cout << setw(60) << " " << "+----------------------------------------------------------+\n";
										cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 4. |\n"; 
										cout << setw(60) << " " << "+----------------------------------------------------------+\n";
										textcolor(224);	    	
										cout << setw(60) << " " << "+---------------------------------+\n";
										cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
										cout << setw(60) << " " << "+---------------------------------+\n";
										gotoxy(97,15);
										getch();
									}
							        system("cls");
							    }while(option < 1 || option > 4);
								if(option != 4){
								    productManage.displayOption(option);
								    system("pause");
								}else over = false;
							}while(over);
							break;
						}
	                    case 2:{
	                    	string id;
	                    	do{
	                    		system("cls");
								productManage.displayOption(1);
								cout << endl;
								cout << setw(30) << " " << "- Nhấn ESC để quay lại\n" << endl;
								cout << setw(30) << " " << "- Nhấn Enter để nhập\n" << endl;
								char t = getch();
								if(t == 27){
									break;
								}else if (t == 13){
									cout << setw(60) << " " << ">> Nhập ID sản phẩm cần xem: ";
									cin >> id;
								}
								if(productManage.find(id) == nullptr) {
		                        	cout << endl;
		                        	textcolor(228);
		                        	cout << setw(60) << " " << "+------------------------------+\n";
							    	cout << setw(60) << " " << "|  Không tìm thấy sản phẩm !!  |\n"; 
							    	cout << setw(60) << " " << "+------------------------------+\n" << endl;
							    	textcolor(224);
								}
		                        else {
		                        	system("cls");
		                        	productManage.find(id)->data.show();
								}
		                        system("pause");
							}while(1);
							break;
						}
	                    case 3:
	                        system("cls");
	                        productManage.add();
	                        system("pause");
	                        break;
	                    case 4:{
	                    	string id;
	                    	system("cls");
	                    	cout << endl;
	                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
					    	cout << setw(60) << " " << "| Nhập ID sản phẩm cần cập nhật |           |\n"; 
					    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
	                        productManage.displayOption(1); cout << endl;
					    	gotoxy(95,3);
	                        cin >> id;  
	                        if(productManage.find(id) == nullptr) {
	                        	system("cls"); cout << endl;
	                        	textcolor(228);
	                        	cout << setw(60) << " " << "+------------------------------+\n";
						    	cout << setw(60) << " " << "|  Không tìm thấy sản phẩm !!  |\n"; 
						    	cout << setw(60) << " " << "+------------------------------+\n" << endl;
						    	textcolor(224);
							}
	                        else {
	                        	system("cls");
	                        	productManage.update(productManage.find(id)->data);
	                        	if(productManage.find(id)){
		                        	cout << setw(50) << " " << string(60, '=') << endl;
		                        	textcolor(226);
							        cout << setw(70) << " " << "CẬP NHẬT THÀNH CÔNG" << endl;
							        textcolor(224);
								}
							}
	                        system("pause");
							break;
						}
	                    case 5:{
	                    	string id; char t;
	                    	do{
	                    		system("cls"); cout << endl;
		                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
						    	cout << setw(60) << " " << "|    Nhập ID sản phẩm cần xóa   |           |\n"; 
						    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
		                        productManage.displayOption(1); cout << endl;
						    	gotoxy(95,3);
		                        cin >> id;  
		                        if(productManage.find(id) == nullptr) {
		                        	system("cls"); cout << endl; 
		                        	textcolor(228);
		                        	cout << setw(60) << " " << "+------------------------------+\n";
							    	cout << setw(60) << " " << "|  Không tìm thấy sản phẩm !!  |\n"; 
							    	cout << setw(60) << " " << "+------------------------------+\n" << endl;
							    	textcolor(224);
							    	cout << setw(60) << " " << "- Nhấn phím bất bỳ để tiếp tục\n\n"; cout << setw(60) << " " << "- Nhấn ESC để quay lại\n" << endl;
	                        		t = getch();
									if(t == 27){
										break;
									}
							    	system("pause");
								}
							}while(productManage.find(id) == nullptr);
	                        if(t != 27 || productManage.find(id) != nullptr){
	                        	productManage.remove(productManage.find(id)->data);	
		                        textcolor(226);
		                        cout << setw(60) << " " << "+------------------------------+\n";
							    cout << setw(60) << " " << "|   XÓA THÀNH CÔNG SẢN PHẨM    |\n"; 
							    cout << setw(60) << " " << "+------------------------------+\n" << endl;
							    textcolor(224);
		                        system("pause");
							}
							break;
						}
	                    case 6:{
	                    	string id, seri;
	                        int count;
	                        system("cls"); cout << endl;
	                    	cout << setw(60) << " " << "+-------------------------------+-----------+\n";
					    	cout << setw(60) << " " << "|    Nhập mã sản phẩm cần thêm  |           |\n"; 
					    	cout << setw(60) << " " << "+-------------------------------+-----------+\n" << endl;
	                        productManage.displayOption(1); cout << endl;
	                        gotoxy(95,3);
	                        cin >> id;  
	                        Node<Product>* prod = productManage.find(id);
	                        if (prod == nullptr){
	                        	system("cls"); cout << endl;
	                        	textcolor(228);
	                        	cout << setw(60) << " " << "+------------------------------------+\n";
						    	cout << setw(60) << " " << "|      Mã sản phẩm không tồn tại     |\n"; 
						    	cout << setw(60) << " " << "+------------------------------------+\n" << endl;
						    	textcolor(224);
	                        }
	                        else
	                        {
	                        	char t;
	                        	do{
	                        		system("cls");
		                        	cout << setw(60) << " " << "+-------------------------------+------+\n";
						    		cout << setw(60) << " " << "|    Nhập số lượng cần thêm     |      |\n"; 
						    		cout << setw(60) << " " << "+-------------------------------+------+\n" << endl;
		                            gotoxy(95,2); cin >> count;
		                            if(count <= 0){
		                            	textcolor(228);
			                            cout << endl<< setw(60) << " " << "+----------------------------------+\n";
							    		cout 		<< setw(60) << " " << "|    Số lượng không phù hợp !!     |\n"; 
							    		cout 		<< setw(60) << " " << "+----------------------------------+\n" << endl;
							    		textcolor(224);
	                        			cout << setw(60) << " " << "- Nhấn phím bất bỳ để tiếp tục\n\n"; cout << setw(60) << " " << "- Nhấn ESC để hủy nhập số lượng\n" << endl;
	                        			t = getch();
										if(t == 27){
											break;
										}
									}
								}while(count <= 0);
	                            if(t != 27 || count > 0){
	                            	for (int i = 0; i < count; i++){
		                            	cout << endl << setw(60) << " " << string(40, '-') << endl;
		                                cout << setw(60) << " " << "  Nhập seri thứ " << i+1 << ": "; cin >> seri;
		                                prod->data.addSerial(seri);
		                            }
		                            cout << setw(60) << " " << string(40, '-') << endl;
		                            textcolor(226);
		                            cout << setw(60) << " " << "+------------------------------------+\n";
								    cout << setw(60) << " " << "|     Thêm số lượng thành công       |\n"; 
								    cout << setw(60) << " " << "+------------------------------------+\n" << endl;
								    textcolor(224);
								    system("pause");
								}
	                        }
	                        cout << endl;
	                        system("pause");
							break;
						}
						case 7:
							over = false;
							break;
	                }
				}while(over);
				break;
			}
			case 3:{
				int option;
				bool over = true;
				do{
					system("cls");
					customerManage.display(); 
					do{
						cout << endl;
						cout << setw(60) << " " << "+-------------------------------------------+" << endl;
	                    cout << setw(60) << " " << "|\t\t1. Cập nhật khách hàng          |" << endl;
					    cout << setw(60) << " " << "|\t\t2. Tìm lịch sử mua hàng         |" << endl;
					    cout << setw(60) << " " << "|\t\t3. Quay lại                     |" << endl;
					    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
				    	cout << setw(60) << " " << ">> Mời bạn nhập chức năng >> "; 
				    	cin >> option;  
	                    if(option < 1 || option > 3){
				    		cout << endl;
				    		textcolor(228);
				    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 3. |\n"; 
					    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	textcolor(224);
					    	
					    	cout << setw(60) << " " << "+---------------------------------+\n";
					    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
					    	cout << setw(60) << " " << "+---------------------------------+\n";
					    	gotoxy(97,14);
					    	getch();
						}
	                }while(option < 1 || option > 3);
	                switch(option){
	                	case 1:{
	                		int id;
	                    	cout << endl;
					    	cout << setw(60) << " " << ">> Nhập ID khách hàng cần cập nhật: "; 
	                        cin >> id;  
	                        if(customerManage.find(id) == nullptr) {
	                        	cout << endl;
	                        	textcolor(228);
	                        	cout << setw(60) << " " << "+--------------------------------+\n";
						    	cout << setw(60) << " " << "|  Không tìm thấy khách hàng !!  |\n"; 
						    	cout << setw(60) << " " << "+--------------------------------+\n" << endl;
						    	textcolor(224);
							}
	                        else {
	                        	system("cls");
	                        	customerManage.edit(customerManage.find(id)->data);
	                        	if(customerManage.find(id)){
		                        	cout << setw(60) << " " << string(37, '=') << endl;
		                        	textcolor(226);
							        cout << setw(70) << " " << "CẬP NHẬT THÀNH CÔNG" << endl;
							        textcolor(224);
								}
							}
	                        system("pause");
							break;
						}
	                	case 2:{
	                		int id;
			                cout << endl;
							cout << setw(60) << " " << ">> Nhập mã khách hàng: "; 
							cin >> id;  
							Node<Customer>* fcus = customerManage.find(id);
			                if(fcus != nullptr){
			                	system("cls");
			                    fcus->data.Show();
			                    cout << endl << "  LỊCH SỦ MUA HÀNG: " << endl << endl;
			                    if(invoiceManage.find(fcus->data) == nullptr){
									textcolor(228);
									cout << setw(60) << " " << "+---------------------------+\n";
									cout << setw(60) << " " << "| Không có lịch sử mua hàng |\n"; 
									cout << setw(60) << " " << "+---------------------------+\n";
									textcolor(224);
								}
			                    else
									invoiceManage.find(fcus->data)->display();
			                }
			                else{
			                    cout << endl;
			                    textcolor(228);
								cout << setw(60) << " " << "+------------------------------------+\n";
								cout << setw(60) << " " << "|  Không tìm thấy mã khách hàng này  |\n";
								cout << setw(60) << " " << "+------------------------------------+\n";
			                    textcolor(224);
			                }
			                system("pause");
							break;
						}
	                	case 3:
	                		over = false;
	                		break;
					}
				}while(over);
				
				break;
			}
			case 4:{
				int option;
                do{
                    system("cls");
                    cout << setw(60) << " " << "+---------------------------------------------------+" << endl;
                    cout << setw(60) << " " << "|\t\t1. Nhập thông tin khách hàng mới        |" << endl;
                    cout << setw(60) << " " << "|\t\t2. Khách hàng cũ                        |" << endl;
				    cout << setw(60) << " " << "|\t\t3. Quay lại                             |" << endl;
				    cout << setw(60) << " " << "+---------------------------------------------------+\n" << endl;
				    cout << setw(60) << " " << "+------------------------+----+\n";
			    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |    |\n"; 
			    	cout << setw(60) << " " << "+------------------------+----+\n";
			    	gotoxy(88,8);
			    	cin >> option;  
                    if(option < 1 || option > 3){
			    		cout << endl;
			    		textcolor(228);
			    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 3. |\n"; 
				    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
				    	textcolor(224);
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	cout << setw(60) << " " << "| Nhấn phím bất kỳ để quay lại !! |\n"; 
				    	cout << setw(60) << " " << "+---------------------------------+\n";
				    	gotoxy(97,13);
				    	getch();
					}else{
						if(option == 3) break;	
	                	invoiceManage.sell(customerManage, productManage,option);
					}
                }while(option < 1 || option > 3);
				break;
			}
			case 5:{
				int option;
				bool over = true;
                do{
                	do{
	                    system("cls");
	                    cout << setw(60) << " " << "+-------------------------------------------+" << endl;
	                    cout << setw(60) << " " << "|\t\t1. Tìm theo mã hóa đơn          |" << endl;
					    cout << setw(60) << " " << "|\t\t2. Tìm theo năm                 |" << endl;
					    cout << setw(60) << " " << "|\t\t3. Tìm theo tháng               |" << endl;
					    cout << setw(60) << " " << "|\t\t4. Tìm theo ngày                |" << endl;
					    cout << setw(60) << " " << "|\t\t5. Quay lại	                |" << endl;
	                    cout << setw(60) << " " << "+-------------------------------------------+\n" << endl;
	                    cout << setw(60) << " " << "+------------------------+-----+\n";
				    	cout << setw(60) << " " << "| Mời bạn nhập chức năng |     |\n"; 
				    	cout << setw(60) << " " << "+------------------------+-----+\n";
				    	gotoxy(88,10);
				    	cin >> option;  
	                    if(option < 1 || option > 5){
				    		cout << endl;
				    		textcolor(228);
				    		cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	cout << setw(60) << " " << "| Vui lòng nhập lại chức năng !! Chức năng chỉ từ 1 đến 5. |\n"; 
					    	cout << setw(60) << " " << "+----------------------------------------------------------+\n";
					    	textcolor(224);
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
					    	cin >> id; cout << endl;  
	                        invoiceManage.findtoShow(id);
	                        system("pause");
							break;
						}
	                    case 2:{
	                    	int y;
	                    	cout << endl;
	                    	cout << setw(60) << " " << "+-----------------------------+-------+\n";
					    	cout << setw(60) << " " << "|    Nhập năm cần tìm kiếm    |       |\n"; 
					    	cout << setw(60) << " " << "+-----------------------------+-------+\n";
					    	gotoxy(93,13);
					    	cin >> y; cout << endl;  
					    	if(invoiceManage.find(y) == nullptr){
						    	textcolor(228);
					    		cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không tìm thấy hóa đơn hoặc dữ liệu không hợp lệ  |\n"; 
						    	cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	textcolor(224);
					    	}else
								invoiceManage.find(y)->display();
	                        system("pause");
							break;
						}
	                    case 3:{
	                    	int m,y;
	                    	cout << endl;
	                    	cout << setw(60) << " " << "+---------------------------+----+------+\n";
					    	cout << setw(60) << " " << "| Nhập lần lượt tháng, năm  |    |      |\n"; 
					    	cout << setw(60) << " " << "+---------------------------+----+------+\n" << endl;
					    	gotoxy(91,13); cin >> m;
							gotoxy(96,13); cin >> y; cout << endl;  
							if(invoiceManage.find(m, y) == nullptr){
						    	textcolor(228);
					    		cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không tìm thấy hóa đơn hoặc dữ liệu không hợp lệ  |\n"; 
						    	cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	textcolor(224);
					    	}else
								invoiceManage.find(m, y)->display();
	                        system("pause");
							break;
						}
	                    case 4:{
	                    	int d,m,y;
	                    	cout << endl;
	                    	cout << setw(60) << " " << "+---------------------------------+----+----+------+\n";
					    	cout << setw(60) << " " << "| Nhập lần lượt ngày, tháng, năm  |    |    |      |\n"; 
					    	cout << setw(60) << " " << "+---------------------------------+----+----+------+\n" << endl;
					    	gotoxy(97,13); cin >> d;
							gotoxy(102,13); cin >> m; 
							gotoxy(107,13); cin >> y; cout << endl;  
							if(invoiceManage.find(d,m,y) == nullptr){
						    	textcolor(228);
					    		cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	cout << setw(60) << " " << "| Không tìm thấy hóa đơn hoặc dữ liệu không hợp lệ  |\n"; 
						    	cout << setw(60) << " " << "+---------------------------------------------------+\n";
						    	textcolor(224);
					    	}else 
								invoiceManage.find(d, m, y)->display();
	                        system("pause");
							break;
						}
	                    case 5:
	                    	over = false;
	                        break;
	                }
				}while(over);
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
		    	do{
		    		cin >> Close;  
		    		if(Close != 1 && Close != 2){
			    		textcolor(228);
			    		cout << endl << endl;
			    		cout << setw(60) << " " << "Vui lòng nhập đúng chức năng !! Nhập lại: ";
			    		textcolor(224);
					} 	
				}while(Close != 1 && Close != 2);
				if(Close == 1){
					cout << endl;
					textcolor(226);
		    		cout << setw(60) << " " << "+--------------------------------------------+\n";
			    	cout << setw(60) << " " << "|   Bạn đã thoát chương trình thành công !!  |\n"; 
			    	cout << setw(60) << " " << "+--------------------------------------------+\n";
			    	textcolor(224);
		    		over = true;
//		    		system("pause");
				}
				break;
			}
		}
	}while(over != true);
}
 
#include <iostream>
#include "RoomManage.h"
#include "ClientManage.h"

int main() {
    RoomManage roomManager;
    ClientManage customerManager;

    // Thêm phòng
    roomManager.addRoom(Room(101, "Standard", false, 100));
    roomManager.addRoom(Room(102, "Deluxe", true, 150));

    // Hiển thị danh sách phòng
    roomManager.displayRooms();

    // Kiểm tra phòng trống
    cout << "Tinh trang phong:" << endl;
    roomManager.checkStateRoom();

    // Thêm khách thuê
    customerManager.addClient(Client("John Doe", "123456789", "0909090909","VietNam", 101));

    // Hiển thị danh sách khách
    customerManager.displayClients();

    return 0;
}

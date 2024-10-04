#include"Room.h"
#include<vector>

class RoomManage{
	private:
		vector<Room> rooms;
	public:
		void addRoom(const Room& room);
		Room* findRoom(int id);
		void deleteRoom(int id);
		void displayRooms() const;
		void checkStateRoom() const;
};
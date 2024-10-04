#include"RoomManage.h"
#include<iostream>

void RoomManage::addRoom(const Room& room){
	rooms.push_back(room);
}
Room* RoomManage::findRoom(int id){
	for(Room& room : rooms){
		if(room.getID() == id)
			return &room;
	}
	return NULL;
}
void RoomManage::deleteRoom(int id){
	for(auto it = rooms.begin(); it!=rooms.end(); it++){
		if(it->getID() == id){
			rooms.erase(it);
			break;
		}
	}
}
void RoomManage::displayRooms() const{
	for(const Room& room : rooms){
		room.display_info();
		cout << "-----------------" << endl;
	}
}
void RoomManage::checkStateRoom() const{
	for(const Room& room : rooms){
		if(!room.getState()){
			room.display_info();
			cout << "-----------------" << endl;
		}
	}
}
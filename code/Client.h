#include"Person.h"

class Client: public Person{
	private:
		string address;
		int idRoom;
	public:
		Client();
		Client(string name,string idCard,string phone,string address,int idRoom);
		//lay gia tri
		string getAddress() const;
		int getIdRoom() const;
		//gan gia tri
		void setAddress(string address);
		void setIdRoom(int room);
		~Client();
};
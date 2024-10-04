#include<string>
using namespace std;

class Room{
	private:
		int id;
		string type;
		bool state;
		double price;
	public:
		Room();
		Room(int id, string type, bool state, double price);
		//lay gia tri
		int getID() const;
		string getType() const;
		bool getState() const;
		double getPrice() const;
		//gan gia tri
		void setID(int id);
		void setType(string type);
		void setState(bool state);
		void setPrice(double price);
		
		void display_info() const;
		~Room();
};
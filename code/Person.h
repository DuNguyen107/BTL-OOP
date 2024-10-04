#include<string>
using namespace std;

class Person{
	protected:
		string name;
		string idCard;
		string phone;
	public:
		Person();
		Person(string name, string idCard, string phone);
		//lay gia tri
		string getName() const;
		string getIdCard() const;
		string getPhone() const;
		//gan gia tri
		void setName(string name);
		void setIdCard(string idCard);
		void setPhone(string phone);
		
		virtual void display_info() const;
		virtual ~Person();
};
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;


using namespace std;
#pragma once
class Person{
	protected:
		string name, phone, email, address;
		int id;
		bool gender;
	public:
		//constructor
		Person(string = "", string = "", string = "", string = "", int = 0, bool = true);
		~Person();
		//getter
		string getName();
		string getPhone();
		string getEmail();
		string getAddress();
		int getID();
		bool getGender();
		//setter
		void setName(string);
		void setPhone(string);
		void setEmail(string);
		void setAddress(string);
		void setID(int);
		void setGender(bool);
		//method
		bool operator!=(const Person&);
        bool operator==(const Person&);
		virtual void Show();
};


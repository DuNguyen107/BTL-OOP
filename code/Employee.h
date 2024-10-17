#include "Person.h"
#pragma once

enum Position{
	sales = 0, // tu van ban hang
	manager = 1 // quan ly
};
class Employee: public Person{
	private:
		Position position;
		double salary;
		string password;
	public:
		Employee(string = "", string = "", string = "", string = "", int = 0, bool = true, Position = manager, double = 0, string = "");
		~Employee();
		//getter
		Position getPosition();
		double getSalary();
		string getPassword();
		//setter
		void setPosition(Position);
		void setSalary(double);
		void setPassword(string);
		//method
		friend ostream& operator<<(ostream& os, const Employee& emp);
		void Show();
		bool changePassword();
};


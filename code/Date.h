#include<iostream>
#include<ctime>
using namespace std;
#pragma once
class Date{
	protected:
		int year;
		int month;
		int day;
	public:
		Date();
		Date(int,int,int);
		Date(const Date&);
		Date& operator = (const Date&);
		~Date();
		int getYear();
		int getMonth();
		int getDay();
		void setYear(int);
		void setMonth(int);
		void setDay(int);
		friend ostream& operator << (ostream&, const Date&);
		friend void getCurrent(Date&);
};
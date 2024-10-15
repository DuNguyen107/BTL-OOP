#include"Date.h"
Date::Date(){}
Date::Date(int day, int month, int year){
	this->year = year;
	this->month = month;
	this->day = day;
}
Date::Date(const Date& date){
	this->year = date.year;
	this->month = date.month;
	this->day = date.day;
}
Date& Date::operator =(const Date& date){
	if(this != &date){
		this->year = date.year;
		this->month = date.month;
		this->day = date.day;
	}
	return *this;
}
Date::~Date(){}
int Date::getYear(){
	return this->year;
}

int Date::getMonth(){
	return this->month;
}
int Date::getDay(){
	return this->day;
}
void Date::setYear(int year){
	this->year = year;
}
void Date::setMonth(int month){
	this->month = month;
}
void Date::setDay(int day){
	this->day = day;
}
void getCurrent(Date& date){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	date.setYear(1900 + ltm->tm_year);
	date.setMonth(1 + ltm->tm_mon);
	date.setDay(ltm->tm_mday);
}
ostream& operator << (ostream& os, const Date& date){
	os << date.day << "/" << date.month << "/" << date.year << "/";
	return os;
}

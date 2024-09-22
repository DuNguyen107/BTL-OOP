#include<iostream>
#include<string>
using namespace std;
class Nguoi{
	private:
		string hoTen, queQuan;
		int namSinh, gioiTinh;
	public:
		Nguoi();
		Nguoi(string hoTen, string queQuan, int namSinh, int gioiTinh);
		~Nguoi();
		string getHoTen();
		string getQueQuan();
		int getNamSinh();
		int getGioiTinh();
		void setHoTen(string hoTen);
		void setQueQuan(string QueQuan);
		void setNamSinh(int namSinh);
		void setGioiTinh(int gioiTinh);
		friend istream& operator >> (istream &is, Nguoi &p);
		friend ostream& operator << (ostream &os, Nguoi p);
};
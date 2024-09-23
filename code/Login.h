#include<string>
using namespace std;

class DangNhap{
	private:
		string TaiKhoan;
		string MatKhau;
	public:
		DangNhap();
		~DangNhap();
		string getTaiKhoan();
		string getMatKhau();
		void setTaiKhoan(string TaiKhoan);
		void setMatKhau(string MatKhau);		
};
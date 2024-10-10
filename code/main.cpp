#include <iostream>
#include"Person.h"
#include"Customer.h"
#include"Employee.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Person p("Duy", "0987654321", "duyle@gmail.com", "Quang Ngai", 0, true);
	Customer c("Duy", "0987654321", "duyle@gmail.com", "Quang Ngai", 123, true);
	Employee e("Linh", "0987654321", "linhle@gmail.com", "Quang Ngai", 678, false, manager, 200000, "linh123");
	p.Show(); cout << endl;
	c.Show(); cout << endl;
	e.Show(); cout << endl;
	return 0;
}
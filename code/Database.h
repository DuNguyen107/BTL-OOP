#include "ProdManage.h"
#include "EmpManage.h"
#include "CusManage.h"
#include "InvManage.h"

using namespace std;
class Database
{
	private:
	    ProdManage productM;
	    EmpManage employeeM;
	    CusManage customerM;
	    InvManage invoiceM;
	    static Database instance;
	    
	    Database();
	    ~Database();
	    Database(const Database&) = delete;
	    Database& operator=(const Database&) = delete;
    public:
	    static Database& DB_Instance();
	    ProdManage& getProdManage();
	    EmpManage& getEmpManage();
	    CusManage& getCusManage();
	    InvManage& getInvManage();
	    static void readData();
	    static void saveData();
};

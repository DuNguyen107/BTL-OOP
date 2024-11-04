#include "ProdManage.h"
#include "CusManage.h"
#include "InvManage.h"

using namespace std;
class Database
{
	private:
	    ProdManage productM;
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
	    CusManage& getCusManage();
	    InvManage& getInvManage();
	    static void readData();
	    static void saveData();
};

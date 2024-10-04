#include"Client.h"
#include<vector>

class ClientManage{
	private:
		vector<Client> clients;
	public:
		void addClient(const Client& client);
		Client* findClient(string idCard);
		void deleteClient(string id);
		void displayClients() const;
};
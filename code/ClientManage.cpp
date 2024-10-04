#include "ClientManage.h"
#include <iostream>

void ClientManage::addClient(const Client& client) {
    clients.push_back(client);
}

Client* ClientManage::findClient(string idCard) {
    for (Client& client : clients) {
        if (client.getIdCard() == idCard) {
            return &client;
        }
    }
    return NULL;
}

void ClientManage::deleteClient(string idCard) {
    for (auto it = clients.begin(); it != clients.end(); ++it) {
        if (it->getIdCard() == idCard) {
            clients.erase(it);
            break;
        }
    }
}

void ClientManage::displayClients() const {
    for (const Client& client : clients) {
        client.display_info();
        cout << "------------------------" << endl;
    }
}

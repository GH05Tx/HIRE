//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_CLIENTREPOSITORY_H
#define PRO_WYPO_CLIENTREPOSITORY_H
#include<memory>
#include<list>
using namespace std;
class Client;
typedef shared_ptr<Client> Client_ptr;

class ClientRepository {
    list<Client_ptr> cli_repo;
public:
    void addClient(Client_ptr);
    void removeClient(Client_ptr);
    void removeClient(int);
    string ClientReport();
    void changeType(Client_ptr,string);
};
typedef shared_ptr<ClientRepository>CR_ptr;
#endif //PRO_WYPO_CLIENTREPOSITORY_H

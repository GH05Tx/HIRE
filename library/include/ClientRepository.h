//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_CLIENTREPOSITORY_H
#define PRO_WYPO_CLIENTREPOSITORY_H
#include<memory>
#include<list>
#include "Repository.h"

using namespace std;
class Client;
typedef shared_ptr<Client> Client_ptr;

class ClientRepository: public Repository<Client_ptr>{
public:
    ClientRepository();
    void create(Client_ptr ptr);
    void remove(Client_ptr ptr);
    void update();
    std::string getAll(); //zwraca report
    Client_ptr find(std::string);
~ClientRepository();
    void removeClient(int);

    void changeType(Client_ptr,string);
};
typedef shared_ptr<ClientRepository>CR_ptr;
#endif //PRO_WYPO_CLIENTREPOSITORY_H

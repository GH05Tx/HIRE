//
// Created by Janek on 05.12.2018.
//
#include <ClientRepository.h>

#include "../include/ClientRepository.h"
#include "../include/client.h"

ClientRepository::ClientRepository() {

}
void ClientRepository::changeType(Client_ptr client, string nazwa)
{
    client->changeClientType(nazwa);
}

void ClientRepository::create(Client_ptr ptr) {
this->repoList.push_back(ptr);
}

void ClientRepository::remove(Client_ptr ptr) {
this->repoList.remove(ptr);
}

void ClientRepository::update() {
cout<<"co?"<<endl;
}

std::string ClientRepository::getAll() {
    string temp = "";
    for(Client_ptr client: this->repoList)
    {
      temp+=  client->clientInfo()+"\n ";
    }
}

Client_ptr ClientRepository::find(std::string str) {
    for(Client_ptr client: this->repoList)
    {
        if (client->getpersonalid()==str)
        {
            return client;
        }
    }}

ClientRepository::~ClientRepository() {

}



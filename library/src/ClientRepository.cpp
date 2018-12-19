//
// Created by Janek on 05.12.2018.
//
#include "../include/ClientRepository.h"
#include "../include/client.h"


void ClientRepository::addClient(Client_ptr client)
{
    cli_repo.push_back(client);
}

void ClientRepository::removeClient(Client_ptr client)
{
    cli_repo.remove(client);
}

string ClientRepository::ClientReport()
{
    string report="";
    for(auto it: cli_repo)
    {
        report+=it->clientInfo()+"\n";
    }
    return report;
}

void ClientRepository::removeClient(int index)
{

    int i=0;
    for(auto it: cli_repo)
    {
        i++;
        if(i==index) cli_repo.remove(it); 
    }
   
}

void ClientRepository::changeType(Client_ptr client, string nazwa)
{
    client->changeClientType(nazwa);
}
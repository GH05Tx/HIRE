
#include <RentsManager.h>
#include <RentException.h>

#include "../include/RentsManager.h"


void RentsManager::changeClientType(Client_ptr client)
{
list<Rent_ptr>rents = this->archiveRents.getAllClientRents(client);
int x = rents.size();
if(x=3)
{
    client->changeClientType("BRONZE");
}
if(x=5)
{
    client->changeClientType("SILVER");
}
if(x=7)
{
    client->changeClientType("GOLD");
}

}

RentsManager::RentsManager() {

}

void RentsManager::rentVehicle(Vehicle_ptr vehicle,Client_ptr client) {
if(this->currentRents.find(vehicle)!= nullptr)
{
    throw new RentException();
}
if(client->getNumberOfRents()>client->getMRents())
{
    throw new RentException();
}
Rent_ptr one(new Rent(vehicle,client));
this->currentRents.create(one);
}

void RentsManager::returnVehicle(Vehicle_ptr vehicle) {
    if(this->currentRents.find(vehicle)== nullptr)
    {
        throw new RentException();
    }
    Rent_ptr one = this->currentRents.find(vehicle);
    Client_ptr client_ptr = one->getClient();
    this->currentRents.remove(one); //???to czy to zadziala
    this->archiveRents.create(one);
    //tu mozna dodac spr czy klient awansowal
    this->changeClientType(client_ptr);
}



//
// Created by Janek on 05.12.2018.
//
#include <RentsManager.h>
#include <RentException.h>

#include "../include/RentsManager.h"


void RentsManager::changeClientType()
{

}

RentsManager::RentsManager() {

}

void RentsManager::rentVehicle(Vehicle_ptr vehicle,Client_ptr client) {
if(vehicle->getStatus())
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
    if(!vehicle->getStatus())
    {
        throw new RentException();
    }
    Rent_ptr one = this->currentRents.find(vehicle);
    this->currentRents.remove(one); //???to czy to zadziala
    this->archiveRents.create(one);
    //tu mozna dodac spr czy klient awansowal
}

list<Rent_ptr> RentsManager::getAllClientRents(Client_ptr ptr) {
    return list<Rent_ptr>();
}

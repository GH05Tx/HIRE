
#include <RentsManager.h>
#include <RentException.h>

#include "../include/RentsManager.h"

RentsManager::RentsManager() {

}

void RentsManager::changeClientType(Client_ptr client) {
    list<Rent_ptr> rents = this->archiveRents.getAllClientRents(client);
    int x = rents.size();
    if (x = 3) {
        client->changeClientType("BRONZE");
    }
    if (x = 5) {
        client->changeClientType("SILVER");
    }
    if (x = 7) {
        client->changeClientType("GOLD");
    }

}



void RentsManager::rentVehicle(Vehicle_ptr vehicle, Client_ptr client) {
    cout<<"JEDEN"<<endl;

    if (this->currentRents.find(vehicle)!=nullptr) {
        throw new RentException();
    }

    if (client->getNumberOfRents() > client->getMRents()) {
        throw new RentException();
    }
    vehicleRepository.create(vehicle);
    clientRepository.create(client);
    Rent_ptr one(new Rent(vehicle, client));
    this->currentRents.create(one);
}

void RentsManager::returnVehicle(Vehicle_ptr vehicle) {
    if (this->currentRents.find(vehicle) == nullptr) {
        throw new RentException();
    }
    Rent_ptr one = this->currentRents.find(vehicle);
    Client_ptr client_ptr = one->getClient();
    this->currentRents.remove(one);
    this->archiveRents.create(one);
    //tu mozna dodac spr czy klient awansowal
    this->changeClientType(client_ptr);
}

list<Rent_ptr> RentsManager::getAllClientRents(Client_ptr client) {
    return this->archiveRents.getAllClientRents(client);
}

int RentsManager::checkClientRentBallance(Client_ptr client) {
    list<Rent_ptr> lista = this->archiveRents.getAllClientRents(client);
    int cost;
    for (Rent_ptr rent: lista) {
        cost += rent->getCost();
    }
    return cost;
}





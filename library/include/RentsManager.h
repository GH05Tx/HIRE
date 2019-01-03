//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_RENTSMANAGER_H
#define PRO_WYPO_RENTSMANAGER_H


#include "client.h"
#include "vehicle.h"
#include "CurrentRentsRepository.h"
#include "ClientRepository.h"

class RentsManager
{

    CurrentRentsRepository currentRents;
    CurrentRentsRepository archiveRents;
    ClientRepository clientRepository;
public:
    RentsManager();
    void rentVehicle(Vehicle_ptr vehicle,Client_ptr client);
    void returnVehicle(Vehicle_ptr ptr);
    list <Rent_ptr> getAllClientRents(Client_ptr ptr);
    int checkClientRentBallance(Client_ptr);
    void changeClientType();
};


#endif //PRO_WYPO_RENTSMANAGER_H

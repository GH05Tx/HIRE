//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_RENTSMANAGER_H
#define PRO_WYPO_RENTSMANAGER_H


#include "client.h"
#include "vehicle.h"
#include "RentsRepository.h"
#include "ClientRepository.h"

class RentsManager
{

    RentsRepository currentRents;
    RentsRepository archiveRents;
    ClientRepository clientRepository;
public:
    RentsManager();
    void rentVehicle(Vehicle_ptr vehicle,Client_ptr client);
    void returnVehicle(Vehicle_ptr ptr);
    void changeClientType(Client_ptr);
};


#endif //PRO_WYPO_RENTSMANAGER_H

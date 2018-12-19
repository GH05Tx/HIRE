//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_RENTSMANAGER_H
#define PRO_WYPO_RENTSMANAGER_H


#include "client.h"

class RentsManager
{
    void returnVehicle();
    void getAllClientRents();
    void checkClientRentBallance(Client_ptr);
    void changeClientType();
};


#endif //PRO_WYPO_RENTSMANAGER_H

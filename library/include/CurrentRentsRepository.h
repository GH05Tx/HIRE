//
// Created by Janek on 01.12.2018.
//

#ifndef PRO_WYPO_CURRENTRENTSREPOSITORY_H
#define PRO_WYPO_CURRENTRENTSREPOSITORY_H
#include <list>
#include <iostream>
#include "../include/vehicle.h"
using namespace std;

class Vehicle;
class Rent;
typedef shared_ptr<Rent>Rent_ptr;
class CurrentRentsRepository
{
    list <Rent_ptr> repo;
public:
    void createRent(Rent_ptr);
    void removeRent(Rent_ptr);
    string getClientForRentedVehicle(Vehicle_ptr);
    string rentReport();
};

#endif //PRO_WYPO_CURRENTRENTSREPOSITORY_H

//
// Created by Janek on 25.11.2018.
//

#ifndef PRO_WYPO_VEHICLE_H
#define PRO_WYPO_VEHICLE_H
#include <iostream>
#include <cstdlib>
#include <memory>
#include "rent.h"
using namespace std;

class Vehicle
{
private:
    string id;
    int baseRentPrice;
    bool ifRented;
public:
    Vehicle(string, int);
    string vehicleInfo();
    string getID();
    bool getStatus();
    void setBool(bool);
    int actualRentalPrice();
    ~Vehicle();
};
typedef shared_ptr<Vehicle> Vehicle_ptr;
#endif //PRO_WYPO_VEHICLE_H

//
// Created by Janek on 25.11.2018.
//
#include "../include/vehicle.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <sstream>
#include <VehicleException.h>

using namespace std;

Vehicle::Vehicle(string tmp, int tmp2)
{
    if(tmp2<0)
    {
        throw new VehicleException("Vehicle Exception id<0");
    }

    this->id=tmp;
    this->baseRentPrice=tmp2;
    this->ifRented=false;
}

Vehicle::~Vehicle()=default;

void Vehicle::setBool(bool ifR)
{
    this->ifRented=ifR;
}

string Vehicle::vehicleInfo()
{
    stringstream tmp;
    if(ifRented)
        {
            tmp << id << " " << baseRentPrice << " rented";
        }
    if(!ifRented)
        {
            tmp << id << " " << baseRentPrice << " returned";
        }
    return tmp.str();
}

bool Vehicle::getStatus()
{
    return ifRented;
}

string Vehicle::getID()
{
    return id;
}

int Vehicle::actualRentalPrice()
{
    return baseRentPrice;
}

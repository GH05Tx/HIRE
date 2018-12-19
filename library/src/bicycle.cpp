//
// Created by Janek on 26.11.2018.
//
#include "../include/bicycle.h"
#include "../include/vehicle.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Bicycle::Bicycle(string id2, int baseprice):Vehicle(id2,baseprice){}

int Bicycle::actualRentalPrice()
{
    return baseRentPrice;
}

Bicycle::~Bicycle()=default;

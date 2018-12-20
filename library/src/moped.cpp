//
// Created by Janek on 26.11.2018.
//
#include "../include/moped.h"
#include <iostream>
#include <cstdlib>
#include <VehicleException.h>

using namespace std;

Moped::Moped(char seg, string id2, int base, int engine):MotorVehicle(id2,base,engine)
{
    this->segment=seg;
}

int Moped::actualRentalPrice()
{
    int price=baseRentPrice;
    float tmp;
    switch(segment)
    {
        case 'A':{tmp=1.0;}break;
        case 'B':{tmp=1.1;}break;
        case 'C':{tmp=1.2;}break;
        case 'D':{tmp=1.3;}break;
        case 'E':{tmp=1.5;}break;
        default:
            throw new VehicleException("No such segment VehicleException");
    }
    if(engineDisplacement<1000) {price*=tmp;}
    if(engineDisplacement>2000) {price*=tmp*1.5;}
    if(engineDisplacement>=1000 && engineDisplacement<=2000) {price*=(0.0005*engineDisplacement+0.5)*tmp;}
    return price;
}

char Moped::getSegment()
{
    return segment;
}

Moped::~Moped()=default;
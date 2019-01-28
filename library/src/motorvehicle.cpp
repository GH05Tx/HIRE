//
// Created by Janek on 02.12.2018.
//

#include <iostream>
#include <cstdlib>
#include "../include/motorvehicle.h"
#include "VehicleException.h"
using namespace std;

MotorVehicle::MotorVehicle(char seg, string id2, int base, int engine):Vehicle(id2,base)
{
    this->engineDisplacement=engine;
    this->segment=seg;
}

int MotorVehicle::getEngineDisplacement()
{
    return engineDisplacement;
}

int MotorVehicle::actualRentalPrice()
{
    float tmp;
    switch(segment)
    {
        case 'A':{tmp=1.0;}break;
        case 'B':{tmp=1.1;}break;
        case 'C':{tmp=1.2;}break;
        case 'D':{tmp=1.3;}break;
        case 'E':{tmp=1.5;}break;
        default: throw new VehicleException("Bad Segment Vehicle Exception");
    }
    return Vehicle::actualRentalPrice()*tmp;
}

char MotorVehicle::getSegment()
{
    return segment;
}

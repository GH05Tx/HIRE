//
// Created by Janek on 02.12.2018.
//

#include <iostream>
#include <cstdlib>
#include "../include/motorvehicle.h"
using namespace std;

MotorVehicle::MotorVehicle(string id2, int base, int engine):Vehicle(id2,base)
{
    this->engineDisplacement=engine;
}

int MotorVehicle::getEngineDisplacement()
{
    return engineDisplacement;
}

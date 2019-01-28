//
// Created by Janek on 26.11.2018.
//
#include "../include/moped.h"
#include <iostream>
#include <cstdlib>
#include <VehicleException.h>

using namespace std;

Moped::Moped(char seg, string id2, int base, int engine):MotorVehicle(seg,id2,base,engine)
{}

int Moped::actualRentalPrice()
{
    if(MotorVehicle::getEngineDisplacement()<1000) {return MotorVehicle::actualRentalPrice();}
    if(MotorVehicle::getEngineDisplacement()>2000) {return MotorVehicle::actualRentalPrice()*1.5;}
    if(MotorVehicle::getEngineDisplacement()>=1000 && MotorVehicle::getEngineDisplacement()<=2000) {return MotorVehicle::actualRentalPrice()*(0.0005*MotorVehicle::getEngineDisplacement()+0.5);}
}

Moped::~Moped()=default;
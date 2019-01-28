//
// Created by Janek on 26.11.2018.
//
#include "../include/car.h"
#include "../include/vehicle.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <VehicleException.h>

using namespace std;

Car::Car(char seg, string id2, int base, int engine):MotorVehicle(seg,id2,base,engine)
{}

int Car::actualRentalPrice()
{
    if(MotorVehicle::getEngineDisplacement()<1000) {return MotorVehicle::actualRentalPrice();}
    if(MotorVehicle::getEngineDisplacement()>2000) {return MotorVehicle::actualRentalPrice()*1.5;}
    if(MotorVehicle::getEngineDisplacement()>=1000 && MotorVehicle::getEngineDisplacement()<=2000) {return MotorVehicle::actualRentalPrice()*(0.0005*MotorVehicle::getEngineDisplacement()+0.5);}
}

Car::~Car()=default;

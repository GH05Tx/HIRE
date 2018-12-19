//
// Created by Janek on 26.11.2018.
//

#ifndef PRO_WYPO_MOTORVEHICLE_H
#define PRO_WYPO_MOTORVEHICLE_H
#include <iostream>
#include <cstdlib>
#include "vehicle.h"
using namespace std;

class MotorVehicle:public Vehicle
{
protected:
    int engineDisplacement;
public:
    MotorVehicle(string, int, int);
    int getEngineDisplacement();
};
#endif //PRO_WYPO_MOTORVEHICLE_H

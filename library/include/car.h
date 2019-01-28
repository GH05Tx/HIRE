//
// Created by Janek on 26.11.2018.
//

#ifndef PRO_WYPO_CAR_H
#define PRO_WYPO_CAR_H
#include <iostream>
#include <cstdlib>
#include <memory>
#include "motorvehicle.h"
using namespace std;

class Car: public MotorVehicle
{
public:
    Car(char,string, int, int);
    int actualRentalPrice();
    ~Car();
};
typedef shared_ptr<Car>Car_ptr;
#endif //PRO_WYPO_CAR_H

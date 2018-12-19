//
// Created by Janek on 26.11.2018.
//

#ifndef PRO_WYPO_BICYCLE_H
#define PRO_WYPO_BICYCLE_H
#endif //PRO_WYPO_BICYCLE_H
#include "../include/vehicle.h"

class Bicycle: public Vehicle
{
public:
    Bicycle(string, int);
    int actualRentalPrice();
    ~Bicycle();

};
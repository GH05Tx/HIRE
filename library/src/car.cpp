//
// Created by Janek on 26.11.2018.
//
#include "../include/car.h"
#include "../include/vehicle.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

Car::Car(char seg, string id2, int base, int engine):MotorVehicle(id2,base,engine)
{
    this->segment=seg;
}

int Car::actualRentalPrice()
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
    }
    if(engineDisplacement<1000) {price*=tmp;}
    if(engineDisplacement>2000) {price*=tmp*1.5;}
    if(engineDisplacement>=1000 && engineDisplacement<=2000) {price*=(0.0005*engineDisplacement+0.5)*tmp;}
    return price;
}

Car::~Car()=default;

char Car::getSegment()
{
    return segment;
}

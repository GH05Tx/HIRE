//
// Created by Janek on 01.12.2018.
//

#ifndef PRO_WYPO_CURRENTRENTSREPOSITORY_H
#define PRO_WYPO_CURRENTRENTSREPOSITORY_H
#include <list>
#include <iostream>
#include "../include/vehicle.h"
#include "Repository.h"

using namespace std;

class Vehicle;
class Rent;
typedef shared_ptr<Rent>Rent_ptr;
class CurrentRentsRepository:public Repository<Rent_ptr>
{
public:
    CurrentRentsRepository();
    void create(Rent_ptr ptr);
    void remove(Rent_ptr ptr);
    void update();
    std::string getAll(); //zwraca report
    Rent_ptr find(std::string str);
    Rent_ptr find(Vehicle_ptr ptr);
    ~CurrentRentsRepository();

};

#endif //PRO_WYPO_CURRENTRENTSREPOSITORY_H

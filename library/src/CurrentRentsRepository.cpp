//
// Created by Janek on 01.12.2018.
//

#include "../include/CurrentRentsRepository.h"
#include "../include/rent.h"
#include "../include/client.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <sstream>
using namespace std;

void CurrentRentsRepository::createRent(Rent_ptr tmp)
{
    repo.push_back(tmp);
}

void CurrentRentsRepository::removeRent(Rent_ptr tmp)
{
    repo.remove(tmp);
}

string CurrentRentsRepository::getClientForRentedVehicle(Vehicle_ptr tmp)
{
    for(auto it:repo)
    {
        return it->getClient()->clientInfo();
    }
}

string CurrentRentsRepository::rentReport()
{
    stringstream tmp;
    for(auto it:repo)
    {
        tmp << it->rentInfo() << "\n";
    }
    return tmp.str();
}
//
// Created by Janek on 25.11.2018.
//
#include <boost/uuid/random_generator.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "../include/rent.h"
#include "../include/vehicle.h"
#include "../include/car.h"
#include "../include/client.h"
#include "../include/address.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <cstddef>
#include <vector>
#include <ctime>
#include <RentException.h>

using namespace std;

Rent::Rent(Vehicle_ptr ptr, Client_ptr ptr2)
{
    if(ptr!=nullptr || ptr2!=nullptr)
    {
            this->uid=boost::uuids::random_generator()();
            this->rentDate=boost::local_time::local_sec_clock::local_time(timeZone);
            this->cost=0;
            this->vehicle=ptr;
            this->client=ptr2;
            vehicle->setBool(true);
            this->client->addNewRent();
    }
}

int Rent::rentDuration()
{
    if(returnDate.is_not_a_date_time()) throw new RentException();
    if(returnDate.date()<rentDate.date()) { cout << "ERROR";
    throw new RentException();
    }
    return (returnDate.date()-rentDate.date()).days()+1;
}

Rent::~Rent()=default;

string Rent::rentInfo()
{
    stringstream tmp;
    if(vehicle->getStatus())
    {
        tmp << vehicle->vehicleInfo()  << "  " << client->clientInfo() << "UID: " << uid << " FROM: " << rentDate << " COST: " << cost;
    }
    if(!vehicle->getStatus())
    {
        tmp << vehicle->vehicleInfo()  << "  " << client->clientInfo() << "UID: " << uid << " FROM: " << rentDate << " TO: " << returnDate << " COST: " << cost;

    }
    return tmp.str();
}

int Rent::rentCost()
{
    if(vehicle->getStatus()) {return 0;}
    if(!vehicle->getStatus()) {return vehicle->actualRentalPrice()*rentDuration()*client->getDiscount();}
}

void Rent::setVehicleBool(bool ifR)
{
    vehicle->setBool(ifR);
}

void Rent::returnVehicle()
{
    setVehicleBool(false);
    this->returnDate=boost::local_time::local_sec_clock::local_time(timeZone);
    this->cost=rentCost();
}

boost::uuids::uuid Rent::getUid()
{
    return uid;
}

int Rent::getCost()
{
    return cost;
}

Vehicle_ptr Rent::getVehicle()
{
    return vehicle;
}

Client_ptr Rent::getClient()
{
    return client;
}

//
// Created by Janek on 25.11.2018.
//

#ifndef PRO_WYPO_RENT_H
#define PRO_WYPO_RENT_H
#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/local_time/local_time.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include <cstdlib>
#include <memory>
#include "vehicle.h"
using namespace std;
class Client;
typedef shared_ptr<Client> Client_ptr;
class Vehicle;
typedef shared_ptr<Vehicle> Vehicle_ptr;

typedef boost::local_time::local_date_time LTime;
typedef boost::local_time::time_zone_ptr TZone;
typedef boost::posix_time::ptime PTime;

class Rent
{
    boost::uuids::uuid uid;
    double cost;
    Vehicle_ptr vehicle;
    Client_ptr client;
    TZone timeZone{new boost::local_time::posix_time_zone("CET+1")};
    LTime rentDate=LTime(PTime(), TZone());
    LTime returnDate=LTime(PTime(), TZone());

public:
    Rent(Vehicle_ptr,Client_ptr);
    ~Rent();
    int rentDuration();
    void setVehicleBool(bool);
    string rentInfo();
    void returnVehicle();
    int rentCost();
    boost::uuids::uuid getUid();
    int getCost();
    Vehicle_ptr getVehicle();
    Client_ptr getClient();

};
typedef shared_ptr<Rent>Rent_ptr;
#endif //PRO_WYPO_RENT_H

//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_VEHICLEREPOSITORY_H
#define PRO_WYPO_VEHICLEREPOSITORY_H
#include <memory>
#include <list>
#include "vehicle.h"
using namespace std;

class VehicleRepository:public Repository {
public:
    string vehicleReport();
    void addVehicle(Vehicle_ptr);
    Vehicle_ptr getVehicle(int);
};
typedef shared_ptr<VehicleRepository>VR_ptr;
#endif //PRO_WYPO_VEHICLEREPOSITORY_H

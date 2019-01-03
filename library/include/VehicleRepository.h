//
// Created by Janek on 05.12.2018.
//

#ifndef PRO_WYPO_VEHICLEREPOSITORY_H
#define PRO_WYPO_VEHICLEREPOSITORY_H
#include <memory>
#include <list>
#include "vehicle.h"
#include "Repository.h"
using namespace std;

class VehicleRepository:public Repository<Vehicle_ptr>{
public:
    VehicleRepository();
    void create(Vehicle_ptr veh);
    void remove(Vehicle_ptr veh);
    void update();
    std::string getAll(); //zwraca report
    Vehicle_ptr find(std::string str );
    ~VehicleRepository();
};
typedef shared_ptr<VehicleRepository>VR_ptr;
#endif //PRO_WYPO_VEHICLEREPOSITORY_H

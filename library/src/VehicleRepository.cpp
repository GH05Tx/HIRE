//
// Created by Janek on 05.12.2018.
//

#include "../include/VehicleRepository.h"
#include <memory>
#include <list>
#include <VehicleRepository.h>

using namespace std;

void VehicleRepository::create(Vehicle_ptr veh) {
    this->repoList.push_back(veh);
}
void VehicleRepository::remove(Vehicle_ptr veh) {
    this->repoList.remove(veh);
}
Vehicle_ptr VehicleRepository::find(std::string str) {
    for(Vehicle_ptr veh: this->repoList)
    {
        if (veh->getID()== str)
        {
            return veh;
        }
    }
}
std::string VehicleRepository::getAll() {
    string temp= " ";
    for(Vehicle_ptr veh: this->repoList)
    {
      temp+= veh->vehicleInfo() + " ";
    }
    return temp;
}
VehicleRepository::~VehicleRepository() {}

VehicleRepository::VehicleRepository() {

}

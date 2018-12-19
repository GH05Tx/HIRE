//
// Created by Janek on 05.12.2018.
//

#include "../include/VehicleRepository.h"
#include <memory>
#include <list>
using namespace std;

string VehicleRepository::vehicleReport()
{
    string report="";
    for(auto it: veh_repo)
    {
        report+=it-> vehicleInfo() + "\n";
    }
    return report;
}

void VehicleRepository::addVehicle(Vehicle_ptr veh)
{
    veh_repo.push_back(veh);
}

Vehicle_ptr VehicleRepository::getVehicle(int nr)
{
    int i=0;
    for(auto it: veh_repo)
    {
        i++;
        if(i==nr) return it;
    }
}
//
// Created by pobi on 20.12.18.
//

#ifndef OOPPROJECT_VEHICLEEXCEPTION_H
#define OOPPROJECT_VEHICLEEXCEPTION_H

#include <stdexcept>

using namespace std;
class VehicleException: public logic_error{
public:
VehicleException(string msg);

};


#endif //OOPPROJECT_VEHICLEEXCEPTION_H

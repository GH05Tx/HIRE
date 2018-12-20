//
// Created by pobi on 20.12.18.
//

#ifndef OOPPROJECT_RENTEXCEPTION_H
#define OOPPROJECT_RENTEXCEPTION_H

#include <stdexcept>

using namespace std;
class RentException: public logic_error {

public:
    RentException(string msg);

};


#endif //OOPPROJECT_RENTEXCEPTION_H

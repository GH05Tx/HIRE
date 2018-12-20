//
// Created by pobi on 20.12.18.
//

#ifndef OOPPROJECT_CLIENTEXCEPTION_H
#define OOPPROJECT_CLIENTEXCEPTION_H

#include<stdexcept>

using namespace std;
class ClientException: public logic_error {

public:
    ClientException(string msg);

};


#endif //OOPPROJECT_CLIENTEXCEPTION_H

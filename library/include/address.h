//
// Created by Janek on 25.11.2018.
//

#ifndef PRO_WYPO_ADDRESS_H
#define PRO_WYPO_ADDRESS_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include "../include/client.h"
using namespace std;

class Address
{
private:
    string street;
    string number;
public:
    Address(string,string);
    ~Address();
    string AddressInfo();
    void setStreet(string);
    string getStreet();
    void setNumber(string);
    string getNumber();
};
typedef shared_ptr<Address>Address_ptr;

#endif //PRO_WYPO_ADDRESS_H

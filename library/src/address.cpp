//
// Created by Janek on 25.11.2018.
//
#include "../include/address.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
using namespace std;

Address::Address(string str,string nr)
{
    this->street=str;
    this->number=nr;
}

string Address::AddressInfo()
{
    stringstream tmp;
    tmp << street << " " << number;
    return tmp.str();
}

Address::~Address()=default;

void Address::setStreet(string str)
{
    this->street=str;
}

string Address::getStreet()
{
    return street;
}

void Address::setNumber(string nr)
{
    this->number=nr;
}

string Address::getNumber()
{
    return number;
}


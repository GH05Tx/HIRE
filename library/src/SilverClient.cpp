//
// Created by Janek on 06.12.2018.
//
#include "../include/SilverClient.h"
#include <iostream>
using namespace std;

double SilverClient::discount(int x)
{
    return 1-(0.1+(4/3)*x*0.01);
}

int SilverClient::getMRents()
{
    return maxRents;
}

SilverClient::SilverClient()
{
    this->maxRents=15;
}
//
// Created by Janek on 06.12.2018.
//

#include "../include/GoldClient.h"
#include <iostream>
using namespace std;

double GoldClient::discount(int x)
{
    return 1-(0.15+0.015*x);
}

int GoldClient::getMRents()
{
    return maxRents;
}

GoldClient::GoldClient()
{
    this->maxRents=20;
}
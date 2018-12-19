//
// Created by Janek on 06.12.2018.
//
#include "../include/BronzeClient.h"
#include <iostream>
using namespace std;

double BronzeClient::discount(int x)
{
    return 1-(x*0.01+0.05);
}

int BronzeClient::getMRents()
{
    return maxRents;
}

BronzeClient::BronzeClient()
{
    this->maxRents=10;
}
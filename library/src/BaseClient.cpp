//
// Created by Janek on 06.12.2018.
//
#include <iostream>
#include "../include/BaseClient.h"
using namespace std;

double BaseClient::discount(int x)
{
    return 1;
}

int BaseClient::getMRents()
{
    return maxRents;
}

BaseClient::BaseClient()
{
    this->maxRents=5;
}
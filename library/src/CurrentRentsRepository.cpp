//
// Created by Janek on 01.12.2018.
//

#include "../include/CurrentRentsRepository.h"
#include "../include/rent.h"
#include "../include/client.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <sstream>
#include <CurrentRentsRepository.h>

using namespace std;

void CurrentRentsRepository::create(Rent_ptr ptr) {
this->repoList.push_back( ptr);
}

void CurrentRentsRepository::remove(Rent_ptr ptr) {
this->repoList.remove(ptr);
}

void CurrentRentsRepository::update() {

}

std::string CurrentRentsRepository::getAll() {
string temp = "";
for(Rent_ptr ptr: this->repoList)
{
    temp += ptr->rentInfo();
}
return temp;
}

Rent_ptr CurrentRentsRepository::find(std::string str) {
    for(Rent_ptr ptr: this->repoList)
    {
if(true/*?co tu ma byc*/)
{
    return ptr;
}
    }}

CurrentRentsRepository::~CurrentRentsRepository() {

}

CurrentRentsRepository::CurrentRentsRepository() {

}

Rent_ptr CurrentRentsRepository::find(Vehicle_ptr ptr) {
    for(Rent_ptr ptr : this->repoList)
    {
        if (ptr->getVehicle()==ptr)
        {
            return ptr;
        }
    }
}

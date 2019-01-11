#include "../include/RentsRepository.h"
#include "../include/rent.h"
#include "../include/client.h"
#include <iostream>
#include <cstdlib>
#include <list>
#include <sstream>
#include <../include/RentException.h>

using namespace std;

RentsRepository::RentsRepository() {

}
void RentsRepository::create(Rent_ptr ptr) {
    this->repoList.push_back(ptr);
}

void RentsRepository::remove(Rent_ptr ptr) {
    this->repoList.remove(ptr);
}

void RentsRepository::update() {

}

std::string RentsRepository::getAll() {
    string temp = "";
    for (Rent_ptr ptr: this->repoList) {
        temp += ptr->rentInfo();
    }
    if(temp=="")
    {
        throw new RentException();
    }
    return temp;
}

Rent_ptr RentsRepository::find(std::string str) {
    for (Rent_ptr ptr: this->repoList) {
        if (true/*?co tu ma byc*/) {
            return ptr;
        }
    }
    throw new RentException();
}





Rent_ptr RentsRepository::find(Vehicle_ptr ptr) {
    for (Rent_ptr ptr : this->repoList) {
        if (ptr->getVehicle() == ptr->getVehicle()) {
            return ptr;
        }
    }
    throw new RentException();
}

list<Rent_ptr> RentsRepository::getAllClientRents(Client_ptr ptr) {
    list<Rent_ptr> rents;
    for (Rent_ptr ptr1 : this->repoList) {
        if (ptr1->getClient() == ptr) {
            rents.push_back(ptr1);
        }
    }
    if(rents.empty())
    {
        throw new RentException();
    }
    return rents;

}

RentsRepository::~RentsRepository() {

}
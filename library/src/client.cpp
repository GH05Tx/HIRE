//
// Created by Janek on 25.11.2018.
//
#include "../include/client.h"
#include "../include/address.h"
#include "../include/rent.h"
#include "../include/vehicle.h"
#include "../include/BaseClient.h"
#include "../include/BronzeClient.h"
#include "../include/GoldClient.h"
#include "../include/SilverClient.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <memory>
#include <cstddef>
#include <list>
using namespace std;

Client::Client(string fn, string ln, string pid, Address_ptr a, Address_ptr ra)
{
    this->firstName=fn;
    this->lastName=ln;
    this->personalid=pid;
    this->address=a;
    this->registeredAddress=ra;
    this->client_type=ClientType_ptr(new BaseClient());
}

string Client::clientInfo()
{
    stringstream tmp;
    if(registeredAddress==nullptr || address==nullptr)
        {
             tmp << firstName << " " << lastName << " " << personalid;
             return tmp.str();
        }
    if(registeredAddress!=nullptr || address!=nullptr)
        {
            tmp << firstName << " " << lastName << " " << personalid << " " << registeredAddress->AddressInfo() << " " <<  address->AddressInfo() << " ";
            return tmp.str();
        }
}

void Client::changeClientType(string nazwa)
{
   if(nazwa.compare("BRONZE")==0 or nazwa.compare("bronze")==0)
   {
       client_type=ClientType_ptr(new BronzeClient());
   }
   else if(nazwa.compare("GOLD")==0 or nazwa.compare("gold")==0)
   {
       client_type=ClientType_ptr(new GoldClient());
   }
   else if(nazwa.compare("SILVER")==0 or nazwa.compare("silver")==0)
   {
       client_type=ClientType_ptr(new SilverClient());
   }
   else if(nazwa.compare("BASE")==0 or nazwa.compare("base")==0)
   {
       client_type=ClientType_ptr(new BaseClient());
   }
   else
   {
       cout << "THERE IS NO CLIENT TYPE MATCHING!" << endl;
   }
}

void Client::addRent(Rent_ptr rent)
{
    rents.push_back(rent);

}

void Client::removeRent(Rent_ptr rent)
{
    rents.remove(rent);

}

Address_ptr Client::getRegAddress()
{
    return registeredAddress;
}
Address_ptr Client::getAddress()
{
    return address;
}

string Client::getWholeAddress()
{
    stringstream tmp;
    tmp << address->AddressInfo() << " " << registeredAddress->AddressInfo();
    return tmp.str();
}

int Client::getMRents()
{
    return client_type->getMRents();
}

double Client::getDiscount()
{
    return client_type->discount(getNrVehicles());
}

int Client::getNrVehicles()
{
    int tmp=0;
    for(auto it: rents)
    {
        if((it->getVehicle())->getStatus())   tmp++;
    }
    return tmp;
}

void Client::showRentsInfo()
{
    bool check=rents.empty();
    if (check) {cout << "NO RENTS" << endl;}
    if (!check) {
        for(auto it:rents)
            {
                cout << it->rentInfo() << "\n";
            }
    }
}

Client::~Client()=default;

string Client::getFirstName()
{
    return firstName;
}

string Client::getlastName()
{
    return lastName;
}

string Client::getpersonalid()
{
    return personalid;
}

void Client::setAddress(Address_ptr adr)
{
    this->address=adr;
}

Address_ptr Client::getregisteredAddress()
{
    return registeredAddress;
}

void Client::setregisteredAddress(Address_ptr rA)
{
    this->registeredAddress=rA;
}
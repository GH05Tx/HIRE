//
// Created by Janek on 25.11.2018.
//

#ifndef PRO_WYPO_CLIENT_H
#define PRO_WYPO_CLIENT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <list>

using namespace std;

class Address;
typedef shared_ptr<Address>Address_ptr;
class Rent;
typedef shared_ptr<Rent>Rent_ptr;
class ClientType;
typedef shared_ptr<ClientType>ClientType_ptr;

class Client
{
private:
    list <Rent_ptr> rents;
    string firstName;
    string lastName;
    string personalid;
    Address_ptr registeredAddress;
    Address_ptr address;
    ClientType_ptr client_type;
    int numberOfRents;
public:
    Client(string, string, string, Address_ptr, Address_ptr);
    ~Client();
    string clientInfo();
    void addRent(Rent_ptr);
    void removeRent(Rent_ptr);
    void showRentsInfo();
    int getMRents();
    double getDiscount();
    int getNrVehicles();
    void changeClientType(string);
    string getFirstName();
    string getlastName();
    string getpersonalid();
    string getWholeAddress();
    Address_ptr getAddress();
    Address_ptr getRegAddress();
    void setAddress(Address_ptr);
    Address_ptr getregisteredAddress();
    void setregisteredAddress(Address_ptr);
    ClientType_ptr getClient_type();
    int getNumberOfRents();
    void addNewRent();
};
typedef shared_ptr<Client> Client_ptr;

#endif //PRO_WYPO_CLIENT_H

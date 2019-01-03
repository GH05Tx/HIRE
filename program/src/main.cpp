#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <list>
#include "../include/client.h"
#include "../include/address.h"
#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/moped.h"
#include "../include/motorvehicle.h"
#include "../include/vehicle.h"
#include "../include/rent.h"
#include "RentsRepository.h"
#include "../include/VehicleRepository.h"
#include "../include/ClientRepository.h"

using namespace std;

int main()
{
    srand(time(NULL));
    Address_ptr tmp1(new Address("Wojska Polskiego", "9"));
    Address_ptr tmp2(new Address("Piotrkowska", "1"));
    Client_ptr clt(new Client("Jan","Kowalski","98050909219",tmp1,tmp2));
    cout << clt->clientInfo();
    tmp1->setStreet("Pstragowa");
    cout << endl << "CHANGE OF THE ADDRESS" << endl;
    cout << clt->clientInfo() << endl;

    Vehicle_ptr cptr (new Car('E',"EZG137",100,6300));
    cout << cptr->vehicleInfo() << " faktyczna cena: " << cptr->actualRentalPrice()<< endl;

    Vehicle_ptr cptr2 (new Moped('D',"EL4204",160,3000));
    cout << cptr2->vehicleInfo() << " faktyczna cena: " << cptr2->actualRentalPrice()<< endl;

    Rent_ptr one(new Rent(cptr,clt));
    clt->addRent(one);
    Rent_ptr two(new Rent(cptr2,clt));
    clt->addRent(two);

    cout << endl << "RENT 1" << endl;
    cout << one->rentInfo();
    cout << endl << "RENT 2" << endl;
    cout << two->rentInfo();
    cout << endl << "RENTS-BEGIN" << endl;
    //clt->addRent(one);
    cout << "CAR PTR: " << cptr->vehicleInfo() << endl;
    clt->showRentsInfo();
    cout << "Actual price RPTR: " << cptr->actualRentalPrice()<< endl;
    one->returnVehicle();
    cout << "CAR PTR: " << cptr->vehicleInfo() << endl;
    clt->showRentsInfo();
    two->returnVehicle();
    //clt->removeRent(one);
    cout << "RENTS-END" << endl;
    clt->showRentsInfo();
    cout << endl << "----------" << endl;


    cout << "RENT REPOSITORY" << endl;
    RentsRepository repo;
    repo.createRent(one);
    repo.createRent(two);
    repo.rentReport();
    cout << repo.getClientForRentedVehicle(cptr) << endl;
    repo.removeRent(two);
    repo.rentReport();

    cout << endl << "----------" << endl;
    cout << "VEHICLE REPOSITORY" << endl;
    Vehicle_ptr vptr (new Car('E',"EZG420",100,6300));
    cout << vptr->vehicleInfo() << endl;
    Vehicle_ptr vptr2 (new Bicycle("EL666",50));
    cout << vptr2->vehicleInfo() << endl;
    Vehicle_ptr vptr3 (new Moped('E',"WW2131",90,6300));
    cout << vptr3->vehicleInfo() << endl;
    Vehicle_ptr vptr4 (new Car('A',"WJ5431",100,700));
    Vehicle_ptr vptr5 (new Moped('B',"EL0031",90,5250));
    Vehicle_ptr vptr6 (new Moped('D',"EZG161",70,2300));
    Vehicle_ptr vptr7 (new Car('C',"EZD431",50,6300));
    Vehicle_ptr vptr8 (new Bicycle("EL696",450));
    Vehicle_ptr vptr9 (new Car('B',"WW2131",150,630));
    Vehicle_ptr vptr10 (new Moped('D',"WW2131",100,6400));
    VR_ptr vehRepo(new VehicleRepository());
    vehRepo->addVehicle(vptr);
    vehRepo->addVehicle(vptr2);
    vehRepo->addVehicle(vptr3);
    vehRepo->addVehicle(vptr4);
    vehRepo->addVehicle(vptr5);
    vehRepo->addVehicle(vptr6);
    vehRepo->addVehicle(vptr7);
    vehRepo->addVehicle(vptr8);
    vehRepo->addVehicle(vptr9);
    vehRepo->addVehicle(vptr10);
    cout << "REPORT: " << endl;
    cout << vehRepo->vehicleReport();
    cout << "----" << endl;
    cout << (vehRepo->getVehicle(2))->vehicleInfo();
    /*
    cout << endl << "----------" << endl;
    cout << "CLIENT REPOSITORY" << endl;
    CR_ptr cltRepo(new ClientRepository());
    Client_ptr clt2(new Client("Aneta","Butna","43050900919",tmp1,tmp2));
    Client_ptr clt3(new Client("Mirek","Zasadny","98063709219",tmp1,tmp2));
    cltRepo->addClient(clt);
    cout << clt->clientInfo() << endl;
    cltRepo->addClient(clt2);
    cout << clt2->clientInfo() << endl;
    cltRepo->addClient(clt3);
    cout << clt3->clientInfo() << endl;
    cout << endl << "CLIENT REPORT" << endl;
    cout << cltRepo->ClientReport();
    cout << endl << "AFTER REMOVE:" << endl;
    cltRepo->removeClient(clt2);
    cout << cltRepo->ClientReport();

    cout << endl << "----------" << endl;
    cout<< "WITHOUT DISCOUNT: "<< one->rentCost() << endl;
    cout<< "GOLD CLIENT" << endl;
    clt->changeClientType("gold");
    cout << "WITH DISCOUNT: " << one->rentCost() << endl;
    cout << "DISCOUNT: " << (1-clt->getDiscount())*100 << "%";
    cout << endl << "----------" << endl << "SILVER CLIENT" << endl;
    clt->changeClientType("silver");
    cout << "WITH DISCOUNT: " << one->rentCost() << endl;
    cout << "DISCOUNT: " << (1-clt->getDiscount())*100 << "%";
    cout << endl << "----------" << endl << "BRONZE CLIENT" << endl;
    clt->changeClientType("bronze");
    cout << "WITH DISCOUNT: " << one->rentCost() << endl;
    cout << "DISCOUNT: " << (1-clt->getDiscount())*100 << "%";
*/
    cout << endl << "---------" << endl << clt->getNrVehicles() << endl;

    Rent_ptr rent1(new Rent(vptr8 ,clt));
    Rent_ptr rent2(new Rent(vptr9,clt));
    Rent_ptr rent3(new Rent(vptr5 ,clt));
    Rent_ptr rent4(new Rent(vptr6,clt));
    Rent_ptr rent5(new Rent(vptr10,clt));
    Rent_ptr rent6(new Rent(vptr2,clt));

    clt->addRent(rent1);
    clt->addRent(rent2);
    clt->addRent(rent3);
    clt->addRent(rent4);
    clt->addRent(rent5);
    clt->addRent(rent6);

    clt->showRentsInfo();

    return 0;
}

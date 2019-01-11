#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <ctime>
#include <list>
#include <RentsManager.h>
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
    cout<<"HELLO"<<endl;

    srand(time(NULL));

    RentsManager *manager = new RentsManager();

    Address_ptr tmp1(new Address("Wojska Polskiego", "9"));
    Address_ptr tmp2(new Address("Piotrkowska", "1"));
    Client_ptr clt(new Client("Jan","Kowalski","98050909219",tmp1,tmp2));
    Client_ptr clt2(new Client("Aneta","Butna","43050900919",tmp1,tmp2));
    Client_ptr clt3(new Client("Mirek","Zasadny","98063709219",tmp1,tmp2));


    Vehicle_ptr cptr (new Car('E',"EZG137",100,6300));
    Vehicle_ptr cptr2 (new Moped('D',"EL4204",160,3000));
    Vehicle_ptr vptr (new Car('E',"EZG420",100,6300));
    Vehicle_ptr vptr2 (new Bicycle("EL666",50));
    Vehicle_ptr vptr3 (new Moped('E',"WW2131",90,6300));
    Vehicle_ptr vptr4 (new Car('A',"WJ5431",100,700));
    Vehicle_ptr vptr5 (new Moped('B',"EL0031",90,5250));
    Vehicle_ptr vptr6 (new Moped('D',"EZG161",70,2300));
    Vehicle_ptr vptr7 (new Car('C',"EZD431",50,6300));
    Vehicle_ptr vptr8 (new Bicycle("EL696",450));
    Vehicle_ptr vptr9 (new Car('B',"WW2131",150,630));
    Vehicle_ptr vptr10 (new Moped('D',"WW2131",100,6400));



    manager->rentVehicle(cptr,clt);
    manager->rentVehicle(vptr,clt);
    //cout<<"Tu rzuci exc"<<endl;
    //manager->rentVehicle(vptr,clt2);
    manager->returnVehicle(vptr);

    //delete manager;
    return 0;
}

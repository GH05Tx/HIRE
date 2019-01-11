#include <boost/test/unit_test.hpp>
#include <RentsManager.h>
#include <RentException.h>
#include "../include/client.h"
#include "../include/address.h"
#include "../include/bicycle.h"
#include "../include/car.h"
#include "../include/moped.h"
#include "../include/motorvehicle.h"
#include "../include/vehicle.h"
#include "../include/rent.h"

BOOST_AUTO_TEST_SUITE(ManagerSuite)

    BOOST_AUTO_TEST_CASE(ManagerNoExceptCase)
    {
        RentsManager *manager = new RentsManager();
        Address_ptr tmp1(new Address("Wojska Polskiego", "9"));
        Address_ptr tmp2(new Address("Piotrkowska", "1"));
        Client_ptr clt(new Client("Jan","Kowalski","98050909219",tmp1,tmp2));
        Client_ptr clt2(new Client("Aneta","Butna","43050900919",tmp1,tmp2));
        Vehicle_ptr cptr (new Car('E',"EZG137",100,6300));
        Vehicle_ptr cptr2 (new Moped('D',"EL4204",160,3000));
        Vehicle_ptr vptr (new Car('E',"EZG420",100,6300));
        Vehicle_ptr vptr2 (new Bicycle("EL666",50));
        Vehicle_ptr vptr3 (new Moped('E',"WW2131",90,6300));
        Vehicle_ptr vptr4 (new Car('A',"WJ5431",100,700));
        BOOST_REQUIRE_EQUAL(manager->rentVehicle(cptr,clt),true);
        BOOST_REQUIRE_EQUAL(manager->rentVehicle(cptr2,clt),true);
        BOOST_CHECK_THROW(manager->rentVehicle(cptr2,clt),RentException);
        BOOST_REQUIRE_EQUAL(manager->checkClientRentBallance(clt),0);
        BOOST_REQUIRE_EQUAL(manager->returnVehicle(cptr),true);
        BOOST_CHECK_THROW(manager->returnVehicle(cptr),RentException);



    }
BOOST_AUTO_TEST_SUITE_END()


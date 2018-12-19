//
// Created by pobi on 19.12.18.
//
#include <boost/test/unit_test.hpp>
#include <address.h>
#include <rent.h>
#include <client.h>
#include <moped.h>
#include <car.h>

BOOST_AUTO_TEST_SUITE(VehicleSuite)

    BOOST_AUTO_TEST_CASE(VehicleFunctionsCase)
    {
        Vehicle_ptr cptr (new Car('A',"WJ5431",100,700));
        BOOST_REQUIRE_EQUAL(cptr->vehicleInfo(),"WJ5431 100 returned");
        BOOST_REQUIRE_EQUAL(cptr->getStatus(),false);
        cptr->setBool(true);
        BOOST_REQUIRE_EQUAL(cptr->getStatus(),true);
        BOOST_REQUIRE_EQUAL(cptr->actualRentalPrice(),100);
    }

    BOOST_AUTO_TEST_CASE(RentVehicleCase)
    {
        Address_ptr add(new Address("Rojna","420"));
        Address_ptr add2(new Address("Piotrkowska","112"));
        Client_ptr client(new Client("Marek","Mostowiak","990934243",add,add2));
        Vehicle_ptr cptr (new Car('E',"EZG137",100,6300));
        BOOST_REQUIRE_EQUAL(cptr->getStatus(),false);
        Rent_ptr one(new Rent(cptr,client));
        client->addRent(one);
        BOOST_REQUIRE_EQUAL(client->getNrVehicles(),1);
        BOOST_REQUIRE_EQUAL(cptr->getStatus(),true);
        BOOST_REQUIRE_EQUAL(one->rentDuration(),0);
        one->returnVehicle();
        BOOST_REQUIRE_EQUAL(cptr->getStatus(),false);
        BOOST_REQUIRE_EQUAL(one->rentDuration(),1);
        BOOST_REQUIRE_EQUAL(client->getNrVehicles(),0);
        client->removeRent(one);
        BOOST_REQUIRE_EQUAL(client->getNrVehicles(),0);
    }

BOOST_AUTO_TEST_SUITE_END()

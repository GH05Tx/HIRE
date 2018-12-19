#include <boost/test/unit_test.hpp>
#include <address.h>
#include <rent.h>
#include <client.h>
#include <moped.h>
#include <car.h>

BOOST_AUTO_TEST_SUITE(ClientSuite)

BOOST_AUTO_TEST_CASE(ClientAddressInfoCase)
{
    Address_ptr add(new Address("Rojna","420"));
    Address_ptr add2(new Address("Piotrkowska","112"));
    Client_ptr client(new Client("Marek","Mostowiak","990934243",add,add2));
    BOOST_REQUIRE_EQUAL(add->AddressInfo(), "Rojna 420");
    BOOST_REQUIRE_EQUAL(add2->AddressInfo(), "Piotrkowska 112");
}

BOOST_AUTO_TEST_CASE(AddressChangeCase)
{
    Address_ptr add(new Address("Rojna","420"));
    Address_ptr add2(new Address("Piotrkowska","112"));
    Client_ptr client(new Client("Marek","Mostowiak","990934243",add,add2));
    Client_ptr client2(new Client("Zdzislaw","Byczkowski","964564243",add,add2));
    BOOST_REQUIRE_EQUAL(client->getWholeAddress(), "Rojna 420 Piotrkowska 112");
    BOOST_REQUIRE_EQUAL(client2->getWholeAddress(), "Rojna 420 Piotrkowska 112");
    add->setStreet("Marynarska");
    BOOST_REQUIRE_EQUAL(client->getWholeAddress(), "Marynarska 420 Piotrkowska 112");
    BOOST_REQUIRE_EQUAL(client2->getWholeAddress(), "Marynarska 420 Piotrkowska 112");
}

BOOST_AUTO_TEST_CASE(ClientRentCase)
{
   Address_ptr add(new Address("Rojna","420"));
   Address_ptr add2(new Address("Piotrkowska","112"));
   Client_ptr client(new Client("Marek","Mostowiak","990934243",add,add2));
   Vehicle_ptr cptr (new Car('E',"EZG137",100,6300));
   Vehicle_ptr cptr2 (new Moped('D',"EL4204",160,3000));
   Rent_ptr one(new Rent(cptr,client));
   Rent_ptr two(new Rent(cptr2,client));
   client->addRent(one);
   client->addRent(two);
   BOOST_REQUIRE_EQUAL(client->getNrVehicles(),2);
}

BOOST_AUTO_TEST_SUITE_END()

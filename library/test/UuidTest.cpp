//
// Created by pobi on 03.01.19.
//
#include <boost/test/unit_test.hpp>
#include <rent.h>
#include <address.h>
#include <car.h>
#include <bicycle.h>
#include <moped.h>

BOOST_AUTO_TEST_SUITE(UuidSuite)

BOOST_AUTO_TEST_CASE(RentUuidCase)
        {
                Vehicle_ptr vptr1 (new Car('A',"WJ5431",100,700));
                Vehicle_ptr vptr2 (new Moped('B',"EL0031",90,5250));
                Vehicle_ptr vptr3 (new Moped('D',"EZG161",70,2300));
                Vehicle_ptr vptr4 (new Car('C',"EZD431",50,6300));
                Vehicle_ptr vptr5 (new Bicycle("EL696",450));
                Address_ptr add(new Address("Rojna","420"));
                Address_ptr add2(new Address("Piotrkowska","112"));
                Client_ptr clt(new Client("Marek","Mostowiak","990934243",add,add2));

                Rent_ptr rent1(new Rent(vptr1 , clt));
                Rent_ptr rent2(new Rent(vptr2,clt));
                Rent_ptr rent3(new Rent(vptr3 ,clt));
                Rent_ptr rent4(new Rent(vptr4,clt));
                Rent_ptr rent5(new Rent(vptr5,clt));
                Rent_ptr rent6(new Rent(vptr1,clt));
                Rent_ptr rent7(new Rent(vptr2 ,clt));
                Rent_ptr rent8(new Rent(vptr3,clt));
                Rent_ptr rent9(new Rent(vptr4 ,clt));
                Rent_ptr rent10(new Rent(vptr5,clt));

                Rent_ptr tab[10];
                tab[0]=rent1;
                tab[1]=rent2;
                tab[2]=rent3;
                tab[3]=rent4;
                tab[4]=rent5;
                tab[5]=rent6;
                tab[6]=rent7;
                tab[7]=rent8;
                tab[8]=rent9;
                tab[9]=rent10;

                for(int i=0; i<10; i++)
                {
                    for(int j=0; j<10; j++)
                    {
                        if(i!=j) BOOST_CHECK(tab[i]->getUid()!=tab[j]->getUid());
                    }
                }
        }
BOOST_AUTO_TEST_SUITE_END()
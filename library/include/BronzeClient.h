//
// Created by Janek on 06.12.2018.
//

#ifndef PRO_WYPO_BRONZECLIENT_H
#define PRO_WYPO_BRONZECLIENT_H
#include "ClientType.h"
#include <memory>
using namespace std;

class BronzeClient: public ClientType {
private:
    int maxRents;
public:
    virtual double discount(int);
    virtual int getMRents();
    BronzeClient();

};
typedef shared_ptr<BronzeClient>BronzeClient_ptr;

#endif //PRO_WYPO_BRONZECLIENT_H

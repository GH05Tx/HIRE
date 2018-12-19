//
// Created by Janek on 06.12.2018.
//

#ifndef PRO_WYPO_BASECLIENT_H
#define PRO_WYPO_BASECLIENT_H
#include <memory>
#include "ClientType.h"
using namespace std;

class BaseClient: public ClientType{
private:
    int maxRents;
public:
    virtual double discount(int);
    virtual int getMRents();
    BaseClient();
};
typedef shared_ptr<BaseClient>BaseClient_ptr;

#endif //PRO_WYPO_BASECLIENT_H

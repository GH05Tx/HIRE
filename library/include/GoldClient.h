//
// Created by Janek on 06.12.2018.
//

#ifndef PRO_WYPO_GOLDCLIENT_H
#define PRO_WYPO_GOLDCLIENT_H
#include "ClientType.h"
#include <memory>
using namespace std;

class GoldClient: public ClientType {
private:
    int maxRents;
public:
    virtual double discount(int);
    virtual int getMRents();
    GoldClient();
};
typedef shared_ptr<GoldClient>GoldClient_ptr;
#endif //PRO_WYPO_GOLDCLIENT_H

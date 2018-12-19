//
// Created by Janek on 06.12.2018.
//

#ifndef PRO_WYPO_SILVERCLIENT_H
#define PRO_WYPO_SILVERCLIENT_H
#include <memory>
#include "ClientType.h"
using namespace std;

class SilverClient: public ClientType {
private:
    int maxRents;
public:
    virtual double discount(int);
    virtual int getMRents();
    SilverClient();
};
typedef shared_ptr<SilverClient>SilverClient_ptr;
#endif //PRO_WYPO_SILVERCLIENT_H

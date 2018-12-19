//
// Created by Janek on 06.12.2018.
//

#ifndef PRO_WYPO_CLIENTTYPE_H
#define PRO_WYPO_CLIENTTYPE_H
#include <memory>
using namespace std;

class ClientType {
public:
    virtual double discount(int)=0;
    virtual int getMRents()=0;
    virtual ~ClientType();
    ClientType();
};
typedef shared_ptr<ClientType>ClientType_ptr;
#endif //PRO_WYPO_CLIENTTYPE_H

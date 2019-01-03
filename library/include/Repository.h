//
// Created by pobi on 03.01.19.
//

#ifndef OOPPROJECT_REPOSITORY_H
#define OOPPROJECT_REPOSITORY_H


#include <list>
#include <string>

template <class  T>
class Repository{
protected:
    std::list<T> repoList;
public:
    virtual void create(T)=0;
    virtual void remove(T)=0;
    virtual void update()=0;
    virtual std::string getAll()=0; //zwraca report
    virtual T find(std::string)=0;
    ~Repository();
};






#endif //OOPPROJECT_REPOSITORY_H

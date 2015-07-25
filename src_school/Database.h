//
// Created by 越 on 2015/7/24.
//

#ifndef UMJI_VG101_PROJECT_FOR_DATABASE_H
#define UMJI_VG101_PROJECT_FOR_DATABASE_H
#include <list>
template <class T>
class DataEntries{
public:
    typedef bool (*Pred)(T*);
            DataEntries(std::list<T *>&);
    template <class TF>
            DataEntries(std::list<T *>&,TF T::*field,TF);
    DataEntries<T> Select(Pred);
    template <class TF>
        DataEntries<T> Select(TF T::*field,TF);
    std::list<T*>& getObjects();
private:
    std::list<T*> objects;
};
#endif //UMJI_VG101_PROJECT_FOR_DATABASE_H

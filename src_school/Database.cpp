//
// Created by 越 on 2015/7/24.
//

#include "Database.h"

template <class T>
DataEntries<T>::DataEntries(std::list<T *> &data) {
        objects = data;
        //Making a copy of the original data
}

template <class T> template <class TF>
DataEntries<T>::DataEntries(std::list<T *> &data,TF T::*field,TF value) {
    typename std::list<T*>::iterator it;
    for (it = data.begin(); it != data.end(); it++) {
        if( ( (*it)->*field) == value )objects.push_back(*it);
        //Making a copy of the original data
        //By thier property on the "field".
    }
}


template <class T>
DataEntries<T> DataEntries<T>::Select(DataEntries::Pred pred) {
    std::list <T*> result;
    typename std::list <T*>::iterator it;
    for(it=objects.begin();it!=objects.end();it++){
        if(pred(*it)==true)result.push_back(*it);
    }
    return DataEntries<T>(result);
}

template <class T> template <class TF>
DataEntries<T> DataEntries<T>::Select(TF T::*field, TF value) {
    std::list <T*> result;
    typename std::list <T*>::iterator it;
    for(it=objects.begin();it!=objects.end();it++){
        if( ((*it)->*field) == value)result.push_back(*it);
    }
    return DataEntries<T>(result);
}

template <class T>
std::list<T *> &DataEntries::getObjects() {
    return objects;
}

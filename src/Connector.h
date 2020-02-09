#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "CMD.h"

using namespace std;

class Connector : public CMD {
public:
virtual bool run();
Connector();
Connector(char* arr[], int size){
    for (int i =0; i < size; ++i){
        cons[i] = arr[i];
    }   
};

protected:
char* cons[64];
Connector* lhs;
Connector* rhs;
};

#endif

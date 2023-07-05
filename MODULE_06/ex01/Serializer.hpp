#ifndef SERIALIZER_HPP

#define SERIALIZER_HPP
#include <iostream>
#include <stdint.h>

struct Data {
    int value;
    Data(int val) : value(val) {}
};

class Serializer {
    public:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);
        ~Serializer();
        
        static uintptr_t serialize(Data* ptrData);
        static Data* deserialize(uintptr_t raw);
};

#endif
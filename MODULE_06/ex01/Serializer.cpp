#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& other) {
    *this = other;
}

Serializer& Serializer::operator=(const Serializer& other) { 
    (void)other; 
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptrData) {
    return reinterpret_cast<uintptr_t>(ptrData);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}

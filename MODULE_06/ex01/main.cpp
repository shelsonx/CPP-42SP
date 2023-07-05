#include "Serializer.hpp"

int main(void) {
    Data data(42);

    uintptr_t serialized = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "data value: " << data.value << std::endl;
    std::cout << "deserialized value: " << deserialized->value << std::endl;
    std::cout << "&data: " << &data << std::endl;
    std::cout << "deserialized: " << deserialized << std::endl;
    std::cout << "is equals? " 
        << (deserialized == &data ? "Yes" : "Not") << std::endl;
}

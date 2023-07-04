#include "DataConverter.hpp"

int DataConverter::count = 0;

void DataConverter::addConverter(Converter* converter) {
    if (count < MAX_CONVERTERS)
        converters[count++] = converter;
}

void DataConverter::notifyConverters() {
    for (int i = 0; i < count; ++i) {
        converters[i]->update();
    }
}

void DataConverter::notifyPseudoLiteral() {
    for (int i = 0; i < count; ++i) {
        converters[i]->pseudoLiteral();
    } 
}

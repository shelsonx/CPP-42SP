#ifndef DATACONVERTER_HPP

#define DATACONVERTER_HPP

#include "Converter.hpp"

class DataConverter {
    public:
        void addConverter(Converter* converter);
        void notifyConverters();

    private:
        static const int MAX_CONVERTERS = 4;
        Converter* converters[MAX_CONVERTERS];
        static int count;
};

#endif

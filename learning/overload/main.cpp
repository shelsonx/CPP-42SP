#include "sample.hpp"

int main()
{
    Sample sample;

    float f = 3.14;

    sample.bar(5);
    sample.bar('c');
    sample.bar(f);
    sample.bar(sample);
    return (0);
}

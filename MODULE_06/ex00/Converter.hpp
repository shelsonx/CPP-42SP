#ifndef CONVERTER_HPP

#define CONVERTER_HPP

#include <iostream>

class Converter {
    public:
        virtual void update() = 0;
};

class CharConverter : public Converter {
    public:
        void update();
        char getStrToChar() const;
        void setStrToChar(char c);
    
    private:
        char _strToChar;
};

class IntConverter : public Converter {
    public:
        void update();
        int getStrToInt() const;
        void setStrToInt(int i);
    
    private:
        int _strToInt;
};

class FloatConverter : public Converter {
    public:
        void update();
        float getStrToFloat() const;
        void setStrToFloat(float f);
    
    private:
        float _strToFloat;
};

class DoubleConverter : public Converter {
    public:
        void update();
        double getStrToDouble() const;
        void setStrToDouble(double d);
    
    private:
        double _strToDouble;
};

#endif

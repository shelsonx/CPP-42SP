#ifndef CONVERTER_HPP

#define CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <climits>
#include <cfloat>

class Converter {
    public:
        Converter();
        virtual void update() = 0;
        virtual void checkConversion(const std::string& str) = 0;
    
    protected:
        bool isConvertible;
};

class CharConverter : public Converter {
    public:
        void update();
        void checkConversion(const std::string& str);
        bool isDisplayableChar(char c);
        char getStrToChar() const;
        void setStrToChar(char c);
    
    private:
        char _strToChar;
};

class IntConverter : public Converter {
    public:
        void update();
        void checkConversion(const std::string& str);
        int getStrToInt() const;
        void setStrToInt(int i);
    
    private:
        int _strToInt;
};

class FloatConverter : public Converter {
    public:
        void update();
        void checkConversion(const std::string& str);
        float getStrToFloat() const;
        void setStrToFloat(float f);
    
    private:
        float _strToFloat;
};

class DoubleConverter : public Converter {
    public:
        void update();
        void checkConversion(const std::string& str);
        double getStrToDouble() const;
        void setStrToDouble(double d);
    
    private:
        double _strToDouble;
};

#endif

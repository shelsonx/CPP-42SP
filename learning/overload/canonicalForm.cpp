#include <iostream>

class FixedPoint {
    public:
        //Default constructor
        FixedPoint() : _integerPart(0), _fractionalPart(0), _scalePart(1) {}
        //Constructor
        FixedPoint(int integer, int fractional, int scale)
            : _integerPart(integer), _fractionalPart(fractional), _scalePart(scale){}
        //Copy constructor
        FixedPoint(const FixedPoint& other)
            : _integerPart(other._integerPart), 
            _fractionalPart(other._fractionalPart), 
            _scalePart(other._scalePart){}
        //Copy constructor assignment
        FixedPoint& operator=(const FixedPoint& other){
            if (this != &other)
            {
                _integerPart = other._integerPart;
                _fractionalPart = other._fractionalPart;
                _scalePart = other._scalePart;
            }
            return *this;
        }

        ~FixedPoint() {}
        
        int getIntegerPart() const {
            return _integerPart;
        }

        int getFractionalPart() const {
            return _fractionalPart;
        }

        int getScaleFactor() const {
            return _scalePart;
        }

        void setIntegerPart(int integer) {
            _integerPart = integer;
        }

        void setFractionalPart(int fractional) {
            _fractionalPart = fractional;
        }

        void setScaleFactor(int scale) {
            _scalePart = scale;
        }

        double toDouble() const {
            return _integerPart + static_cast<double>(_fractionalPart) / _scalePart;
        }

    private:
        int _integerPart;
        int _fractionalPart;
        int _scalePart;
};


int main() {
    FixedPoint fixedNum(12, 345, 1000);
    std::cout << "Integer Part: " << fixedNum.getIntegerPart() << std::endl;
    std::cout << "Fractional Part: " << fixedNum.getFractionalPart() << std::endl;
    std::cout << "Scale Factor: " << fixedNum.getScaleFactor() << std::endl;
    std::cout << "Value as Double: " << fixedNum.toDouble() << std::endl;

    FixedPoint copyNum(fixedNum);
    std::cout << "Copied Integer Part: " << copyNum.getIntegerPart() << std::endl;
    std::cout << "Copied Fractional Part: " << copyNum.getFractionalPart() << std::endl;
    std::cout << "Copied Scale Factor: " << copyNum.getScaleFactor() << std::endl;

    FixedPoint assignedNum;
    assignedNum = fixedNum;
    std::cout << "Assigned Integer Part: " << assignedNum.getIntegerPart() << std::endl;
    std::cout << "Assigned Fractional Part: " << assignedNum.getFractionalPart() << std::endl;
    std::cout << "Assigned Scale Factor: " << assignedNum.getScaleFactor() << std::endl;

    return 0;
}
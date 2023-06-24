#ifndef CHARACTER_HPP

#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const & getName() const = 0;
        void equip(AMateria* m) = 0;
        void unequip(int idx) = 0;
        void use(int idx, ICharacter& target) = 0;
    
    private:
        static const int SLOTS = 4;
        AMateria* slots[SLOTS];
        std::string _name;
};

#endif
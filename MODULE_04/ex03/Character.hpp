#ifndef CHARACTER_HPP

#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character(const std::string& name);
        Character();
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
    
    private:
        static const int MAX_SLOTS = 4;
        AMateria* _inventory[MAX_SLOTS];
        std::string _name;

        void initInventory();
        void emptyInventory();
};

#endif
#include <iomanip>
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main() {
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {   
        IMateriaSource *ms = new MateriaSource();
        ms->learnMateria(new Ice());
        ms->learnMateria(new Ice());
        ms->learnMateria(new Cure());
        ms->learnMateria(new Cure());

        Ice *ice = new Ice();
        ms->learnMateria(ice);

        AMateria* tmp =  ms->createMateria("ice");
        std::cout << tmp->getType() <<  std::endl;

        AMateria* tmp2 =  ms->createMateria("cure");
        std::cout << tmp2->getType() <<  std::endl;
        
        AMateria* tmp3 =  ms->createMateria("unknown");
        std::cout << tmp3 <<  std::endl;

        delete tmp;
        delete tmp2;
    
        delete ice;
        delete ms;
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    {   
        ICharacter *ch = new Character();
        ch->equip(new Ice());
        ch->equip(new Ice());
        ch->equip(new Cure());
        ch->equip(new Cure());
        Ice *ice = new Ice();
        ch->equip(ice);
 
        delete ice;
        delete ch;
    }
    std::cout << std::setw(40) << std::setfill('*') << "" << std::endl;
    return 0;
}

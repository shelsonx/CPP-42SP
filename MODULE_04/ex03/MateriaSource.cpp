#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    std::cout << "MateriaSource: Default constructor called!" << std::endl;
    this->initMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "Character: Copy constructor called!" << std::endl;
    *this = other;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource: Copy assignment operator called!" << std::endl;
    if (this != &other) {
        this->emptyMaterias();
        for (int i = 0; i < MAX_MATERIAS; i++) {
            this->_materias[i] = other._materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource () {
    std::cout << "MateriaSource: Default destructor called!" << std::endl;
    this->emptyMaterias();
}

void MateriaSource::learnMateria(AMateria* materia) {
    for (int i = 0; i < MAX_MATERIAS; i++) {
        if (this->_materias[i] == NULL) {
            this->_materias[i] = materia;
            std::cout << "Successfully added!" << std::endl;
            return ;
        }
    }
    std::cout << "Full materias!" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < MAX_MATERIAS; i++) {
        if (this->_materias[i]->getType() == type) {
            return this->_materias[i]->clone();
        }
    }
    return 0;
}

void MateriaSource::initMaterias() {
    for (int i = 0; i < MAX_MATERIAS; i++)
        this->_materias[i] = NULL;
}

void MateriaSource::emptyMaterias() {
    for (int i = 0; i < MAX_MATERIAS; i++) {
        delete this->_materias[i];
        this->_materias[i] = NULL;
    }
}

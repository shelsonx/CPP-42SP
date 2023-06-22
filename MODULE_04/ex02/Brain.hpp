#ifndef BRAIN_HPP

#define BRAIN_HPP

#include <iostream>

class Brain {
    public:
        Brain();
        Brain(const Brain& other);
        Brain& operator=(const Brain& other);
        ~Brain();

        std::string* getIdeas();
        std::string getIdea(const int id) const;
        void setIdea(const int id, const std::string idea);
    
    private:
        std::string _ideas[100];
};

#endif
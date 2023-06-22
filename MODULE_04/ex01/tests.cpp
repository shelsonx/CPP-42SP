#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string.h>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

TEST_CASE("test constructors") {
    Brain b1;

    for (int i = 0; i < 100; i++) 
        b1.setIdea(i, "idea_" + std::to_string(i));
    
    CHECK_EQ("idea_0", b1.getIdea(0));
    CHECK_EQ("idea_99", b1.getIdea(99));

    Brain b2(b1);
    CHECK_EQ("idea_0", b2.getIdea(0));
    CHECK_EQ("idea_99", b2.getIdea(99));
    CHECK_EQ("idea_42", b2.getIdea(42));

    Brain b3;
    b3 = b2;
    CHECK_EQ("idea_0", b3.getIdea(0));
    CHECK_EQ("idea_99", b3.getIdea(99));
    CHECK_EQ("idea_42", b3.getIdea(42));
    CHECK_EQ("idea_33", b3.getIdea(33));
}

TEST_CASE("test gets and sets") {
    Brain b1;
    std::string* ideas;

    b1.setIdea(0, "banana");
    b1.setIdea(1, "uva");
    
    CHECK_EQ("banana", b1.getIdea(0));
    CHECK_EQ("uva", b1.getIdea(1));
    
    ideas = b1.getIdeas();
    CHECK_EQ(ideas[0], b1.getIdea(0));
    CHECK_EQ(ideas[1], b1.getIdea(1));

    CHECK_EQ("", b1.getIdea(2));
    delete[] ideas;
}

TEST_CASE ("test constructs and brains") {
    Cat c1;
    Brain *brainC1 = c1.getBrain();
    brainC1->setIdea(0, "idea_0");

    Cat c2(c1);
    Brain *brainC2 = c2.getBrain();
    CHECK_EQ("idea_0", c2.getBrain()->getIdea(0));

    brainC2->setIdea(0, "idea_change");
    CHECK_EQ("idea_change", c2.getBrain()->getIdea(0));
    CHECK_EQ("idea_0", c1.getBrain()->getIdea(0));

    Cat c3 = c2;
    Brain *brainC3 = c3.getBrain();
    CHECK_EQ("idea_change", c3.getBrain()->getIdea(0));
    brainC3->setIdea(0, "idea_change_change");
    CHECK_EQ("idea_change_change", c3.getBrain()->getIdea(0));
    CHECK_EQ("idea_change", c2.getBrain()->getIdea(0));
}

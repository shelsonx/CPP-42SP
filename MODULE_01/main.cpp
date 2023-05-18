#include "PhoneBook.hpp"

int main()
{
   PhoneBook pb;
   Contact c1("Davi", "Alves", "principe", "91992536693", "shelldorydavi");
   pb.add(c1);
   pb.contacts[0].display();
}

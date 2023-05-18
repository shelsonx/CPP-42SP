#include "PhoneBook.hpp"

int main()
{
   PhoneBook pb;
   pb.add(Contact("Davi", "Alves", "principe", "91992536693", "shelldorydavi"));
   pb.add(Contact("Doriane", "Alves", "dory", "91992536693", "dorishell"));
   pb.add(Contact("Shelson", "Alves", "shell", "91992536693", "shelldd"));
   pb.display_contacts();
   pb.search(10);
}

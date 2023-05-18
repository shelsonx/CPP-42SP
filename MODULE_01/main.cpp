#include "PhoneBook.hpp"

Contact create_new_contact()
{
   std::string first_name, last_name, nickname, phone_number, darkest_secret;
   std::cout << "First name: ";
   std::cin >> first_name;
   std::cout << "Last name: ";
   std::cin >> last_name;
   std::cout << "Nickname: ";
   std::cin >> nickname;
   std::cout << "Phone number: ";
   std::cin >> phone_number;
   std::cout << "Darkest secret: ";
   std::cin >> darkest_secret;
   Contact contact(first_name, last_name, nickname, phone_number, darkest_secret);
   return contact;
}

void dispatcher(PhoneBook *pb, int option)
{
   switch (option)
   {
      case 1:
         pb->add(create_new_contact());
         break;
      case 2:
         std::cout << "Missing implement!" << std::endl;
         break;
      case 3:
         std::cout << "Missing implement!" << std::endl;
         break;
      default:
         break;
   }
   if (option != 4)
      pb->display_contacts();
}

void input(PhoneBook *pb)
{
   char input[1];
   int option = -1;
   while (option != 4)
   {
      std::cout << "Select option: " << std::endl;
      std::cout << "1- Add new contact" << std::endl;
      std::cout << "2- Search an contact" << std::endl;
      std::cout << "3- Display all contacts" << std::endl;
      std::cout << "4- Exit" << std::endl;
      std::cout << "> ";
      std::cin >> input;
      option = atoi(input);
      dispatcher(pb, option);
   }
}

int main()
{
   PhoneBook pb;
   pb.add(Contact("Davi", "Alves", "principe", "91992536693", "shelldorydavi"));
   pb.add(Contact("Doriane", "Alves", "dory", "91992536693", "dorishell"));
   pb.add(Contact("Shelson", "Alves", "shell", "91992536693", "shelldd"));
   pb.search(10);
   input(&pb);
}

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

void  search(PhoneBook *pb)
{
   int input;

   pb->display_contacts();
   std::cout << "Insert um id to search: ";
   std::cin >> input;
   std::cout << std::endl << "Result search: " << std::endl;
   pb->search(input);
   std::cout << std::endl;
}

void dispatcher(PhoneBook *pb, int option)
{
   switch (option)
   {
      case 1:
         pb->add(create_new_contact());
         break;
      case 2:
         search(pb);
         break;
      case 3:
         std::cout << "Exited Successfully!" << std::endl;
         break;
      default:
         break;
   }      
}

void system(PhoneBook *pb)
{
   char input[1];
   int option = -1;
   while (option != 3)
   {
      std::cout << "Select option: " << std::endl;
      std::cout << "1- Add new contact" << std::endl;
      std::cout << "2- Search an contact" << std::endl;
      std::cout << "3- Exit" << std::endl;
      std::cout << "> ";
      std::cin >> input;
      option = atoi(input);
      dispatcher(pb, option);
   }
}

int main()
{
   PhoneBook pb;
   system(&pb);
}

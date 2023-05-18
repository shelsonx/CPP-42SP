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

void dispatcher(PhoneBook *pb, std::string input)
{
   if (input.compare("1") == 0)
      pb->add(create_new_contact());
   else if (input.compare("2") == 0)
      std::cout << "Missing implement!" << std::endl;
   else if (input.compare("3") == 0)
      std::cout << "Missing implement!" << std::endl;
   if (input.compare("4") != 0)
      pb->display_contacts();
}

void input(PhoneBook *pb)
{
   std::string sentry;
   sentry = "";
   while (sentry.compare("4"))
   {
      std::cout << "Select option: " << std::endl;
      std::cout << "1- Add new contact" << std::endl;
      std::cout << "2- Search an contact" << std::endl;
      std::cout << "3- Display all contacts" << std::endl;
      std::cout << "4- Exit" << std::endl;
      std::cout << "> ";
      std::cin >> sentry;
      dispatcher(pb, sentry);
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


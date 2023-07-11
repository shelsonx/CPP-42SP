#include <iostream>
#include <set>
#include <map>

int main(void) {
    std::set<int> mySet;
    mySet.insert(3);
    mySet.insert(5);
    mySet.insert(7);

    for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it){
        std::cout << *it << std::endl;
    }

    if (mySet.find(5) != mySet.end())
        std::cout << "5 in my set" << std::endl ;

    mySet.insert(5);//Não pode adicionar valores duplicados. Será ignorado.
    mySet.insert(9);
    std::cout << mySet.size() << std::endl << std::endl;


    std::map<std::string, int> myMap;

    myMap["Davi"] = 10;
    myMap["Dory"] = 9;
    myMap["shell"] = 8;

    std::map<std::string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;

    if (myMap.find("Davi") != myMap.end())
        std::cout << "Davi está in map" << std::endl;
}

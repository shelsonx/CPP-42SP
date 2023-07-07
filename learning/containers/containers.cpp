#include <vector>
#include <list>
#include <map>
#include <stack>
#include <iostream>

int main () {
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);
    numbers.push_back(50);

    numbers.pop_back();

    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << std::endl;
    
    std::list<std::string> names;
    names.push_back("Davi");
    names.push_back("Doriane");
    names.push_back("Shelson");
    names.push_front("Jesus");

    for (std::list<std::string>::iterator it = names.begin(); it != names.end(); ++it)
        std::cout << *it << std::endl;
    
    std::map<std::string, int> scores;
    scores["Davi"] = 10;
    scores["Dory"] = 9;
    scores["shell"] = 8;

    for (std::map<std::string, int>::iterator it = scores.begin(); it != scores.end(); ++it)
        std::cout << it->first << ": " << it->second << std::endl;
    

    {
        std::stack<int> numbers;
        numbers.push(10);
        numbers.push(20);
        numbers.push(30);

        std::cout << "Top: " << numbers.top() << std::endl;
        std::cout << "Size: " << numbers.size() << std::endl;

        while (!numbers.empty()) {
            std::cout << "Top: " << numbers.top() << std::endl;
            numbers.pop();
        }

    }

}

//Example by manual
//std::begin / std::end example
#include <iostream>
#include <vector> //std::vector, std::begin, std::end

int main()
{
    int foo[] = {10, 20, 30, 40, 50};
    std::vector<int> bar;

    //iterate foo: inserting into bar
    for (auto it = std::begin(foo); it != std::end(foo); ++it)
        bar.push_back(*it);
    
    //iterator bar: print contents:
    std::cout << "bar contains:";
    for (auto it = std::begin(bar); it != std::end(bar); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
    return 0;
}

#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> g1;

    for (int i = 0;  i <= 5; i++)
        g1.push_back(i);
    
    cout << "Size:" << g1.size() << endl;
    cout << "Capacity: " << g1.capacity() << endl;
    cout << "Max size: " << g1.max_size() << endl;

    g1.resize(4);
    cout << "Size:" << g1.size() << endl;

    if (g1.empty() == false)
        cout << "\nVector is not empty";
    else
        cout << "\nVector is empty";

    g1.shrink_to_fit();

    for (auto it = g1.begin(); it != g1.end(); it++)
        cout << *it << endl;
    
    //iterator
    vector<int> v1 = {10, 20, 30, 40, 50};

    vector<int>::iterator ptr;

    for (ptr = v1.begin(); ptr < v1.end(); ptr++)
        cout << *ptr << endl;
}

/*
    compile:
        c++ -std=c++98
*/
#include <iostream>

using namespace std;

int main()
{
    char name[10];
    char c;
    cout << "What's first your name? ";
    cin >> name;
    cout << "Hello World, ";
    for (int i=0; i < strlen(name); i++)
    {
        c = toupper(name[i]);
        cout << (char) toupper(name[i]);
    }
    cout << "!" << endl;
}

#include <iostream>
#include <ctime>
#include <iomanip>
#include <stdio.h>


using namespace std;

int main()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << "Year: " << 1900 + ltm->tm_year << endl;
    cout << "Month: " << setw(2) << setfill('0') << 1 + ltm->tm_mon << endl;
    cout << "Day: " << setw(2) << setfill('0') << ltm->tm_mday << endl;
    cout << "Hour: " << setw(2) << setfill('0') << 1 + ltm->tm_hour << endl;
    cout << "Minute: " << setw(2) << setfill('0') << 1 + ltm->tm_min << endl;
    cout << "Secons: " << setw(2) << setfill('0') << 1 + ltm->tm_sec << endl;

}
#include "ReplaceStr.hpp"

void ReplaceStr::replace(std::string& str, 
        const std::string s1,
        const std::string s2)
{
    size_t pos = 0;

    while (true)
    {
        pos = str.find(s1, pos);
        if (pos == std::string::npos)
            break;
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
}

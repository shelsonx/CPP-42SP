#include <iostream>
#include <fstream>

int main()
{
    //ifstram: input file strem
    std::ifstream ifs("numbers");
    unsigned int dst;
    unsigned int dst2;

    ifs >> dst >> dst2;
    std::cout << dst << " " << dst2 << std::endl;
    ifs.close();

    //ofstram: output file stream
    std::ofstream ofs("test.out");
    ofs << "i like ponies a whole damn lot" << std::endl;
    ofs.close();
    return (0);
}

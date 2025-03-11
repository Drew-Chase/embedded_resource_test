#include <iostream>
#include <battery/embed.hpp>

int main()
{
    std::cout << "Sample Text: " << b::embed<"res/sample.txt">() << std::endl;
    return 0;
}

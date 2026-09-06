#include "game.hpp"

#include <iostream>


int main()
{
    std::cout << "before" << std::endl;

    Game game{};
    game.run();


    std::cout << "after" << std::endl;
    return 0;
}
#ifndef GAME_HPP
#define GAME_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>
#include <GLFW/glfw3.h> // Include GLFW for window management

class Game
{
public:
    Game() {}
    Game(const Game &game) { (void)game; }
    Game &operator=(const Game &game) { (void)game; return *this; }
    ~Game() {}

    void run();
};

#endif

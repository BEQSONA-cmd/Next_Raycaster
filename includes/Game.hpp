#ifndef GAME_HPP
#define GAME_HPP
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"

#include <iostream>
#include <GLFW/glfw3.h>
#include "Keys.hpp"

#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

typedef struct s_Point
{
    double x;
    double y;
} Point;

class Game
{
    private:
        GLFWwindow *window;
        std::string Name;
    public:
        Game(std::string name) { this->Name = name; }
        ~Game() { std::cout << YELLOW << "Game Closed." << RESET << std::endl; }

        void init_opengl();

        void run();
};

#endif
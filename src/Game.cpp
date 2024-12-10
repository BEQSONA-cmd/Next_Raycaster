#include "../includes/Game.hpp"

void Game::init_opengl()
{

    if (!glfwInit())
    {
        std::cerr << RED << "Failed to initialize GLFW" << RESET << std::endl;
        return;
    }

    this->window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Game", NULL, NULL);

    if (!this->window)
    {
        std::cerr << RED << "Failed to create GLFW window" << RESET << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(this->window);

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
}


void draw_triangle(Point triangle[3], float color[3])
{
    glBegin(GL_TRIANGLES);
    glColor3f(color[0], color[1], color[2]);
    glVertex2f(triangle[0].x, triangle[0].y);
    glVertex2f(triangle[1].x, triangle[1].y);
    glVertex2f(triangle[2].x, triangle[2].y);
    glEnd();
}

void Game::run()
{
    init_opengl();

    float color[3] = {1.0f, 1.0f, 0.0f}; 

    Point triangle[3] = {
        {0.0, 0.5},
        {0.5, -0.5},
        {-0.5, -0.5}
    };

    int key = 0;

    while (!Keys::Close(this->window))
    {
        if((key = Keys::key_pressed(this->window)))
            Keys::print_key(key);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_triangle(triangle, color);

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }

    glfwDestroyWindow(this->window);
    glfwTerminate();
}

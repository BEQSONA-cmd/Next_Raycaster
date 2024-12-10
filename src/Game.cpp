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

void draw_square(Point coordinates, Point size, float color[3])
{
    glBegin(GL_QUADS);
    glColor3f(color[0], color[1], color[2]);
    glVertex2f(coordinates.x - size.x, coordinates.y - size.y);
    glVertex2f(coordinates.x + size.x, coordinates.y - size.y);
    glVertex2f(coordinates.x + size.x, coordinates.y + size.y);
    glVertex2f(coordinates.x - size.x, coordinates.y + size.y);
    glEnd();
}


void Game::run()
{
    init_opengl();

    float color[3] = {1.0f, 1.0f, 0.0f}; 

    Point coordinates;
    coordinates.x = 0.0f;
    coordinates.y = 0.0f;

    Point size;
    size.x = 0.01f;
    size.y = 0.01f;

    int key = 0;

    while (!Keys::Close(this->window))
    {
        if((key = Keys::key_pressed(this->window)))
        {
            if(key == W)
                coordinates.y += 0.01f;
            else if(key == S)
                coordinates.y -= 0.01f;
            else if(key == A)
                coordinates.x -= 0.01f;
            else if(key == D)
                coordinates.x += 0.01f;
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_square(coordinates, size, color);

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}

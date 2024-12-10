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

    // Set orthographic projection
    glOrtho(-1, 1, -1, 1, -1, 1);

    // Initialize GLUT
    int argc = 0;
    char *argv[] = {nullptr};
    glutInit(&argc, argv);

    // disable vsync
    // glfwSwapInterval(0);
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

void draw_text(const std::string& text, Point position,float color[3])
{
    glColor3f(color[0], color[1], color[2]);
    glRasterPos2f(position.x, position.y);
    
    int i = 0;
    while (text[i])
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
        i++;
    }
}

void draw_fps(float fps)
{
    std::ostringstream fps_text;

    fps_text << std::fixed << std::setprecision(1) << "FPS: " << fps;

    float text_color[3] = {0.0f, 1.0f, 1.0f};

    Point text_position;
    text_position.x = 0.8f;
    text_position.y = 0.9f;

    draw_text(fps_text.str(), text_position, text_color);
}

double get_fps(double last_time)
{
    static int frame_count;
    double current_time = glfwGetTime();
    double fps = frame_count / (current_time - last_time);
    frame_count++;
    return fps;
}

void Game::run()
{
    init_opengl();

    float color[3] = {1.0f, 1.0f, 0.0f};

    Point coordinates = {0.0f, 0.0f};
    Point size = {0.01f, 0.01f};

    int key = 0;

    double last_time = glfwGetTime();

    while (!Keys::Close(this->window))
    {
        if ((key = Keys::key_pressed(this->window)))
        {
            if (key == W)
                coordinates.y += 0.01f;
            else if (key == S)
                coordinates.y -= 0.01f;
            else if (key == A)
                coordinates.x -= 0.01f;
            else if (key == D)
                coordinates.x += 0.01f;
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_square(coordinates, size, color);
        draw_fps(get_fps(last_time));

        glfwSwapBuffers(this->window);
        glfwPollEvents();
    }
}

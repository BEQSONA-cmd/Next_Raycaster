#include "Game.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    (void)window;
    glViewport(0, 0, width, height); // Adjust the viewport when the window is resized
}

void Game::run()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cerr << RED << "Failed to initialize GLFW" << RESET << std::endl;
        return;
    }

    // Create a window
    GLFWwindow *window = glfwCreateWindow(1080, 720, "OpenGL 10x10 Yellow Square", nullptr, nullptr);
    if (!window)
    {
        std::cerr << RED << "Failed to create GLFW window" << RESET << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window); // Make the window's context current
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Set up OpenGL viewport
    glViewport(0, 0, 1080, 720);

    // Main game loop
    while (!glfwWindowShouldClose(window))
    {
        // Clear the screen with black color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Draw a 10x10 yellow square at the center
        glColor3f(1.0f, 1.0f, 0.0f); // Set the color to yellow
        glBegin(GL_QUADS);           // Start drawing a square
        glVertex2f(-0.01f, -0.01f);  // Bottom-left corner
        glVertex2f(0.01f, -0.01f);   // Bottom-right corner
        glVertex2f(0.01f, 0.01f);    // Top-right corner
        glVertex2f(-0.01f, 0.01f);   // Top-left corner
        glEnd();

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up and terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
}

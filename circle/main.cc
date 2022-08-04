#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#define WINDOW_NAME "Circle Approximation OpenGL"

int main()
{
    int steps{};
    printf("[message] number of shades : ???");
    std::cin >> steps;
    float angle = M_PI * 2.0 / steps; // Angle for Approximation

    GLFWwindow *window{nullptr};
    if (glfwInit() == false)
    {
        printf("[error] glfwInit Error!\n");
        return -1;
    };
    window = glfwCreateWindow(700, 700, WINDOW_NAME, NULL, NULL); // Creating glfw Window
    if (!window)
    {
        printf("[error] glfwCreateWindow error!\n");
        glfwTerminate(); // terminate if window creation failed don't just return after glfwinit()
        return -1;
    };

    glfwMakeContextCurrent(window); // I don't know about this what thw heck is that

    float xPos{}, yPos{};                  // x,y cordinate for circle approximation
    const float radius{1.0f};              // raduis of circle
    while (!glfwWindowShouldClose(window)) // making event poll
    {
        glClearColor(1.0, 1.0, 1.0, 1.0); // setting up window background color
        glClear(GL_COLOR_BUFFER_BIT);     // idk what this thing do

        float prevX = xPos, prevY = yPos - radius;

        for (short i = 0; i <= steps; ++i)
        {
            float newX{(radius * sin(angle * i))};
            float newY{(-radius * cos(angle * i))};
            glBegin(GL_TRIANGLES);
            glColor3f(0, 0.1, 0);
            glVertex3f(0.0f, 0.0f, 0.0f);   // strting point
            glVertex3f(prevX, prevY, 0.0f); // prev point
            glVertex3f(newX, newY, 0.0f);   // new point
            glEnd();                        // end()
            prevX = newX;
            prevY = newY;
        };

        glfwSwapBuffers(window); // buffer swpping
        glfwPollEvents();        // hadle poll events
    };

    return 0;
};

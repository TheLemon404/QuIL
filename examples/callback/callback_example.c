#include <stdio.h>
#include <GLFW/glfw3.h>
#include "quil.h"

void keyCallback() {
    printf("key\n");
}

void mouseCallback() {
    printf("mouse\n");
}

int main() {
    printf("general_example");

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    quilCreateWindowContext(window);

    quilAddKeyCallback(GLFW_KEY_R, QUIL_JUST_PRESSED, &keyCallback);
    quilAddMouseButtonCallback(GLFW_MOUSE_BUTTON_1, QUIL_JUST_RELEASED, &mouseCallback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        //this function must be called each frame to check for callbacks
        quilPollCallbacks();

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

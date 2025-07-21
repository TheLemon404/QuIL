#include <stdio.h>
#include <GLFW/glfw3.h>
#include "quil.h"

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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        if (quilIsMouseButtonJustPressed(GLFW_MOUSE_BUTTON_1)) {
            printf("mouse button 1 pressed\n");
        }

        enum QuilInputState spaceKeyState = quilGetKeyState(GLFW_KEY_SPACE);
        printf("%s\n", quilKeyToString(spaceKeyState));

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

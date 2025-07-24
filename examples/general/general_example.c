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

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        if (quilIsMouseButtonJustPressed(GLFW_MOUSE_BUTTON_1)) {
            printf("mouse button 1 just pressed\n");
        }

        if (quilIsMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
            printf("mouse button 1 pressed\n");
        }

        if (quilIsKeyJustReleased(GLFW_KEY_W)) {
            printf("key w just released\n");
        }

        if (quilIsKeyReleased(GLFW_KEY_W)) {
            printf("key w released\n");
        }

        // this code will print the current key state (PRESSED, JUST_PRESSED, RELEASED, JUST_RELEASED) to the console every frame
        QuilInputState spaceKeyState = quilGetKeyState(GLFW_KEY_SPACE);
        printf("%s\n", quilKeyToString(spaceKeyState));

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

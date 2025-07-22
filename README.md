# QuIL
### Quick Input Layer

Oftentimes when writing a project containing keyboard and mouse input, I find myself rewriting the same code over and over again between projects. QuIL is meant to be an extremely small code layer that sits on top of GLFW and impliments the basic input logic needed to get a prototype project off the ground. Using QuIL, you can have out of the box input functionality with zero setup, making early project development a tiny bit easier.

## Features:
* PRESSED, JUST_PRESSED, RELEASED, JUST_RELEASED input states for keyboard and mouse
* input state checking functionality through reading the current state of a key, or simply checking isKeyDown(key)
* bind functions with no parameters as callbacks to key and mouse button states

## Limitations:
* you can only bind 1 callback per key. You are free to have multiple keys bound the the same callback, but each key can only be bound to 1 callback.

## Basic Input State Usage
```c++
int main() {
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);

    quilCreateWindowContext(window);
    
    while (!glfwWindowShouldClose(window))
    {
        if (quilIsMouseButtonJustPressed(GLFW_MOUSE_BUTTON_1)) {
            // custom logic
        }
        
        if (quilIsMouseButtonPressed(GLFW_MOUSE_BUTTON_1)) {
            // custom logic
        }
        
        if (quilIsKeyJustReleased(GLFW_KEY_W)) {
            // custom logic
        }
        
        if (quilIsKeyReleased(GLFW_KEY_W)) {
            // custom logic
        }
        
        // this code will print the current key state (PRESSED, JUST_PRESSED, RELEASED, JUST_RELEASED) to the console every frame
        enum QuilInputState spaceKeyState = quilGetKeyState(GLFW_KEY_SPACE);
        printf("%s\n", quilKeyToString(spaceKeyState));
    }
}
```
## Callback Usage
```c++
void keyCallback() {
    printf("key\n");
}

void mouseCallback() {
    printf("mouse\n");
}

int main() {
    GLFWwindow* window;
    glfwInit();
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    glfwMakeContextCurrent(window);

    quilCreateWindowContext(window);
    quilAddKeyCallback(GLFW_KEY_R, QUIL_JUST_PRESSED, &keyCallback);
    quilAddMouseButtonCallback(GLFW_MOUSE_BUTTON_1, QUIL_JUST_RELEASED, &mouseCallback);
    
    while (!glfwWindowShouldClose(window))
    {
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        //this function must be called each frame to check for callbacks
        quilPollCallbacks();

        /* Poll for and process events */
        glfwPollEvents();
    }
}
```
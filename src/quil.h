#pragma once

#ifndef QUIL_H
#define QUIL_H

#include <GLFW//glfw3.h>

#endif //QUIL_H

//types
enum QuilInputState {
    RELEASED,
    JUST_RELEASED,
    PRESSED,
    JUST_PRESSED,
};

struct QuilCallbackCondition {
    enum QuilInputState inputState;
    void (*callback)();
};

struct QuilGlobalState {
    GLFWwindow* currentGLFWWindow;
};

//managing state and code lifetime
void quilCreateWindowContext(GLFWwindow* currentGLFWWindow);

//input state
enum QuilInputState quilGetKeyState(int key);
enum QuilInputState quilGetMouseButtonState(int button);

const char* quilKeyToString(enum QuilInputState key);

//basic input functionality
int quilIsKeyReleased(int key);
int quilIsKeyJustReleased(int key);
int quilIsKeyPressed(int key);
int quilIsKeyJustPressed(int key);

int quilIsMouseButtonReleased(int button);
int quilIsMouseButtonJustReleased(int button);
int quilIsMouseButtonPressed(int button);
int quilIsMouseButtonJustPressed(int button);

//callbacks
int quilAddKeyCallback(int key, enum QuilInputState inputState, void (*callback)());
int quilAddMouseButtonCallback(int mouseButton, enum QuilInputState inputState, void (*callback)());
void quilPollCallbacks();

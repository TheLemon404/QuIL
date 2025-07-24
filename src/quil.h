#pragma once

#ifndef QUIL_H
#define QUIL_H

#include <GLFW//glfw3.h>

#endif //QUIL_H

#ifdef __cplusplus
extern "C" {
#endif

//types
typedef enum QuilInputState {
    QUIL_RELEASED,
    QUIL_JUST_RELEASED,
    QUIL_PRESSED,
    QUIL_JUST_PRESSED,
} QuilInputState;

typedef struct QuilCallback {
    QuilInputState inputState;
    void (*callback)();
} QuilCallback;

typedef struct QuilGlobalState {
    GLFWwindow* currentGLFWWindow;
} QuilGlobalState;

//managing state and code lifetime
void quilCreateWindowContext(GLFWwindow* currentGLFWWindow);

//input state
QuilInputState quilGetKeyState(int key);
QuilInputState quilGetMouseButtonState(int button);

const char* quilKeyToString(QuilInputState key);

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
void quilAddKeyCallback(int key, QuilInputState inputState, void (*callback)());
void quilAddMouseButtonCallback(int mouseButton, QuilInputState inputState, void (*callback)());
void quilPollCallbacks();

#ifdef __cplusplus
}
#endif
//
// Created by Osprey on 7/21/2025.
//

#pragma once

#ifndef QUIL_H
#define QUIL_H

#include <GLFW//glfw3.h>

#endif //QUIL_H

//types
enum QuilKeyState {
    RELEASED,
    JUST_RELEASED,
    PRESSED,
    JUST_PRESSED,
};

struct QuilState {
    GLFWwindow* currentGLFWWindow;
};

//managing state and code lifetime
void quilCreateWindowContext(GLFWwindow* currentGLFWWindow);
void quilInitializeInputStates();
void quilPollGLFWInput();
void quilTerminateGLFW();

//usable functions
enum QuilKeyState quilGetKeyState(int key);
const char* quilKeyToString(enum QuilKeyState key);

int quilIsKeyReleased(int key);
int quilIsKeyJustReleased(int key);
int quilIsKeyPressed(int key);
int quilIsKeyJustPressed(int key);
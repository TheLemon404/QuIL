//
// Created by Osprey on 7/21/2025.
//

#include "quil.h"

struct QuilState globalState = {};
int GLFWKeys[105];

#include <stdio.h>
#include <stdlib.h>

void quilCreateWindowContext(GLFWwindow* currentGLFWWindow) {
	globalState.currentGLFWWindow = currentGLFWWindow;
}

void quilInitializeInputStates() {
	// This could include setting up key states, mouse states, etc.
	// Initialize input states
}

void quilPollGLFWInput() {
	// Poll for GLFW events
	glfwPollEvents();
}

void quilTerminateGLFW() {
	// Terminate GLFW
	glfwTerminate();
}

enum QuilKeyState quilGetKeyState(int key) {
	int result = RELEASED;
	int GLFWKeyState = glfwGetKey(globalState.currentGLFWWindow, key);

	switch (GLFWKeyState) {
		case GLFW_PRESS:
			if (GLFWKeys[key] == GLFW_PRESS) {
				result = PRESSED;
			}
			else if (GLFWKeys[key] == GLFW_RELEASE) {
				result = JUST_PRESSED;
			}
			break;
		case GLFW_RELEASE:
			if (GLFWKeys[key] == GLFW_RELEASE) {
				result = RELEASED;
			}
			else if (GLFWKeys[key] == GLFW_PRESS) {
				result = JUST_RELEASED;
			}
			break;
		default:
			break;
	}

	GLFWKeys[key] = GLFWKeyState;
	return result;
}

const char* quilKeyToString(enum QuilKeyState key) {
	switch (key) {
		case PRESSED:
			return "PRESSED";
		case JUST_PRESSED:
			return "JUST_PRESSED";
		case RELEASED:
			return "RELEASED";
		case JUST_RELEASED:
			return "JUST_RELEASED";
		default:
			return "UNKNOWN_KEY_STATE";
	}
}

int quilIsKeyReleased(int key) {
	return quilGetKeyState(key) == RELEASED;
}

int quilIsKeyJustReleased(int key) {
	return quilGetKeyState(key) == JUST_RELEASED;
}

int quilIsKeyPressed(int key) {
	return quilGetKeyState(key) == PRESSED;
}

int quilIsKeyJustPressed(int key) {
	return quilGetKeyState(key) == JUST_PRESSED;
}
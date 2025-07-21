#include "quil.h"

struct QuilGlobalState globalState = {};
int GLFWKeys[105];
int GLFWMouseButtons[8];

void quilCreateWindowContext(GLFWwindow* currentGLFWWindow) {
	globalState.currentGLFWWindow = currentGLFWWindow;
}

enum QuilInputState quilGetKeyState(int key) {
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

enum QuilInputState quilGetMouseButtonState(int button) {
	int result = RELEASED;
	int GLFWMouseButtonState = glfwGetMouseButton(globalState.currentGLFWWindow, button);

	switch (GLFWMouseButtonState) {
		case GLFW_PRESS:
			if (GLFWMouseButtons[button] == GLFW_PRESS) {
				result = PRESSED;
			}
			else if (GLFWMouseButtons[button] == GLFW_RELEASE) {
				result = JUST_PRESSED;
			}
			break;
		case GLFW_RELEASE:
			if (GLFWMouseButtons[button] == GLFW_RELEASE) {
				result = RELEASED;
			}
			else if (GLFWMouseButtons[button] == GLFW_PRESS) {
				result = JUST_RELEASED;
			}
			break;
		default:
			break;
	}

	GLFWMouseButtons[button] = GLFWMouseButtonState;
	return result;
}

const char* quilKeyToString(enum QuilInputState key) {
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

int quilIsMouseButtonReleased(int button) {
	return quilGetMouseButtonState(button) == RELEASED;
}

int quilIsMouseButtonJustReleased(int button) {
	return quilGetMouseButtonState(button) == JUST_RELEASED;
}

int quilIsMouseButtonPressed(int button) {
	return quilGetMouseButtonState(button) == PRESSED;
}

int quilIsMouseButtonJustPressed(int button) {
	return quilGetMouseButtonState(button) == JUST_PRESSED;
}
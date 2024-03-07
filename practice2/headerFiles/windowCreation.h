#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void initSteps() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}
void gladLoadFunc() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "COULDN'T LOAD GLAD" << std::endl;
	}
}
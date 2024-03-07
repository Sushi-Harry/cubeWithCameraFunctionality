#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Shader {
public:
	
	unsigned int shaderID;
	Shader(const char* vertexPath, const char* fragmentPath) {
		
		
		//open the files
		string vertexCode, fragmentCode;
		ifstream vFile;
		vFile.open(vertexPath, ios::in);
		ifstream fFile;
		fFile.open(fragmentPath, ios::in);
		if (!vFile.is_open() || !fFile.is_open()) {
			std::cout << "Couldn't load the shader files" << std::endl;
		}
		//read the contents into a file
		stringstream vStream, fStream;
		vStream << vFile.rdbuf();//reading
		fStream << fFile.rdbuf();
		vertexCode = vStream.str();//writing
		fragmentCode = fStream.str();
		//closing the files
		vFile.close();
		fFile.close();
		//creating a const char* 
		const char* vShader = vertexCode.c_str();
		const char* fShader = fragmentCode.c_str();

		//The ShaderProgram
		unsigned int  vertShader = glCreateShader(GL_VERTEX_SHADER), fragShader = glCreateShader(GL_FRAGMENT_SHADER); ;
		glShaderSource(vertShader, 1, &vShader, NULL);
		glShaderSource(fragShader, 1, &fShader, NULL);
		glCompileShader(vertShader);
		glCompileShader(fragShader);
		shaderID = glCreateProgram();
		glAttachShader(shaderID, vertShader);
		glAttachShader(shaderID, fragShader);
		glLinkProgram(shaderID);
		glDeleteShader(vertShader);
		glDeleteShader(fragShader);
	}
	void useShader() {
		glUseProgram(shaderID);
	}

};

#endif
#pragma once
#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
//#include "GLAD/glad.h"

#include "stdio.h"
#include "stdlib.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"


#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include <iostream>



class ShaderTwo : public VictorGL
{
private:
	std::string ShaderH = ("Hello From ShaderTwo");
	std::string ShelloH = ("Hello From Shader_Two");
public:
	//var
	std::string shaderh_ = ShaderH;

	ShaderTwo() {} ;


	GLuint ShaderTwoCreateProgram();
	void ShaderTwoDisplay(GLFWwindow* ShaderOneWindow, double currentTime);
	void ShaderTwoInit(GLFWwindow* ShaderOneWindow);

	


};
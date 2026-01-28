#pragma once
#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
//#include "GLAD/glad.h"
#include <fstream>
#include <iostream>
#include <string>

#include "stdio.h"
#include "stdlib.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"


#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include <iostream>
#include "VictorGL.h"			/// added
#include "Display.h"

#include <iostream>




class ShaderThree : public VictorGL
{

protected:
	std::string Shade3Hello = "ShaderThree Says Hello";
public:

	void Hello_shade3()
	{
		std::cout << Shade3Hello << std::endl;
	}

	std::string readShaderSource(const char* filePath);
	
	GLuint ShaderThreeCreateProgram();
	void ShaderThreeDisplay(GLFWwindow* ShaderOneWindow, double currentTime);
	void ShaderThreeInit(GLFWwindow* ShaderOneWindow);
};
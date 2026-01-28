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

// Notes... 
// DO NOT EVER INCLUDE THE FKN .H FILE FROM ANY CLASS YOUR INHERETING, FOR SOME REASON BUGS ARISE THAT MAKE ME WANT TO PULL MY ****** OUT ,
// SO PLEASE TAKE NOT OF WHAT YOUR INCLUDING AND ENSURE ITS WORKING BEFORE YOU GO GALAVANTING OFF ADDING FUNCTIONS LIKE YOUR NEO FROM THE MATRIX
//												!!!!!!!!! So ChEcK yOuR hEaDeRs !!!!!!!!!

class ShaderOne : public VictorGL
{

public:

	ShaderOne() {};

	/*If I move this out of the class it doesn't work*/
	GLint vertCompiled;
	GLint fragComplied;
	GLint linked;

	GLFWwindow* ShaderOneWindow;

	GLuint		 ShaderOneCreateProgram();
	virtual void ShaderOneInit(GLFWwindow* ShaderOneWindow);
	void		 ShaderOneDisplay(GLFWwindow* ShaderOneWindow, double currentTime);


};
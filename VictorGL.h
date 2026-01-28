#pragma once
#define GLFW_INCLUDE_NONE
#define GLEW_STATIC
//#include "GLAD/glad.h"

#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <string>

#include "GLFW/glfw3.h"
#include "GLEW/glew.h"
//#include "ShaderOne.h" // --> DO NOT UNCOMMENT

#include <iostream>

// NEED TO ADD THE () AND THEN CLEAN UP CPP , NEXT WILL BE THEN TO CALL THE SHADER VIRTUAL DISPLAY FUNCTION
class VictorGL
{
protected:
	GLFWwindow* VicWind;

public:
	VictorGL() {};	


	const char* describeErr;
	const char* description;
	int screenW = 777;
	int screenH = 777;

	bool isFull = true;
	bool isNotFull = false;
	bool Dump = true;

	/*Current Window in use ! do not touch !*/
	struct glfwWinSurfRend
	{
		GLFWwindow* glfwWindow;			// hard coded user input window glfw
	};
		

	void glfwGetVer();
	void glfwinitLaunch();
	void glewInitLaunch();


	void GLFWVictorWindow(GLFWwindow* window);							// GLFWwindow 
	void Display(GLFWwindow* window, double currentTime);				// red display


};

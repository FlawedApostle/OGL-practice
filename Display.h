#pragma once


#include "stdio.h"
#include "stdlib.h"

#include <fstream>
#include <ostream>

#include <vector>
#include "ShaderOne.h"


#include <iostream>

///* DISPLAY CLASS WILL LOAD WINDOWS(DISPLAYS) FOR USER , READING FILES FOR GLSL SHADERS ALL FUNCTIONS ARE LOCATED IN THIS FILE */


/// THESE ARE TESTING PURPOSES , FOR LINKING SHADING WHEN READING FILES TO INPUT INTO SHADER FUNCTIONS DO NOT FUCK WITH THIS, ENSURE YOU KNOW!!!! WHERE YOU DECLARE THEM !!!!! PREVIOUS FILE HAD TO BE PUT IN CLASS
//vertCompiled  fragComplied linked
//GLint vertCompiled_;
//GLint fragCompiled_;
//GLint ProgLinked_;


class Display : public VictorGL
{
protected:
	GLFWwindow* shaderWind1; // = glfwCreateWindow(400, 700, "ShaderOneWind1_Window", NULL, NULL);
	GLFWwindow* DisplayC1 = glfwCreateWindow(400, 400, "Display 1", NULL, NULL);
	GLFWwindow* Display1; // = glfwCreateWindow(400, 400, "Display 1", NULL, NULL);
private:
	bool windowTrue = true;
	bool windowFlase = false;
public:
	GLFWwindow* shaderwind1_ = shaderWind1;

	struct Displays_
	{
		GLFWwindow* Display1; //  = glfwCreateWindow(400, 400, "Display 1", NULL, NULL);
		GLFWwindow* GLFWWind;

	};
	struct shaderWinds
	{
		GLFWwindow* shaderWind1;
	};

	int h, w;
	const char* WinTitle;
	const char* GLFWwindows_string = "GLFWwindows";


	/*Test () 1*/
	void Display1_cast();
	void Display1_context();
	bool Display1_Destroy();
	/**********************/

	/* Read Files Regular files */
	std::string readShaderSources(const char* filePath);
	virtual std::string ReadShaderSrc(const char* filePath_v);
	virtual std::string ReadShaderSrc(const char* filePath_v, const char* filePath_f);

	/*Vec */
	// Vector stores all user/newly created glfwWindows
	std::vector<GLFWwindow*> GLFWwindows {};
	
	void DisplayWindows_Basic(GLFWwindow* temp, double currentTime);
	
	/// glfwWindow create --> User input // Set Context --> User input
	void DisplayWindows_CreateWindow(GLFWwindow* temp);
	void DisplayWindows_CreateWindow(GLFWwindow* temp, int w, int h, const char* WinTitle);
	bool DisplayWindows_ReturnWindow_Back();
	bool DisplayWindows_ReturnWindow_front();
	void DisplayWindows_context(GLFWwindow* temp);

	virtual void Display_ShoudlCloseWindow(GLFWwindow* temp);

	void DisplayWindows_vecReturn();
	void DisplayWindows_DestroyWindows(GLFWwindow* temp);
	/**********************/


	/*RENDER ()*/
	


};



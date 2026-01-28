#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
//#include "GLAD/glad.h"

#include "stdio.h"
#include "stdlib.h"
#include <iostream>

#include <fstream>
#include <ostream>

#include "GLFW/glfw3.h"
#include "GLEW/glew.h"

#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include "VictorGL.h"
#include "Display.h"
#include "ShaderTwo.h"
#include "ShaderOne.h"
#include "ErrorHandles.h"

///* DISPLAY CLASS WILL LOAD WINDOWS(DISPLAYS) FOR USER , READING FILES FOR GLSL SHADERS ALL FUNCTIONS ARE LOCATED IN THIS FILE */

VictorGL VictorGL_disp;
ErrorHandles errorhandles_disp;
ShaderOne shader1_disp;



/*Test ()*/
void Display::Display1_cast()
{
	Display1 = glfwCreateWindow(400, 400, "Display 1", NULL, NULL);
	if (!glfwCreateWindow)
	{	
		errorhandles_disp.GLFWError_check();
	}
	errorhandles_disp.Memaddress_window(Display1);
}
void Display::Display1_context()
{
	//glfwGetCurrentContext();
	Display1; //= glfwCreateWindow(400, 400, "Display 1", NULL, NULL);
	errorhandles_disp.Memaddress_window(Display1);
	glfwMakeContextCurrent(Display1);
	if (!glfwMakeContextCurrent)
	{
		errorhandles_disp.GLFWError_check();
	}
	errorhandles_disp.Memaddress_window(Display1);
}
bool Display::Display1_Destroy()
{
	glfwDestroyWindow(Display1);
	if (!Display1)
	{	
		return false;
		errorhandles_disp.GLFWError_check();
	}
	errorhandles_disp.Memaddress_window(Display1);
	return true;

}
/**********************/

/* Read Files Regular files */  // [readShaderSources is pdf example ()] don't delete!
std::string Display::readShaderSources(const char* filePath)
{
	std::string content;
	std::ifstream fileStream(filePath, std::ios::in);
	std::string line = "";
	while (!fileStream.eof())
	{
		getline(fileStream, line);
		content.append(line + "\n");
		std::cout << content << std::endl;
	}
	return content;
}

std::string Display::ReadShaderSrc(const char* filePath_v)
{
	std::string content;
	std::ifstream fileStreamV(filePath_v, std::ios::in);
	std::string line = "";
	while (!fileStreamV.eof())
	{
		getline(fileStreamV, line);
		content.append(line + "\n");
		std::cout << content << std::endl;
	}

	std::cout << "std::string ReadShaderSrc" << std::endl;
	return content;
}
std::string Display::ReadShaderSrc(const char* filePath_v, const char* filePath_f)
{
	std::string contentV;
	std::ifstream fileStreamV(filePath_v, std::ios::in);
	if (!fileStreamV)
	{
		std::cout << "FilestreamV error!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	std::string lineV = "";
	while (!fileStreamV.eof())
	{
		getline(fileStreamV, lineV);
		contentV.append(lineV + "\n");
		std::cout << contentV << std::endl;
	}

	std::string contentF;
	std::ifstream fileStreamF(filePath_f, std::ios::in);
	if (!fileStreamF)
	{
		std::cout << "FilestreamF error!" << std::endl;
		exit(EXIT_SUCCESS);
	}
	std::string lineF = "";
	while (!fileStreamF.eof())
	{
		getline(fileStreamF, lineF);
		contentF.append(lineF + "\n");
		std::cout << contentF << std::endl;
	}

	return contentV; return contentF;
}


/* Create Shaders Prog*/



/* <summary>
/// These work as of 5:14 pm April 8th 
/// A vector GLFWwindow* array is made, 
/// everytime a user inputs a window its added to the array
/// when the user makes a new context, the first index (window) is placed as the current context loading.
/// --> maybe index the [x] so that you know which one is wich and whihc one can be called
/// --> keep eye on the .push() inside context
/// <param name="temp"></param> */

void Display::DisplayWindows_Basic(GLFWwindow* temp , double currentTime)
{
	glClearColor(1.0, 0.50, 0.0,1.0);		// orange
	glClear(GL_COLOR_BUFFER_BIT);
}

/// glfwWindow create --> User input // Set Context --> User input
void Display::DisplayWindows_CreateWindow(GLFWwindow* temp)
{
	temp = glfwCreateWindow(400, 400, "DisplayAddWIndows", NULL, NULL);
	Display::GLFWwindows.push_back(temp);	// adding to vec array
	errorhandles_disp.Memaddress_window_notes(temp , "DisplayWindows_CreateWindows::");
}
void Display::DisplayWindows_CreateWindow(GLFWwindow* temp, int w, int h , const char* WinTitle)
{
	temp = glfwCreateWindow(w, h, WinTitle, NULL, NULL);
	GLFWwindows.push_back(temp);	// adding to vec array
	errorhandles_disp.Memaddress_window_notes(temp, "DisplayWindows_CreateWindows::");
}

bool Display::DisplayWindows_ReturnWindow_Back()
{	
	return Display::GLFWwindows.back();
}
bool Display::DisplayWindows_ReturnWindow_front()
{
	return Display::GLFWwindows.front();
}
// Print GlfWwindow vector array contents
void Display::DisplayWindows_vecReturn()
{
	for (auto windows : GLFWwindows)
	{
		errorhandles_disp.Memaddress_window_notes(windows , "DisplayWindows_vecReturn");
		//std::cout << windows << std::endl;
		//std::cout << "GLFWwindows Vec arr size :: [" << GLFWwindows.size() << "]" << std::endl;
	}
}

void Display::DisplayWindows_context(GLFWwindow* temp)
{
	glfwMakeContextCurrent(GLFWwindows.back());		// calling the front of the vec array
	if (!glfwMakeContextCurrent)
	{
		errorhandles_disp.GLFWError_notes("GLFWwindows_context : err");
	}	errorhandles_disp.Memaddress_window(GLFWwindows.back());
}
/// Calling the user input window and setting it to the glfwWindowoShouldClose () --> its pretty arbitrary ,
// its purpose is to just follow the mem address of the newly inputed window by the user
void Display::Display_ShoudlCloseWindow(GLFWwindow* temp)
{
	temp = Display::GLFWwindows.back();
	glfwWindowShouldClose(temp);
}



/// Clean Vector Array std::vec<GLFWwindow*> GLFWwindows {};
// Print the current Vector capacity .size()
// Print the mem address of capacity index(s)
// Pop_back() destroy last window
// Print (new) current capacity index(s) .size()
// Print mem address of current capacity of index(s) 
// --> if null return Vec is empty !
void Display::DisplayWindows_DestroyWindows(GLFWwindow* temp)
{
	int* tempptr;
	tempptr = (int*)temp;
	//for (auto win : GLFWwindows)
	//{
	//}
	//GLFWwindows.erase(GLFWwindows.end());
	std::cout << "GLFWwindows vec Array Capacity: "; std::cout << GLFWwindows.size() << std::endl;
	errorhandles_disp.Memaddress_windowVec_notes(GLFWwindows , "NA");
	GLFWwindows.pop_back();
	std::cout << "GLFWwindows vec Array Capacity after destroy: "; std::cout << GLFWwindows.size() << std::endl;
	errorhandles_disp.Memaddress_windowVec_notes(GLFWwindows, "NA");
	//DisplayWindows_vecReturn();
}



//ErrorHandles* ErrorHandles_disptr; // ErrorHandles_disptr->ErrorSaysHello();
/*Renderes ()*/

//bool Display::CreateShaderProgram(GLuint vshader_, GLuint fshader_)
//{
//	return 0;
	//vshader_ = glCreateShader(GL_VERTEX_SHADER);
	//fshader_ = glCreateShader(GL_FRAGMENT_SHADER);
	//
	//if (!glCreateShader(GL_VERTEX_SHADER))
	//{
	//	errorhandles_disp.printShaderLog(vshader_);
	//}	//ErrorHandles_disptr->Success("Vertex Shader Log");
	//if (!glCreateShader(GL_FRAGMENT_SHADER))
	//{	
	//	errorhandles_disp.printProgramLog(fshader_);
	//}	//ErrorHandles_disptr->Success("Fragment Prog Log");

	///* Load the Shader obj ID's 
// Fills the empty [Shader objects] (made above) with their (respective) Shader string info  
// Compile the Shader(s) [vShader , fShader] */
	//glShaderSource(vshader_, 1, &vshaderSource, NULL);			// shader source will be file path !!
	//glShaderSource(fshader_, 1, &fshaderSource, NULL);
	//glCompileShader(vshader_);
	//glCompileShader(fshader_);

	//// debug
	//if (!glShaderSource)
	//{
	//	errorhandles_disp.OpenGlError_notes("glShaderSource_fShader_&&_vShader");
	//	errorhandles_disp.OpenGlError_check();
	//}	errorhandles_disp.Success("glCompileShader_vShader");
	//	errorhandles_disp.Success("glCompileShader_fShader");

	//// Error handling ----> we here boi keep up ok double time the effort!!
	//glGetShaderiv(vshader_, GL_COMPILE_STATUS, &vertCompiled_);
	//if (vertCompiled_ != 1)
	//{
	//	errorhandles_disp.OpenGlError_check();
	//	std::cout << "Vertex_Shader_Compile_Status :: Failed " << std::endl;
	//	errorhandles_disp.printShaderLog(vshader_);
	//}	errorhandles_disp.Success("glGetShaderiv_vShader");

	//glGetShaderiv(fshader_, GL_COMPILE_STATUS, &fragCompiled_);
	//if (fragCompiled_ != 1)
	//{
	//	errorhandles_disp.OpenGlError_check();
	//	std::cout << "Fragment_Shader_Compile_Status :: Failed " << std::endl;
	//	errorhandles_disp.printShaderLog(fshader_);
	//}	errorhandles_disp.Success("glGetShaderiv_fShader");

	/* An ID is CREATED for vfProgram to launch shader objects */
	/// Create Prog , Attach Shader , Link Prog (with loaded shaders) -> Create & Run shader obj
	//GLuint vfProgram = glCreateProgram();
	//glAttachShader(vfProgram, vshader_);
	//glAttachShader(vfProgram, fshader_);
	//glLinkProgram(vfProgram);
	//// debug
	//glGetProgramiv(vfProgram, GL_LINK_STATUS, &ProgLinked_);
	//if (ProgLinked_ != 1)
	//{
	//	errorhandles_disp.OpenGlError_check();
	//	std::cout << "GL_Linking Program : Failed" << std::endl;
	//	errorhandles_disp.printProgramLog(vfProgram);
	//}	errorhandles_disp.Success("glGetProgramiv : GL_LINK_STATUS");			//virtual func, can call it from any derived class 
	//
	//return vfProgram;
//}
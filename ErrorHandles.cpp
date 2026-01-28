#define GLEW_STATIC
#define GLFW_INCLUDE_NONE


#include "GLFW/glfw3.h"
#include "GLEW/glew.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include "VictorGL.h"
#include "ErrorHandles.h"
#include "ShaderThree.h"


#include <iostream>
#include <cstdlib>


// OpenGl err handle
// Checks if glerror != no error , then read error to terminal
bool ErrorHandles::OpenGlError_clear()
{	
	//printf("glErrorClear Test ! \n");
	if (glGetError != GL_NO_ERROR)
	{
		OpenGlError_check();
		error_found = false;
	}	
	return error_found = true;
}
bool ErrorHandles::OpenGlError_check()
{
	std::cout << "[GL_ERROR] :: " << glfw_error << std::endl;
	return error_found = true;
}
void ErrorHandles::OpenGlError_notes(std::string errorNotes)
{
	std::cout << "[" << errorNotes << "]" << "::" << "[ " << glfw_error << " ]" << std::endl;
}

// GLfw err handle
void ErrorHandles::GLFWError_check()
{
	const char* glfwDescription;
	GLenum glfw_error = glfwGetError(&glfwDescription);
	std::cout << "[GLFW Error Code:] (" << glfw_error << ")" << std::endl;
}
void ErrorHandles::GLFWError_notes(std::string notes)
{
	const char* glfwDescription;
	GLenum glfw_error = glfwGetError(&glfwDescription);
	std::cout << "Notes: [" << notes << "] " << "[GLFW Error Code:] (" << glfw_error << ")" << std::endl;
}



/* Mem Addresses */
void ErrorHandles::Memaddress_window(GLFWwindow* memadd)
{
	std::cout << "(Window Memory Address) :: [" << memadd << "]" << std::endl;
}
void ErrorHandles::Memaddress_window_notes(GLFWwindow* memadd, std::string notes)
{

	std::cout << "["<< notes <<"] :: [" << memadd << "]" << std::endl;
}
void ErrorHandles::Memaddress_windowVec_notes(std::vector<GLFWwindow*> memadd, std::string notes)
{
	//std::cout << "(Window Memory Address) :: [" << notes << "]" << std::endl;  
		for (auto mem : memadd)
		{	
			mem;
			std::cout << "[Vector Memory Address] :: [" << mem << "]" << std::endl;
		}	
		
		if (memadd.empty())
		{
			printf("GLFWwindows Vec is empty !\n");
		}
			
		
}



void ErrorHandles::Success(std::string succesnotes)
{
	std::cout << "(Success!) " << "::" << " [" << succesnotes << "]" << std::endl;
}
void ErrorHandles::Success()
{
	std::cout << "(Success!)" << std::endl;
}


///* Getting Shader Log info - > debugging
// | GL_SHADER_TYPE     returns Fragment, Vertex  -> what Shader type/obj is being queried
// | GL_COMPILE_STATUS  returns True || False     -> wether Shader obj have compiled correctly 
// | GL_DELETE_STATUS   returns True || False     -> wether obj is flagged for deletion
// | GL_INFO_LOG_LENGTH returns int               -> (max) size of buffer required
// | GL_SHADER_SOURCE_LENGTH returns size of concatenated strings in 'Shader' .txt doc(s) 
// -> glGetShaderiv	     =  Returns the number of characters in the information log for shader [param's are line above ^]
// -> glGetShaderSource  =  Getting the 'concatenation' string(s) info from the Shader object 
// -> glGetShaderInfoLog =  Getting the buffer size info by calling [GL_INFO_LOG_LENGTH] , 
// glGetShaderInfoLog    =  'how it works' --> Shader , buffer length (max) , returns info log strings (int format) , returns info log in chars (char format)
// ------------------------------------------> the strings and buffer are [ratio'd] to calculate the max size (needed) of buffer
//* Shader Log Info
void  ErrorHandles::printShaderLog(GLuint ShaderLog_)
{	
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetShaderiv(ShaderLog_, GL_INFO_LOG_LENGTH, &len);

	if (len > 0)
	{	// Taking the buffer size length from the info log ,
		// log is set char pointer mem size equal to the buffer length (of type int) 
		// log (char type) = mem of type char
		log = (char*)malloc(len);
		glGetShaderInfoLog(ShaderLog_, len, &chWrittn, log);		
		std::cout << "Shader info Log: " << log << std::endl;
		free(log); // have to free the log entry
	}

}
//* Program Log Info
void ErrorHandles::printProgramLog(int ProgramLog_)
{
	int len = 0;
	int chWrittn = 0;
	char* log;
	glGetProgramiv(ProgramLog_, GL_INFO_LOG_LENGTH, &len);
	if (len > 0)
	{
		log = (char*)malloc(len);
		glGetProgramInfoLog(ProgramLog_, len, &chWrittn, log);
		std::cout << "Program info Log: " << log <<std::endl;
		free(log);	// have to free the log entry
	}
}




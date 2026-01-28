#pragma once
#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
#include <vector>

#include "GLFW/glfw3.h"
#include "GLEW/glew.h"

#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"


//#include "VictorGL.h"

#include <iostream>

class ErrorHandles : public VictorGL
{

protected:
	bool error_found;
	GLenum glfw_error = glfwGetError(&glfwDescription);

	const char* glfwDescription;
	std::string ErrorHandles_Hello = "ErrorHandles Test String";
	std::string successNotes;
 public:


	//`ErrorHandles() {};

	void ErrorSaysHello()
	{
		printf("ErrorHandles Says Hello!");
	}

	virtual bool OpenGlError_clear();
	virtual bool OpenGlError_check();
	virtual void OpenGlError_notes(std::string errorNotes);

	virtual void GLFWError_notes(std::string notes);
	virtual void GLFWError_check();


	virtual void Memaddress_window(GLFWwindow* memadd);
	virtual void Memaddress_window_notes(GLFWwindow* memadd , std::string notes);
	virtual void Memaddress_windowVec_notes(std::vector<GLFWwindow*> memadd, std::string notes);

	virtual void Success(std::string succesnotes);
	virtual void Success();

	virtual void printShaderLog(GLuint ShaderLog_);
	virtual void printProgramLog(int ProgramLog_);


};
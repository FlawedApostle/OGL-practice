//#pragma once
//
//#include "GLFW/glfw3.h"
//#include "GLEW/glew.h"
//
//class MainTest
//{
//private:
//
//	/*GLFWwindow* GLFWwin;*/
//
//	///  Error handling vars
//	int			errorGLFW;
//	const char* errDescription;
//	GLenum		GLFWerr = glfwGetError(&errDescription);
//
//public:
//
//	GLFWwindow* GLFWwin;
//
//	int			errorGLFW_;
//	const char* errDescription_;
//	GLenum		GLFWerr_;
//
//
//	//MainTest();
//
//	MainTest()
//	{
//		MainTest::errorGLFW		 = errorGLFW_;
//		MainTest::errDescription = errDescription_;
//		MainTest::GLFWerr		 = GLFWerr_;
//	}
//
//	//MainTest(const char* errDescription_, GLenum GLFWerr_, int errorGLFW_)
//	//{
//	//	errDescription_ = MainTest::errDescription;
//	//	MainTest::GLFWerr = GLFWerr_;
//	//	MainTest::errorGLFW = errorGLFW_;
//	//}
//
//	//MainTest();
//
//	//MainTest(GLFWwindow* GLFWwin_)
//	//{
//	//	GLFWwin_ = GLFWwin;
//	//}
//
//	///*GLFW FUNCTIONS*/
//	//*glfw initialization func*/
//	void GLFWinitialization();
//	//*Engine Run Time , executes once programs ends show entire runtime */
//	void RunTimeGLFW();
//	// Testing Purposes
//	const void GetVerGLFW();
//
//	///*GLEW FUNCTIONS*/
//	void GLEWinitialization();
//	void RunTimeGLEW();
//	void GetVerGLEW();
//
//
//
//	/*TRIANGLE GRAPHIC*/
//	void Tri();
//
//
//};
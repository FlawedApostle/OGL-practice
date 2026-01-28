//#include <iostream>
////#define FREEGLUT_STATIC
//#define GLFW_INCLUDE_NONE													// Place gl.h and glfw/. in any order
//#define GLEW_STATIC
//
//#include "MainTest.h"
//
//#include "glm/glm.hpp"
//
////#include "GLAD/glad.h"
//#include "GLFW/glfw3.h"
//
//#include "GLEW/glew.h"
////#include "GLUT/glut.h"
//
////#include "SDL2/SDL.h"
////#include "stdio.h"
//
//
///*LIBS NOTES
//REGARDING GLEW; INSIDE THE PROPERTIES C++ -> PREPROCCESSOR -> PREPROCCESSOR DEFINITIONS [GLEW_STATIC] IS SET. THIS IS DONE TO PREVENT BUILD ERRORS WHEN COMPILING WITH 'GLEW'
//REGARDING GLEW; RATHER THAN SETTING IN PREPROCCESSOR DEFINITIONS GLEW_STATIC IS #define instead
//REGARDING GLEW; TO LINK GLEW STATICALLY YOU MUST BUILD FROM SOURCE AND START FROM GLEW THEN ADD LIBS FROM THERE ONWARDS. [THIS BUILD BEGAN WITH GLFW BINARY BUILD.] [BUILDING GLEW WITH CMAKE FROM SOURCE WILL CREATE A STATIC LIB, TAKE THAT .sln and move it to a folder and add dependencies (test for later)]
//
//REGARDING FREEGLUT; freeglut dll file has been added to the /debug file. [NOT x64/debug]
//*/
//
///*LIBS ADDED
//GLFW	[YES]
//GLEW	[YES]
//GLUT	[NO]
//GLAD	[YES]	-> Installed, but not initialized. Either GLEW or GLAD can be used they cannot be used at the same time
//SDL		[NO]
//*/
//
//
///*CLASS DEC && POINTERS*/
//MainTest* maintest;							// wont work can only pass functions as pointers, pointers contain nothing its empty just add , so it wont have data to append, store the image in a function and then point to that (), which contains the data to be appeneded
//MainTest mt;
//
//int SCREEN_WIDTH = 600;
//int SCREEN_HEIGHT = 500;
//int error;
//
//
//int main(void)						//int argc, char* args[]
//{
//	//The window we'll be rendering to
//	//SDL_Window* SDLwin = NULL;
//	//The surface contained by the window
//	//SDL_Surface* screenSurface = NULL;
//	//Initialize SDL
//	//SDL_Surface* SDL_SetVideoMode(int width, int height, int bpp, Uint32 SDL_OPENGL);
//	//if (SDL_Init(SDL_INIT_VIDEO) < 0)
//	//{
//	//	printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
//	//}
//	//else
//	//{
//	//	//Create window
//	//	SDLwin = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
//	//	if (SDLwin == NULL)
//	//	{
//	//		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
//	//	}
//	//	else
//	//	{
//	//		//Get window surface
//	//		screenSurface = SDL_GetWindowSurface(SDLwin);
//	//		//Fill the surface white
//	//		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
//	//		//Update the surface
//	//		SDL_UpdateWindowSurface(SDLwin);
//	//		//Hack to get window to stay up
//	//		SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
//	//	}
//	//}
//
//	/*GLFW ERROR HANDLING*/
//	const char* description;
//	int GLFWerr = glfwGetError(&description);
//	///*GLFW initialization*/
//	mt.GLFWinitialization();
//	
//	
//
//	//if (!glfwInit())
//	//{
//	//	fprintf(stderr, "%d", GLFWerr);
//	//}
//	//else printf("GLFW Success! \nGLFW Ver: %s \n", glfwGetVersionString());
//
//	/// Place error_callback function here
//	
//	/// GLFW window*
//	//GLFWwindow* GLFWwin;
//
//	///*setting windowhints glfw core profiles*/
//	///* BE CAREFULL WHAT SETTINGS ARE SET OTHERWISE GRAPHICS WONT SHOW IN WINDOW TO USER !!! */
//	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//	///*CREATE WINDOW*/
//	mt.GLFWwin = glfwCreateWindow(640, 480, "GLFW Window", NULL, NULL);
//	if (!mt.GLFWwin)
//	{
//		glfwTerminate();
//		fprintf(stderr, "%d\n", glfwGetError(&description));
//	}
//	
//
//	///*GLFW CURRENT CONTEXT WINDOW*/
//	glfwMakeContextCurrent(mt.GLFWwin);
//
//	///*GLEW initialization*/
//	// Without context inside the 'glew' documentation that without context the 'glewInit' function library cannot be called
//	GLenum err = glewInit();
//	if (GLEW_OK != err)
//	{
//		fprintf(stderr, "%s", glewGetErrorString(err));
//	}	else printf("GLEW_OK!\n");
//	
//
//	///* GLAD initialization */
//	//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//	//// error handling
//	//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	//{
//	//	fprintf(stderr , description);
//	//} else printf("GladloadProc Success!\n");
//
//	
//	
//	///* Loop until the user closes the window */
//	while (!glfwWindowShouldClose(mt.GLFWwin))
//	{
//		/* Render here */
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// Triangle Test
//		mt.Tri();
//
//		/* Swap front and back buffers */
//		glfwSwapBuffers(mt.GLFWwin);
//
//		/* Poll for and process events */
//		glfwPollEvents();
//
//	}
//
//	/*Runtime check, must call after render window is created, and called*/
//	mt.RunTimeGLFW();
//
//
//
//	///*GLEW initialization -> GLEW REQUIRES GLFW WINDOW CONTEX PRIOR TO INITIALIZATION*/
//	///*CHECK HEADER FILES COMMENTED OUT - EITHER GLAD OR GLEW !!*/
//	//GLenum GLEWerr = glewInit();
//	///*GLEW ERROR HANDLING*/
//	//if (GLEW_OK != GLEWerr)
//	//{
//	//	fprintf(stderr, "%s\n", glew.cin.ErrorString(GLEWerr));
//	//}
//	//else printf("GLEW_OK!\n");
//	
//
//	glfwTerminate();
//	return 0;
//
//}
//
////int main(int argc , char** argv)																// [&argc, argv] Need to run -> ITS THE LAW LIKE AM OF FM !
////{
////	std::cout << "Hello" << std::endl;
////	std::cin;
////
////	///*Initialize GLFW */
////	std::cout << glfwGetVersionString() << std::endl;											// Version of GLFW
////	glfwInit();
////	GLenum glfwErr = !glfwInit();
////	const char* description;
////	if (glfwErr)
////	{
////		
////		fprintf(stderr , "%d" , glfwGetError(&description));
////	}
////
////	///*SETTING GLFW VER && MINOR*/
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////	
////	GLFWwindow* window;
////	window = glfwCreateWindow(640, 480, "GLFW Window", NULL, NULL);
////	if (!window)
////	{
////		glfwTerminate();
////		fprintf(stderr, "%d", glfwGetError(&description));
////		return -1;
////	}
////
////	
////	///* glfwContext */
////	glfwMakeContextCurrent(window);
////	
////	///*INITIALIZING FREEGLUT*/
////	GLenum glewErr = glewInit();
////	fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));					// Version of GLFW
////	glutInit(&argc, argv);																		// Needed [&argc, argv] to call to run freeglut library
////	//glutCreateWindow("GLEW Test");																// !! Freeglut dll is needed (add to [x64/debug || /debug] file !
////	///Error Checking
////	if (GLEW_OK != glewErr)
////	{
////		/* Problem: glewInit failed, something is seriously wrong. */
////		fprintf(stderr, "Error: %s\n", glewGetErrorString(glewErr));
////	}
////
////
////
////	while (!glfwWindowShouldClose(window))
////	{
////		///* Render here */
////		glClear(GL_COLOR_BUFFER_BIT);
////
////		///* Swap front and back buffers */
////		glfwSwapBuffers(window);
////
////		///* Poll for and process events */
////		glfwPollEvents();
////	}
////
////	glfwDestroyWindow(window);
////	glfwTerminate();
////}
//
////MainTest::MainTest()
////{
////}
//
/////*glfw initialization func*/
//void MainTest::GLFWinitialization()
//{
//	if (!glfwInit())
//	{
//		//fprintf(stderr, "GLEW_NOT_OKAY!\nGLEW_ERROR:  %d\n", glfwGetError(&errDescription_));
//		fprintf(stderr, "GLFW_NOT_OKAY!\nGLFW_ERROR:  %d\n", GLFWerr_);
//	}
//	else printf("GLFW_OK!\nCurrent Loaded GLFW ver: %s \n", glfwGetVersionString());
//}
//
///// GLFW RUN TIME
//void MainTest::RunTimeGLFW()
//{
//	if (glfwWindowShouldClose(GLFWwin) == 1)
//	{
//		double time = glfwGetTime();
//		std::cout << "Current Run Time: " << time << std::endl;
//	}
//}
//
//
///// Testing Purposes
//const void MainTest::GetVerGLFW()
//{
//	
//	std::cout << glfwGetVersionString() << std::endl;	
//}
//
//
//void MainTest::Tri()
//{
//	glBegin(GL_TRIANGLES);
//	glVertex2f(-0.5f, -0.5f);
//	glVertex2f(0.0f, 0.5f);
//	glVertex2f(0.5f, -0.5f);
//	glEnd();
//}
//
//
/////*GLEW FUNCTIONS*/
//void MainTest::GLEWinitialization()
//{
//
//}
//void MainTest::RunTimeGLEW()
//{
//
//}
//void MainTest::GetVerGLEW()
//{
//
//}
//
//
//
//
//
//
//
////void error_callback(int error, const char* description)
////{
////	fprintf(stderr, "Error: %d  %c\n", description);
////}
//
//void handle_error(int error)
//{
//	fprintf(stderr, "error %d\n", error);
//}
//
//void handle_errorCode(int error)
//{
//	int errorCode = glfwGetError(NULL);
//	if (errorCode != GLFW_NO_ERROR)
//	{
//		handle_error(error);
//	}
//}
//
//static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GLFW_TRUE);
//}
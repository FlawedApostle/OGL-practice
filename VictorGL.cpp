// NEED TO DEFINE GLEW_STATIC IN ORDER TO COMPILE GLEW CORRECTLY. 
//THIS CAN BE DONE IN THE PRE PROCCESSOR AS WELL, I AM DOING IT VIA #define headers on each file.
#define GLEW_STATIC

#define GLFW_INCLUDE_NONE
//#include "GLAD/glad.h"

#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <ostream>

#include "GLFW/glfw3.h"
#include "GLEW/glew.h"

#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include "VictorGL.h"
#include "Display.h"
#include "ShaderOne.h"
#include "ShaderTwo.h"
#include "ErrorHandles.h"

#include <iostream>

VictorGL VictorGL_vic;
VictorGL::glfwWinSurfRend GLFWWinSurfRend_vic;
ShaderOne shader1_vic;
ShaderTwo shader2_vic;				// has to be pointer why ??? -> when constructors exist , Pointers you must acquit
ErrorHandles errorhandles_vic;
Display Display_vic;
Display::Displays_ Displays_vic;

///* Virtuals
//* Prints Shader program(s) logs , //* Prints Shader Object info
/*void printProgramLog(int ProgramLog_) {}
void printShaderLog(GLuint ShaderLog_) {}*/

//******** Get Ver
void VictorGL::glfwGetVer()
{
	printf("[Current glfw Ver:] %s\n", glfwGetVersionString());
}
///********* Initializations *********************************************/
// Glew Initialization -> (glewInit() != GLEW_OK ) [has to be written like this]
void VictorGL::glfwinitLaunch()
{
	if (!glfwInit())
	{
		errorhandles_vic.GLFWError_check();
		exit(EXIT_FAILURE);
	}	errorhandles_vic.Success("GLFW_OK!");
}
void VictorGL::glewInitLaunch()
{
	if (glewInit() != GLEW_OK )
	{
			printf("GLEW_NOTOK\n"); exit(EXIT_FAILURE);
	}		errorhandles_vic.Success("GLEW_OK");
}




///********************* Launch Window ****** works: 3:21pm April 4 ******************************/	
void VictorGL::GLFWVictorWindow(GLFWwindow* window)
{
		//window = glfwWinds_.GLFWWind = glfwCreateWindow(700, 700, "VictorGL_Window", NULL, NULL);
		window = GLFWWinSurfRend_vic.glfwWindow = glfwCreateWindow(700, 700, "VictorGL_Window", NULL, NULL);
		if (!window)
		{
			errorhandles_vic.GLFWError_notes("VictorGL::Display");
		}	errorhandles_vic.Success("VictorGL::GLFWVictorWindow Created"); std::cout << "[VictorGL::GLFWVictorWindow] :: (memAdd#) :: [" << window << "]" << std::endl;
			
	

}


///*********** RENDER Display color || works as of 3:20 Aprl 9th 2024
void VictorGL::Display(GLFWwindow* window, double currentTime)
{	
	
	 Display_vic.GLFWwindows.push_back(window);
	//window = displays_.GLFWwindows.front();
	//errorHandles_.Memaddress_window(window , "Victor DIsplay()");		// test to check mem add	
	
	//  Setting screen to red: No joke if you don't set the values as floats 1.0f  ---> The screen will not render correctly !
	//	GL_COLOR_BUFFER_BIT is calling the glColor params set line prior , GL_DEPTH_CLEAR_VALUE || GL_STENCIL_CLEAR_VALUE || GL_DEPTH_CLEAR_VALUE	
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);						
	glClear(GL_COLOR_BUFFER_BIT);								
	//std::cout << currentTime << std::endl;
}		

//int main(void)
//{	
//	std::ifstream testDoc; //("shaders/testdoc.txt");
//	//std::ofstream testDoc; //("shaders/testdoc.txt");
//	testDoc.open("shaders/testdoc.txt"); 
//	std::string readtestdoc;
//	
//	if (testDoc.is_open()) 
//	{	
//		//testDoc >> readtestdoc;
//		//std::cout << readtestdoc;
//		char gettestdoc; 
//		while (testDoc) 
//		{
//			gettestdoc = testDoc.get();
//			std::cout << gettestdoc;
//		}
//	}
//	//Hello(); /*syntax test*/
	//shaderone.ShaderHello("shaderone.");		// testing the virtual function
	//shadertwo.ShaderHello("shadertwo.");		// testing the virtual function
	//shadertwo.ShaderTwoHello();
	//shadertwo.Shello();
	// Creating a new ShaderTwo obj name st , then using st object to ->
	// change ShaderTwo constructor to change the string value of Shello
	//ShaderTwo st("hello new obj st");
	//st.Shello();
//
//	Vgl.glfwGetVer();	// getting glfw ver , can be called prior to initialization
//	// glfwinitLaunch -> works as of April 1 1:11pm
//	///*********************************************************** Launching GLFW init *************************************************/
//	Vgl.glfwinitLaunch();
//	//********** Setting GLFW versions MAJOR && MINOR ******************************************************/
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
//	///************************************************************ CREATE GLFW window ************************************************/
//	//* works as of 11:56 AM April 1st */ --> there must be a window created to bind to a context for 'glew' to be able to initialize !
//		//Vgl.GLFWVictorWindow(gwsr.glfwWindow);				// works as of 3:27 April 4
//	Vgl.GLFWVictorWindow(win);
//	///******************************************************** Set Current Context Window *******************************************/
//	//* Make current window the current context->need in order to run glewInit() */
//		//glfwMakeContextCurrent(win);	// gwsr.glfwWindow
//	Vgl.Context(win);				// context test !!
//	///*********** initialize glew library  (glewInit() != GLEW_OK) *****************************************/
//	Vgl.glewInitLaunch();
//	//**************** GLAD ********************************************************************************/
//		//gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
//	//*************************************************/
//	///************************************************************* Buffer_Lane *****************************************************/
//	// Next, create a giant buffer function that's open where what ever we put in it we can just call it in the main !! 
//	shaderone.ShaderOneInit(win);						// loading the vertex point(s) 'locations'
//	//shaderone.ShaderOneCreateProgram();				// color -> irrelevant function call - too much mem usage !!
/////********************************************************** Buffer Swap Interval ************************************************/
//	glfwSwapInterval(1);
//	///************************************************************* Poll events ******************************************************/
//	printf("Polling events Begins: \n"); //std::cout << glfwGetTime() << std::endl;
//
//	/// Sadly this containts what window to load - so maybe not a function?? 
//	//Vgl.WhileOn(win);	/// Dont forget me !!
//	
//	//--> have to hard code it , rem only inside the scope does do they know what 'win' is --> in functions its fine, outside no, NO
//	win = gwsr.glfwWindow;
//	std::cout << "Window Mem Add: [" << gwsr.glfwWindow << "]" << std::endl;
//	while (!glfwWindowShouldClose(gwsr.glfwWindow))
//	{
//		while (!glfwWindowShouldClose(gwsr.glfwWindow))
//		{
//			//shaderone.ShaderOneDisplay(gwsr.glfwWindow, glfwGetTime());					// Blue dot
//			//Vgl.Display(gwsr.glfwWindow, glfwGetTime());								// Red screen
//
//			/********************************************************************************************************/
//			glfwSwapBuffers(gwsr.glfwWindow);										// need !
//			glfwPollEvents();														// touch the window 'mouse-cursor'
//			/********************************************************************************************************/
//		}
//
//	}
//	
//	// So this [while loop] will keep the screen open & act as a sort of RENDERER inside place the shader .h inside to apply to the window -> check notes below !
	//*  -->The while loop runs its DEFINED on [gwsr.glfwWindow] ONLY. 
	//.  -->And every following associated shader Display function has to have 'their' associated window initialized to [gwsr.glfwWindow]
	//.	the reason GLFWVictorWindow isn't being called is because *window isn't set to anything, its gets made, 
	//. the the poll events cant find it because its no where , its only set in the scope of the function
	//. the GLFWVictorWindow is fixed -> by setting the window set in the functions to gswr.glfwWindow , 
	//. which is inside the VictorGL header , the poll events now has a object stored in the stack to access
	//. PERHAPS STORING A GLOBAL WINDOW , FROM WICH ALL CLASSES, CAN ACCESS SO TO AVOID CONFUSION ? i STILL THINK ITS ,
	//. GOOD TO HAVE SEPERATE WINDOWS FOR ALL SHADERS, AND THEN ONE MAIN ONE IF NEED BE TO ACCESS, SEPERATE FOR TESTING ?? */
	//while (!glfwWindowShouldClose(gwsr.glfwWindow))
	//{	
	//	shaderone.ShaderOneDisplay(gwsr.glfwWindow, glfwGetTime());				// Blue dot	--> ShaderOne
	//	//Vgl.Display(gwsr.glfwWindow , glfwGetTime());							// Red screen
	//
	//	/********************************************************************************************************/
	//	glfwSwapBuffers(gwsr.glfwWindow);										// need !
	//	glfwPollEvents();														// touch the window 'mouse-cursor'
	//	/********************************************************************************************************/
	//}
//
//	printf("Polling events Ends...: \n"); std::cout << glfwGetTime() << std::endl;

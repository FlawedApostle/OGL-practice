#define GLEW_STATIC
#define GLFW_INCLUDE_NONE

#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>

#include "stdio.h"
#include "stdlib.h"

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "VictorGL.h"
#include "ShaderOne.h"
#include "ShaderTwo.h"
#include "ShaderThree.h"
#include "ErrorHandles.h"
#include "Display.h"

/*SO yeah this is my GLSL && OpenGL Prog
  Its all for testing purposes ,
  neatness , orginization , simplicity 
  Are the main priority for thie Prog
  Enjoy !
  Author:: DeEpSpAcEnOmAd
  Notes.....
  ---> Eventually SDL will be added
  ---> Another File will be made with Glad as the header , CharlieGlad Class
  -----> CharlieGlad will load the new ver of OGL , and follow OGL Bible pdf doc		app. 9:45pm April 10 , 2024 <3
  */

VictorGL VictorGL_app;
VictorGL::glfwWinSurfRend GLFWWinSurfRend_app;
ShaderOne shader1;
ShaderTwo shader2;
ShaderThree shader3;
ErrorHandles errorhandles_app;
Display Display_app;
Display::Displays_ Displays_app;

/* these are test calls to prove any window can be made and created for shaders */ // --> works as of 11:19PM Apr 8 
GLFWwindow* testwindow;
GLFWwindow* testwindow2;

// lol imagine writing func that can take user input as string to then append to a newly made text ,
// and that text can then be used as a GLSL doc 'callable' if needed

/// Here we get the glfw version
/// glfw version && contexts are set
/// Window is created --> display_
/// Context is passed --> display_
/// Launching glew()
/// glfw swap intervals
/// Shader creations || Programs loading
/// Renderer (while loop)
/// Memory clean up , Window Destroy
/// Terminate , exit program

using namespace std;


/* initialize glfw , then glew ...Notes... Ensure steps are correctly followed, do not mess with functions ! */
void initialize_glfw()
{
	VictorGL_app.glfwinitLaunch();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
}
void initialize_glew()
{
	VictorGL_app.glewInitLaunch();
}

/* init Windows/Displays */
void initialize_windows()
{
	Display_app.DisplayWindows_CreateWindow(testwindow, 500, 700, "test_window");
	Display_app.DisplayWindows_context(testwindow);
}
/* init Shader programs */
void initialize_programsInit()
{
	shader1.ShaderOneInit(testwindow);		// initializing Shaders from shaderOne --> have to hard code.back() --> another way to access index ???? --> NOTE... calling 'testwindow' works as of 1:00PM APR 11 2024
	//shader2.ShaderTwoInit(testwindow);		// shader2.ShaderTwoInit(Display_app.GLFWwindows.back());
	//shader3.ShaderThreeInit(testwindow);		// shader3.ShaderThreeInit(Display_app.GLFWwindows.back());
}
/*Read Shader From Source ..Note.. this is necessary to use*/
void initialize_programsShadersSource()
{
	//shader3.readShaderSource("shaders/vertShader_sh3.glsl");
	//shader3.readShaderSource("shaders/fragShader_sh3.glsl");
}

void Render()
{
	Display_app.Display_ShoudlCloseWindow(testwindow);
	while (!glfwWindowShouldClose(testwindow = Display_app.GLFWwindows.back()))			// display_.GLFWwindows.back())
	{

		shader1.ShaderOneDisplay(Display_app.GLFWwindows.back(), glfwGetTime());			// ENSURE Shader(s) have been init in Prog_Creation FIRST !!!
		//shader2.ShaderTwoDisplay(testwindow, glfwGetTime());
		

		shader3.ShaderThreeDisplay(testwindow, glfwGetTime());
		
		//Display_app.DisplayWindows_Basic(testwindow, glfwGetTime());
		


		/********************************************************************************************************/
		glfwSwapBuffers(testwindow);										// need !
		glfwPollEvents();														// touch the window 'mouse-cursor'
		/********************************************************************************************************/
	}	errorhandles_app.Memaddress_window_notes(Display_app.GLFWwindows.back(), "AppApplication _ Renderer :: Current Display :: Mem Add :: ");


}

void Destroy()
{
	Display_app.DisplayWindows_DestroyWindows(testwindow);
}


int main()
{
/*
//std::ifstream Shader3;
//Shader3.open("shaders/Shader3.txt");
//if (Shader3.is_open())
//{
//	std::string Shader3_wrt;
//	while (Shader3)
//	{
//		Shader3_wrt = Shader3.get();
//		std::cout << Shader3_wrt << std::endl;
//	}
//}	Shader3.close();
char data[100];
//std::ofstream Shader3_app;
//Shader3_app.open("shaders/Shader3.txt");
//Shader3_app << "void main(void) \n"
//	"if(gl_VertexID == 0) gl_Position = vec4(0.25,-0.25,0.0,1.0); \n"
//	"else if(gl_VertexID == 1) gl_Position = vec4(-0.25,-0.25,0.0,1.0); \n"
//	"else gl_Position = vec4(0.25,0.25,0.0,1.0); \n"
//	"}";

std::ifstream Shader3;
Shader3.open("shaders/Shader3.txt");
if (Shader3.is_open())
{
	char Shader3_char;
	std::string Shader3_string;
	while (Shader3)
	{
		//Shader3_string = Shader3.get();
		Shader3_char = Shader3.get();
		std::cout << Shader3_char << " ";
	}
}
std::cout << std::endl;
*/
/*
	// files && streams --> reading glsl from text docs
	std::string readtestdoc_string;
	char	readtestdoc_char;
	std::fstream testdoc;
	//std::ifstream testdoc;
	//std::ofstream testdoc;
	testdoc.open("shaders/testdoc.txt");
	if (testdoc.is_open())
	{
		while (testdoc)
		{
			readtestdoc_char = testdoc.get();
			std::cout << readtestdoc_char;
		}
	}
	// create file newtext
	//std::ofstream newtext("shaders/newtext.txt");
	//newtext << "New text first line append  \n";
	//newtext << "newtext , line TWO append:  \n";
	//newtext << "newtext , line THREE append \n";
	//vector<std::string> appends{ "newtext , line FOUR append \n" , "newtext , line FIVE append \n" };
	//for (std::string app : appends)
	//{
	//	
	//	//cout << app << " ";
	//	newtext << app;
	//}
	// read file newtext
	//std::ifstream newtext;
	std::ifstream newtext_read;
	newtext_read.open("shaders/newtext.txt");
	if (newtext_read)
	{
		std::string textlines;
		while (newtext_read >> textlines)
		{
			std::cout << textlines << " ";
		}	newtext_read.close();
	}
*/
	
	//Display_app.ReadShaderSrc("prac/p1.txt" , "prac/p2.txt");
	/******************************************************************/

	VictorGL_app.glfwGetVer();
	///*												    GLFW ver **/
	std::cout << ".....Initializing glfw...." << std::endl;
	initialize_glfw();
	
	///*												    Context (Windows creation) **/
	std::cout << ".....Initializing Display Window...." << std::endl;
	initialize_windows();
	
	///*												    glew Launch  [(Key == Windows(true))] **/
	std::cout << ".....Initializing glew...." << std::endl;
	initialize_glew();


	/// AMEN WE DID IT !!!
	/// Create multiple WhileOn's [use them as call functions renderers]
	/// next , make the next shader
	/// to add the new winds header file window, you must go through every function to ensure its working. i yet dont know why its not
	//shader1.ShaderOneInit(glfwWinsurfrend.glfwWindow);
	//shader1.ShaderOneCreateProgram();
	//shader1.ShaderOneDisplay(glfwWinsurfrend.glfwWindow, glfwGetTime());

	
	///													** Swap Interval **/		
	glfwSwapInterval(1);

	
	///													** Prog Initialization **/
	std::cout << ".....Prog Initializing...." << std::endl;
	///---------->initialize_programsInit();

	//shader1.ShaderOneInit(Display_app.GLFWwindows.back());		// initializing Shaders from shaderOne --> have to hard code.back() --> another way to access index ???? 
	//shader3.ShaderThreeInit(Display_app.GLFWwindows.back());
	
	///													** Prog Shader Srouce **/
	std::cout << ".....Shader Source Initializing...." << std::endl;
	//initialize_programsShadersSource();

	//shader3.readShaderSource("shaders/vertShader_sh3.glsl");
	//shader3.readShaderSource("shaders/fragShader_sh3.glsl");

	
	
	///														** Render **/  **When Loading Shader(s) , ENSURE they are loaded prior (above) Prog_Creation
	//display_.Display_Renderer(testwindow); // don't use ! , for testing only ! :: [Display_Renderer] ... This is the () that calls the entire while loop
	/* I put this inside a function in display to call whichever window is made
	//glfwWindowShouldClose(testwindow); */
	std::cout << ".....Rendering...." << std::endl;
	///---------->Render();

	
	
	///														** Destroy **/
	std::cout << ".....Destroying...." << std::endl;
	Destroy();


	std::cout << ".....Your Gonna Carry That Weight....." << std::endl;
	glfwTerminate();
	exit(EXIT_SUCCESS);


	/*
	//display_.Display_Destroy(testwindow);
	//display_.Display1_Destroy();
	//victorgl.Destroy(testwindow);
	//victorgl.Destroy(displays_.Display1);
	//victorgl.Destroy(glfwWinsurfrend.glfwWindow);
	//victorgl.Destroy(glwWind.GLFWWind);
	*/


}


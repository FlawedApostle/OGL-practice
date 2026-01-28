#define GLEW_STATIC
#define GLFW_INCLUDE_NONE
//#include "GLAD/glad.h"
#include "stdio.h"
#include "stdlib.h"
#include <fstream>
#include <iostream>
#include <string>

#include "GLEW/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include "SOIL2/SOIL2.h"

#include "VictorGL.h"
#include "Display.h"
#include "shaderOne.h"
#include "shaderTwo.h"
#include "ErrorHandles.h"

#include <iostream>
#define numVAOs 1		// has to stay in cpp file

///*SHADER 1 CONSISTS OF PIXEL RENDERING CHANGING COL BASED ON LOCATION , SIZE*/

VictorGL VictorGL_sh1;
VictorGL::glfwWinSurfRend WinSurfRend_sh1;
ShaderTwo shadeTwo;
ErrorHandles errorhandles_sh1;
Display Display_sh1;
Display::Displays_ Displays_sh1;


///* New Declerations */
// has to stay in cpp file
GLuint renderingProgram_sh1;
GLuint vao[numVAOs];

/*called in header file instead */
//GLint vertCompiled;
//GLint fragComplied;
//GLint linked;

// | GL_SHADER_TYPE     returns Fragment, Vertex  -> what Shader type/obj is being queried
// | GL_COMPILE_STATUS  returns True || False     -> wether Shader obj have compiled correctly 
// | GL_DELETE_STATUS   returns True || False     -> wether obj is flagged for deletion
// | GL_INFO_LOG_LENGTH returns int               -> (max) size of buffer required
// | GL_SHADER_SOURCE_LENGTH returns size of concatenated strings in 'Shader' .txt doc(s) 


GLuint ShaderOne::ShaderOneCreateProgram()
{	
	///* Vertex Processing
	// Sends Vertex down the pipeline for Rasterization (pixel-ing the image into 'shape')
	// hardcoded a single point in the vertex shader {gl_position = vec4(0.0 ,0.0 ,0.0 ,1.0);}
	const char* vshaderSource =
		//"#version 430                                              \n"
		//"void main(void)                                     {     \n"
		//"if (gl_VertexID == 0)                                     \n"
		//"{gl_Position = vec4(0.25, -0.25, 0.0, 1.0);}              \n"
		//"else if (gl_VertexID == 1)                                \n"
		//"{gl_Position = vec4(-0.25, -0.25, 0.0, 1.0);}             \n"
		//"else gl_Position = vec4(0.25, 0.25, 0.0, 1.0);      }     \n";
		"#version 430    \n"
		"void main(void) \n"
		"{gl_Position = vec4(-0.5 ,0.0 , 0.0 ,1.0);}";	// X , Y , Z , W = 1.0f (POV) gl_Position --> Set pos of vertex(s) in 3D space using Vec4(x,y,z,w) [2D space is neg !] -> = - | <- = + |
	///* Fragment Shader [Rasterizing; Holds the location of vertex locations -> To 'shape' image] Fragment is to add color to the pixels]
	// Rasterizing the Vertex coords into fragments [from the pipeline (from above)] into pixels 'To shape the image' 
	const char* fshaderSource =
		"#version 430    \n"
		"out vec4 color; \n"	// "out" tag indicating that the variable color is an output , Not Necessary gl_Position is predefined as an output var
		"void main(void) \n"
		//"{color = vec4(0.0 ,0.0 ,1.0 ,1.0);}"; // Settings vert's to color pixels a.k.a fragments | [0.0,0.0,1.0,1.0] = blue | Forth val = Opacity level
		
		/// YOU LEFT HERE CHANING THE COLOR VIA PIXEL LOCATION -> CHECK INSIDE - ShaderOneDisplay() -> sizePoint() will change he size of the obj ther: utilizing color rasterization via pixel location !
		"{ if (gl_FragCoord.x < 200) color = "
		"vec4(1.0, 0.0, 0.0, 1.0); else color = "
		"vec4(0.0, 0.0, 1.0, 1.0);}";
	
	///* Generating Two empty Shader types (objects) -> 
	// An index ID (so code can call the shader obj later) is set (respectively) to each of the [GLuint vars] */
	GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
	
	// debug
	if (!glCreateShader)
	{
		errorhandles_sh1.OpenGlError_notes("glCreateShader_ShaderOne");
		errorhandles_sh1.printShaderLog(vShader);
		errorhandles_sh1.printShaderLog(fShader);
	}	errorhandles_sh1.Success("glCreateShader_vShader_&&_fShader");

	///* Load the Shader obj ID's 
	// Fills the empty [Shader objects] (made above) with their (respective) Shader string info  
	// Compile the Shader(s) [vShader , fShader] */
	glShaderSource(vShader, 1, &vshaderSource, NULL);
	glShaderSource(fShader, 1, &fshaderSource, NULL);
	glCompileShader(vShader);
	glCompileShader(fShader);

	// debug
	if (!glShaderSource)
	{
		errorhandles_sh1.OpenGlError_notes("glShaderSource_fShader_&&_vShader");
		errorhandles_sh1.OpenGlError_check();
	}	errorhandles_sh1.Success("glCompileShader_vShader");
		errorhandles_sh1.Success("glCompileShader_fShader");

	// Error handling ----> we here boi keep up ok double time the effort!!
	glGetShaderiv(vShader, GL_COMPILE_STATUS, &vertCompiled);
	if (vertCompiled != 1)
	{
		errorhandles_sh1.OpenGlError_check();
		std::cout << "Vertex_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh1.printShaderLog(vShader);
	}	errorhandles_sh1.Success("glGetShaderiv_vShader");

	glGetShaderiv(fShader, GL_COMPILE_STATUS, &fragComplied);
	if (fragComplied != 1)
	{
		errorhandles_sh1.OpenGlError_check();
		std::cout << "Fragment_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh1.printShaderLog(fShader);
	}	errorhandles_sh1.Success("glGetShaderiv_fShader");

	/* An ID is CREATED for vfProgram to launch shader objects */
	/// Create Prog , Attach Shader , Link Prog (with loaded shaders) -> Create & Run shader obj
	GLuint vfProgram = glCreateProgram();
	glAttachShader(vfProgram, vShader);
	glAttachShader(vfProgram, fShader);
	glLinkProgram(vfProgram);
	// debug
	glGetProgramiv(vfProgram, GL_LINK_STATUS, &linked);
	if (linked != 1)
	{
		errorhandles_sh1.OpenGlError_check();
		std::cout << "GL_Linking Program : Failed" << std::endl;
		errorhandles_sh1.printProgramLog(vfProgram);
	}	errorhandles_sh1.Success("glGetProgramiv : GL_LINK_STATUS");			//virtual func, can call it from any derived class 

	return vfProgram;
}


/// OpenGL requires min ONE VAO created IF shaders are being used , even if buffers aren't being used
// Think about turning a buffer array function -> to then hot load any 'renderingProgram(s)'
void ShaderOne::ShaderOneInit(GLFWwindow* ShaderOneWindow)
{
	Display_sh1.GLFWwindows.push_back(ShaderOneWindow);
		//dplay_.DisplayWindows_ReturnWindow();
		//dplay_.DisplayWindows_vecReturn();
		//dplay_.GLFWwindows.push_back(ShaderOneWindow);
		errorhandles_sh1.Memaddress_window_notes(ShaderOneWindow,"ShaderOneInit (.cpp)");
		if (!ShaderOneWindow)
		{
			errorhandles_sh1.GLFWError_notes("ShaderOneInit() :: Window_Check :: Error");
		}

		renderingProgram_sh1 = ShaderOneCreateProgram();
		// Vertex Array Buffers , This is how the data is stored in the pipeline to be accessed by GPU
		glGenVertexArrays(numVAOs, vao);			// creating Buffer vertex arr
		glBindVertexArray(vao[0]);					// calling the vertex buffer 'indices'
}


///                                                    * Shader Display
// Loads the compiled shaders into the GPU pipeline
void ShaderOne::ShaderOneDisplay(GLFWwindow* ShaderOneWindow, double currentTime)
{
	Display_sh1.GLFWwindows.push_back(ShaderOneWindow);
	ShaderOneWindow = Display_sh1.GLFWwindows.back();
	
	/// hack if the wind does close then display mem address and the cpp file location of ()
	//if (glfwWindowShouldClose(dplay_.GLFWwindows.front()))					//dplay_.GLFWwindows.back())
	//{
		//errorhandles_.Memaddress_window(dplay_.GLFWwindows.back(), "ShaderOneDisplay (.cpp)");	/// we are here , yes we finally did it all !! it works !
	//}
	
	
	/// Loads(only) (DOES NOT RUN) the compiled shaders into GPU pipeline
	glUseProgram(renderingProgram_sh1);
	glPointSize(225.0f);							// {color = vec4(0.0 ,0.0 ,1.0 ,1.0);} --> Edit'ing vertex buffer points 'size'

	// Draw Wire Mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Initiates pipeline processing
	// Primitive type GL_POINTS --> [one point to display]
	glDrawArrays(GL_POINTS, 0, 1);			//glDrawArrays(GL_POINTS, 0, 1)
	if (!glDrawArrays)
	{
		errorhandles_sh1.OpenGlError_notes("ShaderOneDisplay() :: glDrawArrays :: Error");
	}

	//std::cout << "Hello from DisplayV - ShaderOne" << std::endl;
	
}



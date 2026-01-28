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
#include "ShaderThree.h"
#include "ErrorHandles.h"

#include <iostream>
#define numVAOs_sh2 1		// has to stay in cpp file


///*SHADER 2 CONSISTS OF LOADING GLSL FILES FROM NOTEPAD*/

VictorGL VictorGL_sh2;
VictorGL::glfwWinSurfRend WinSurfRend_sh2;
ErrorHandles errorhandles_sh2;
Display Display_sh2;


///* New Declerations */
// has to stay in cpp file
GLuint renderingProgram_sh2;
GLuint vao_sh2[numVAOs_sh2];

/*called in header file instead */
GLint vertCompiled_sh2;
GLint fragComplied_sh2;
GLint linked_sh2;

// | GL_SHADER_TYPE     returns Fragment, Vertex  -> what Shader type/obj is being queried
// | GL_COMPILE_STATUS  returns True || False     -> wether Shader obj have compiled correctly 
// | GL_DELETE_STATUS   returns True || False     -> wether obj is flagged for deletion
// | GL_INFO_LOG_LENGTH returns int               -> (max) size of buffer required
// | GL_SHADER_SOURCE_LENGTH returns size of concatenated strings in 'Shader' .txt doc(s) 



// Create shader3
GLuint ShaderTwo::ShaderTwoCreateProgram()
{
	///* Vertex Processing
	// Sends Vertex down the pipeline for Rasterization (pixel-ing the image into 'shape')
	// hardcoded a single point in the vertex shader {gl_position = vec4(0.0 ,0.0 ,0.0 ,1.0);}
	//const char* vshaderSource3_sh3 =
	//	"#version 430                                              \n"
	//	"void main(void)                                     {     \n"
	//	"if (gl_VertexID == 0)                                     \n"
	//	"{gl_Position = vec4(0.25, -0.25, 0.0, 1.0);}              \n"
	//	"else if (gl_VertexID == 1)                                \n"
	//	"{gl_Position = vec4(-0.25, -0.25, 0.0, 1.0);}             \n"
	//	"else gl_Position = vec4(0.25, 0.25, 0.0, 1.0);      }     \n";
	//"#version 430    \n"
	//"void main(void) \n"
	//"{gl_Position = vec4(-0.5 ,0.0 , 0.0 ,1.0);}";	// X , Y , Z , W = 1.0f (POV) gl_Position --> Set pos of vertex(s) in 3D space using Vec4(x,y,z,w) [2D space is neg !] -> = - | <- = + |
///* Fragment Shader [Rasterizing; Holds the location of vertex locations -> To 'shape' image] Fragment is to add color to the pixels]
// Rasterizing the Vertex coords into fragments [from the pipeline (from above)] into pixels 'To shape the image' 
	//const char* fshaderSource3_sh3 =
	//	"#version 430    \n"
	//	"out vec4 color; \n"	// "out" tag indicating that the variable color is an output , Not Necessary gl_Position is predefined as an output var
	//	"void main(void) \n"
		//"{color = vec4(0.0 ,0.0 ,1.0 ,1.0);}"; // Settings vert's to color pixels a.k.a fragments | [0.0,0.0,1.0,1.0] = blue | Forth val = Opacity level

		/// YOU LEFT HERE CHANING THE COLOR VIA PIXEL LOCATION -> CHECK INSIDE - ShaderOneDisplay() -> sizePoint() will change he size of the obj ther: utilizing color rasterization via pixel location !
	//	"{ if (gl_FragCoord.x < 200) color = "
	//	"vec4(1.0, 0.0, 0.0, 1.0); else color = "
	//	"vec4(0.0, 0.0, 1.0, 1.0);}";

	///* Generating Two empty Shader types (objects) -> 
	// An index ID (so code can call the shader obj later) is set (respectively) to each of the [GLuint vars] */
	GLuint vShader_sh2 = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader_sh2 = glCreateShader(GL_FRAGMENT_SHADER);

	/// Turning fstream read files into std::string to be read into GLSL pipeline function , glShaderSource
	std::string vShaderStr_sh2 = Display_sh2.readShaderSources("shaders/vertShader_sh3.glsl");
	std::string fShaderStr_sh2 = Display_sh2.readShaderSources("shaders/fragShader_sh2.glsl");
	/// Turning the string into an array of char(s) for the glShaderSource input GLSL shaders
	const char* vShaderSrc_sh2 = vShaderStr_sh2.c_str();
	const char* fShaderSrc_sh2 = fShaderStr_sh2.c_str();

	// debug
	if (!glCreateShader)
	{
		errorhandles_sh2.OpenGlError_notes("glCreateShader_ShaderOne");
		errorhandles_sh2.printShaderLog(vShader_sh2);
		errorhandles_sh2.printShaderLog(fShader_sh2);
	}	errorhandles_sh2.Success("glCreateShader_vShader_&&_fShader");

	///* Load the Shader obj ID's 
	// Fills the empty [Shader objects] (made above) with their (respective) Shader string info  
	// Compile the Shader(s) [vShader , fShader] */
	//glShaderSource(vShader_sh3, 1, &vshaderSource3_sh3, NULL);
	//glShaderSource(fShader_sh3, 1, &fshaderSource3_sh3, NULL);

	// Loading String Shaders 
	glShaderSource(vShader_sh2, 1, &vShaderSrc_sh2, NULL);
	glShaderSource(fShader_sh2, 1, &fShaderSrc_sh2, NULL);
	glCompileShader(vShader_sh2);
	glCompileShader(fShader_sh2);

	// debug
	if (!glShaderSource)
	{
		errorhandles_sh2.OpenGlError_notes("glShaderSource_fShader_&&_vShader");
		errorhandles_sh2.OpenGlError_check();
	}	errorhandles_sh2.Success("glCompileShader_vShader");
		errorhandles_sh2.Success("glCompileShader_fShader");

	// Error handling ----> we here boi keep up ok double time the effort!!
	glGetShaderiv(vShader_sh2, GL_COMPILE_STATUS, &vertCompiled_sh2);
	if (vertCompiled_sh2 != 1)
	{
		errorhandles_sh2.OpenGlError_check();
		std::cout << "Vertex_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh2.printShaderLog(vShader_sh2);
		exit(EXIT_SUCCESS);
	}	errorhandles_sh2.Success("glGetShaderiv_vShader_sh2 Compile");

	glGetShaderiv(fShader_sh2, GL_COMPILE_STATUS, &fragComplied_sh2);
	if (fragComplied_sh2 != 1)
	{
		errorhandles_sh2.OpenGlError_check();
		std::cout << "Fragment_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh2.printShaderLog(fShader_sh2);
		exit(EXIT_SUCCESS);
	}	errorhandles_sh2.Success("glGetShaderiv_fShader_sh2 Compile");

	/* An ID is CREATED for vfProgram to launch shader objects */
	/// Create Prog , Attach Shader , Link Prog (with loaded shaders) -> Create & Run shader obj
	GLuint vfProgram_sh3 = glCreateProgram();
	glAttachShader(vfProgram_sh3, vShader_sh2);
	glAttachShader(vfProgram_sh3, fShader_sh2);
	glLinkProgram(vfProgram_sh3);
	// debug
	glGetProgramiv(vfProgram_sh3, GL_LINK_STATUS, &linked_sh2);
	if (linked_sh2 != 1)
	{
		errorhandles_sh2.OpenGlError_check();
		std::cout << "GL_Linking Program : Failed" << std::endl;
		errorhandles_sh2.printProgramLog(vfProgram_sh3);
	}	errorhandles_sh2.Success("glGetProgramiv : GL_LINK_STATUS");			//virtual func, can call it from any derived class 

	return vfProgram_sh3;
}


// Shader Display
// Loads the compiled shaders into the GPU pipeline
void ShaderTwo::ShaderTwoDisplay(GLFWwindow* ShaderOneWindow, double currentTime)
{
	Display_sh2.GLFWwindows.push_back(ShaderOneWindow);
	ShaderOneWindow = Display_sh2.GLFWwindows.back();

	/// hack if the wind does close then display mem address and the cpp file location of ()
	//if (glfwWindowShouldClose(dplay_.GLFWwindows.front()))					//dplay_.GLFWwindows.back())
	//{
		//errorhandles_.Memaddress_window(dplay_.GLFWwindows.back(), "ShaderOneDisplay (.cpp)");	/// we are here , yes we finally did it all !! it works !
	//}

	/// Loads(only) (DOES NOT RUN) the compiled shaders into GPU pipeline
	glUseProgram(renderingProgram_sh2);
	glPointSize(225.0f);							// {color = vec4(0.0 ,0.0 ,1.0 ,1.0);} --> Edit'ing vertex buffer points 'size'

	float x = 0.0f;
	float inc = 0.01f;
	x += inc;
	if (x > 1.0f)inc = -0.01f;
	if (x < 1.0f)inc =  0.01f;
	GLuint offsetLoc = glGetUniformLocation(renderingProgram_sh2, "offset");
	glProgramUniform1f(renderingProgram_sh2, offsetLoc, x);
	// Draw Wire Mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Initiates pipeline processing
	// Primitive type GL_POINTS --> [one point to display]
	glDrawArrays(GL_TRIANGLES, 0, 3);			//glDrawArrays(GL_POINTS, 0, 1)
	if (!glDrawArrays)
	{
		errorhandles_sh2.OpenGlError_notes("ShaderOneDisplay() :: glDrawArrays :: Error");
	}

	//std::cout << "Hello from DisplayV - ShaderOne" << std::endl;

}

// OpenGL requires min ONE VAO created IF shaders are being used , even if buffers aren't being used
// Think about turning a buffer array function -> to then hot load any 'renderingProgram(s)'
void ShaderTwo::ShaderTwoInit(GLFWwindow* ShaderOneWindow)
{
	Display_sh2.GLFWwindows.push_back(ShaderOneWindow);
	//dplay_.DisplayWindows_ReturnWindow();
	//dplay_.DisplayWindows_vecReturn();
	//dplay_.GLFWwindows.push_back(ShaderOneWindow);
	errorhandles_sh2.Memaddress_window_notes(ShaderOneWindow, "ShaderThreeInit()");
	if (!ShaderOneWindow)
	{
		errorhandles_sh2.GLFWError_notes("ShaderOneInit() :: Window_Check :: Error");
	}

	renderingProgram_sh2 = ShaderTwoCreateProgram();
	// Vertex Array Buffers , This is how the data is stored in the pipeline to be accessed by GPU
	glGenVertexArrays(numVAOs_sh2, vao_sh2);			// creating Buffer vertex arr
	glBindVertexArray(vao_sh2[0]);					// calling the vertex buffer 'indices'
}


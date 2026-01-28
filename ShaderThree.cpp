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
#include "ShaderThree.h"
#include "shaderOne.h"
#include "shaderTwo.h"
#include "ErrorHandles.h"

#include <iostream>
#define numVAOs_sh3 1		// has to stay in cpp file

VictorGL VictorGL_sh3;
VictorGL::glfwWinSurfRend WinSurfRend_sh3;
ErrorHandles errorhandles_sh3;
Display Display_sh3;


///* New Declerations */
// has to stay in cpp file
GLuint renderingProgram_sh3;
GLuint vao_sh3[numVAOs_sh3];

/*called in header file instead */
GLint vertCompiled_sh3;
GLint fragComplied_sh3;
GLint linked_sh3;

// | GL_SHADER_TYPE     returns Fragment, Vertex  -> what Shader type/obj is being queried
// | GL_COMPILE_STATUS  returns True || False     -> wether Shader obj have compiled correctly 
// | GL_DELETE_STATUS   returns True || False     -> wether obj is flagged for deletion
// | GL_INFO_LOG_LENGTH returns int               -> (max) size of buffer required
// | GL_SHADER_SOURCE_LENGTH returns size of concatenated strings in 'Shader' .txt doc(s) 

std::string ShaderThree::readShaderSource(const char* filePath)
{
	std::string content;
	std::ifstream fileStream(filePath , std::ios::in);
	std::string line = "";
	while (!fileStream.eof())
	{
		getline(fileStream, line);
		content.append(line + "\n");
		std::cout << content << std::endl;
	}
	
	return content;
}

// Create shader3
GLuint ShaderThree::ShaderThreeCreateProgram()
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
	GLuint vShader_sh3 = glCreateShader(GL_VERTEX_SHADER);
	GLuint fShader_sh3 = glCreateShader(GL_FRAGMENT_SHADER);

	std::string vShaderStr_sh3 = readShaderSource("shaders/vertShader_sh3.glsl");
	std::string fShaderStr_sh3 = readShaderSource("shaders/fragShader_sh3.glsl");
	
	const char* vShaderSrc_sh3 = vShaderStr_sh3.c_str();
	const char* fShaderSrc_sh3 = fShaderStr_sh3.c_str();
	


	// debug
	if (!glCreateShader)
	{
		errorhandles_sh3.OpenGlError_notes("glCreateShader_ShaderOne");
		errorhandles_sh3.printShaderLog(vShader_sh3);
		errorhandles_sh3.printShaderLog(fShader_sh3);
	}	errorhandles_sh3.Success("glCreateShader_vShader_&&_fShader");

	///* Load the Shader obj ID's 
	// Fills the empty [Shader objects] (made above) with their (respective) Shader string info  
	// Compile the Shader(s) [vShader , fShader] */
	//glShaderSource(vShader_sh3, 1, &vshaderSource3_sh3, NULL);
	//glShaderSource(fShader_sh3, 1, &fshaderSource3_sh3, NULL);
	
	// Loading String Shaders 
	glShaderSource(vShader_sh3, 1, &vShaderSrc_sh3, NULL);
	glShaderSource(fShader_sh3, 1, &fShaderSrc_sh3, NULL);
	glCompileShader(vShader_sh3);			  
	glCompileShader(fShader_sh3);

	// debug
	if (!glShaderSource)
	{
		errorhandles_sh3.OpenGlError_notes("glShaderSource_fShader_&&_vShader");
		errorhandles_sh3.OpenGlError_check();
	}	errorhandles_sh3.Success("glCompileShader_vShader");
		errorhandles_sh3.Success("glCompileShader_fShader");

	// Error handling ----> we here boi keep up ok double time the effort!!
	glGetShaderiv(vShader_sh3, GL_COMPILE_STATUS, &vertCompiled_sh3);
	if (vertCompiled_sh3 != 1)
	{
		errorhandles_sh3.OpenGlError_check();
		std::cout << "Vertex_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh3.printShaderLog(vShader_sh3);
		exit(EXIT_SUCCESS);
	}	errorhandles_sh3.Success("glGetShaderiv_vShader_sh3 Compile");

	glGetShaderiv(fShader_sh3, GL_COMPILE_STATUS, &fragComplied_sh3);
	if (fragComplied_sh3 != 1)
	{
		errorhandles_sh3.OpenGlError_check();
		std::cout << "Fragment_Shader_Compile_Status :: Failed " << std::endl;
		errorhandles_sh3.printShaderLog(fShader_sh3);
		exit(EXIT_SUCCESS);
	}	errorhandles_sh3.Success("glGetShaderiv_fShader_sh3 Compile");

	/* An ID is CREATED for vfProgram to launch shader objects */
	/// Create Prog , Attach Shader , Link Prog (with loaded shaders) -> Create & Run shader obj
	GLuint vfProgram_sh3 = glCreateProgram();
	glAttachShader(vfProgram_sh3, vShader_sh3);
	glAttachShader(vfProgram_sh3, fShader_sh3);
	glLinkProgram(vfProgram_sh3);
	// debug
	glGetProgramiv(vfProgram_sh3, GL_LINK_STATUS, &linked_sh3);
	if (linked_sh3 != 1)
	{
		errorhandles_sh3.OpenGlError_check();
		std::cout << "GL_Linking Program : Failed" << std::endl;
		errorhandles_sh3.printProgramLog(vfProgram_sh3);
	}	errorhandles_sh3.Success("glGetProgramiv : GL_LINK_STATUS");			//virtual func, can call it from any derived class 

	return vfProgram_sh3;
}


// Shader Display
// Loads the compiled shaders into the GPU pipeline
void ShaderThree::ShaderThreeDisplay(GLFWwindow* ShaderOneWindow, double currentTime)
{
	Display_sh3.GLFWwindows.push_back(ShaderOneWindow);
	ShaderOneWindow = Display_sh3.GLFWwindows.back();

	/// hack if the wind does close then display mem address and the cpp file location of ()
	//if (glfwWindowShouldClose(dplay_.GLFWwindows.front()))					//dplay_.GLFWwindows.back())
	//{
		//errorhandles_.Memaddress_window(dplay_.GLFWwindows.back(), "ShaderOneDisplay (.cpp)");	/// we are here , yes we finally did it all !! it works !
	//}


	/// Loads(only) (DOES NOT RUN) the compiled shaders into GPU pipeline
	glUseProgram(renderingProgram_sh3);
	glPointSize(225.0f);							// {color = vec4(0.0 ,0.0 ,1.0 ,1.0);} --> Edit'ing vertex buffer points 'size'


	// Draw Wire Mode
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Initiates pipeline processing
	// Primitive type GL_POINTS --> [one point to display]
	glDrawArrays(GL_TRIANGLES, 0, 3);			//glDrawArrays(GL_POINTS, 0, 1)
	if (!glDrawArrays)
	{
		errorhandles_sh3.OpenGlError_notes("ShaderOneDisplay() :: glDrawArrays :: Error");
	}

	//std::cout << "Hello from DisplayV - ShaderOne" << std::endl;

}

// OpenGL requires min ONE VAO created IF shaders are being used , even if buffers aren't being used
// Think about turning a buffer array function -> to then hot load any 'renderingProgram(s)'
void ShaderThree::ShaderThreeInit(GLFWwindow* ShaderOneWindow)
{
	Display_sh3.GLFWwindows.push_back(ShaderOneWindow);
	//dplay_.DisplayWindows_ReturnWindow();
	//dplay_.DisplayWindows_vecReturn();
	//dplay_.GLFWwindows.push_back(ShaderOneWindow);
	errorhandles_sh3.Memaddress_window_notes(ShaderOneWindow, "ShaderThreeInit()");
	if (!ShaderOneWindow)
	{
		errorhandles_sh3.GLFWError_notes("ShaderOneInit() :: Window_Check :: Error");
	}

	renderingProgram_sh3 = ShaderThreeCreateProgram();
	// Vertex Array Buffers , This is how the data is stored in the pipeline to be accessed by GPU
	glGenVertexArrays(numVAOs_sh3, vao_sh3);			// creating Buffer vertex arr
	glBindVertexArray(vao_sh3[0]);					// calling the vertex buffer 'indices'
}


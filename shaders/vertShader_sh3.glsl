//version 4.30
void main(void)                                     {     
if (gl_VertexID == 0)                                     
{gl_Position = vec4(0.25, -0.25, 0.0, 1.0);}              
else if (gl_VertexID == 1)                                
{gl_Position = vec4(-0.25, -0.25, 0.0, 1.0);}             
else gl_Position = vec4(0.25, 0.25, 0.0, 1.0);      };

// By Def VertexID is a pipline object 
// Calling its index will let us draw specific vertex(s) in order
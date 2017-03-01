#include "sogl.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <iostream>

void GLAPIENTRY glDebugOutput(GLenum source, 
                            GLenum type, 
                            GLuint id, 
                            GLenum severity, 
                            GLsizei length, 
                            const GLchar *message, 
                            const void *userParam)
{
    // ignore non-significant error/warning codes
    if(id == 131169 || id == 131185 || id == 131218 || id == 131204) return; 

    std::cout << "---------------" << std::endl;
    std::cout << "Debug message (" << id << "): " <<  message << std::endl;

    switch (source)
    {
        case GL_DEBUG_SOURCE_API:             std::cout << "Source: API"; break;
        case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   std::cout << "Source: Window System"; break;
        case GL_DEBUG_SOURCE_SHADER_COMPILER: std::cout << "Source: Shader Compiler"; break;
        case GL_DEBUG_SOURCE_THIRD_PARTY:     std::cout << "Source: Third Party"; break;
        case GL_DEBUG_SOURCE_APPLICATION:     std::cout << "Source: Application"; break;
        case GL_DEBUG_SOURCE_OTHER:           std::cout << "Source: Other"; break;
    } std::cout << std::endl;

    switch (type)
    {
        case GL_DEBUG_TYPE_ERROR:               std::cout << "Type: Error"; break;
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: std::cout << "Type: Deprecated Behaviour"; break;
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:  std::cout << "Type: Undefined Behaviour"; break; 
        case GL_DEBUG_TYPE_PORTABILITY:         std::cout << "Type: Portability"; break;
        case GL_DEBUG_TYPE_PERFORMANCE:         std::cout << "Type: Performance"; break;
        case GL_DEBUG_TYPE_MARKER:              std::cout << "Type: Marker"; break;
        case GL_DEBUG_TYPE_PUSH_GROUP:          std::cout << "Type: Push Group"; break;
        case GL_DEBUG_TYPE_POP_GROUP:           std::cout << "Type: Pop Group"; break;
        case GL_DEBUG_TYPE_OTHER:               std::cout << "Type: Other"; break;
    } std::cout << std::endl;
    
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:         std::cout << "Severity: high"; break;
        case GL_DEBUG_SEVERITY_MEDIUM:       std::cout << "Severity: medium"; break;
        case GL_DEBUG_SEVERITY_LOW:          std::cout << "Severity: low"; break;
        case GL_DEBUG_SEVERITY_NOTIFICATION: std::cout << "Severity: notification"; break;
    } std::cout << std::endl;
    std::cout << std::endl;
}

int main(void)
{
	SOGL::Context context(32, 8, 4, 4, 0);

	glEnable(GL_DEBUG_OUTPUT); 
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS); 
    glDebugMessageCallback(glDebugOutput, nullptr);
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
	
	SOGL::Texture tex("ses.png");

	glfwSetWindowSize(context, 640, 640);
	glfwShowWindow(context);
	glViewport(0, 0, 640, 640);

	float verts[] =
	{
		-1,  1, 0, 0, 1,
		 1,  1, 0, 1, 1,
		 1, -1, 0, 1, 0,
		-1, -1, 0, 0, 0
	};

	unsigned indices[] =
	{
		0, 1, 2, 0, 2, 3
	};

	SOGL::VertexBuffer vbo;
	vbo.allocate(verts, 20 * sizeof(float));

	SOGL::VertexBuffer ebo;
	ebo.allocate(indices, 6 * sizeof(unsigned));

	SOGL::VertexArray vao;
	vao.attach_attribute(0, 5 * sizeof(float), vbo, 3, 0);
	vao.attach_attribute(1, 5 * sizeof(float), vbo, 2, 3 * sizeof(float));
	vao.attach_ebo(ebo);

	const char vert_src[] = GLSL
	(
		400,
		layout(location = 0) in vec3 position;
		layout(location = 1) in vec2 uv;

		out vec2 v_uv;

		void main()
		{
			gl_Position = vec4(position, 1);
			v_uv = uv;
		}
	);
	
	const char frag_src[] = GLSL
	(
		400,
		in vec2 v_uv;
		out vec3 color;

		layout(binding = 0) uniform sampler2D tex;

		void main()
		{
			color = texture(tex, v_uv).rgb;
		}
	);

	SOGL::ShaderProgram prog;
	{
		SOGL::VertexShader vert(vert_src);
		SOGL::FragmentShader frag(frag_src);
		prog.attach(vert);
		prog.attach(frag);
		prog.link();
	}


	while(!glfwWindowShouldClose(context))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		prog.bind();
		vao.bind();
		tex.bind(0);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

		glfwPollEvents();
		glfwSwapBuffers(context);
	}

	glfwTerminate();
    return 0;
}
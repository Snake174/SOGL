#include <context.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>
#include <iostream>

namespace SOGL
{
	static void APIENTRY debug_output(GLenum source, 
                            GLenum type, 
                            GLuint id, 
                            GLenum severity, 
                            GLsizei length, 
                            const GLchar *message, 
                            const void *userParam)
{
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

	ContextSettings::ContextSettings(unsigned depth, unsigned stencil, unsigned antialiasing, 
									 unsigned major, unsigned minor):
		depth_bits(depth), stencil_bits(stencil), antialiasing_level(antialiasing),
		major_version(major), minor_version(minor)
	{}

	Context::Context(const ContextSettings& settings)
	{
		assert(glfwInit());
		
		static int at_exit = -1;

		if(at_exit != 0)
			at_exit = std::atexit([] { glfwTerminate(); });

		set_settings(settings);
		assert(m_handle = glfwCreateWindow(1, 1, "", nullptr, nullptr));
		bind();

		glewExperimental = true;
		assert(glewInit() == GLEW_OK);
	
		set_enabled(Capability::DepthTest);
		set_enabled(Capability::DebugOutput);
		set_enabled(Capability::DebugOutputSynchronous);

		glDebugMessageCallback(debug_output, this);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, nullptr, GL_FALSE);
	}

	Context::Context(unsigned depth, unsigned stencil, unsigned antialiasing, 
					 unsigned major, unsigned minor) :
		Context(ContextSettings(depth, stencil, antialiasing, major, minor))
	{}

	Context::~Context()
	{
		glfwDestroyWindow(m_handle);
	}

	Context::Context(Context&& o)
	{
		m_handle = o.m_handle;
		o.m_handle = 0;
	}

	Context::Context(Context& o)
	{
		set_settings(o.settings());

		assert(m_handle = glfwCreateWindow(1, 1, "", nullptr, o.m_handle));
		bind();

		glewExperimental = true;
		assert(glewInit() == GLEW_OK);
	}

	const ContextSettings& Context::settings()
	{
		return m_settings;
	}

	void Context::set_enabled(const Capability& capability, bool enable)
	{
		if(enable)
			glEnable(remap(capability));
		else
			glDisable(remap(capability));
	}

	bool Context::is_enabled(const Capability& capability)
	{
		return glIsEnabled(remap(capability));
	}

	bool Context::is_disabled(const Capability & capability)
	{
		return !is_enabled(capability);
	}

	void Context::draw_arrays(const PrimitiveType& mode, int first, int count)
	{
		glDrawArrays(remap(mode), first, count);
	}

	void Context::bind()
	{
		glfwMakeContextCurrent(m_handle);
	}

	void Context::unbind()
	{
		glfwMakeContextCurrent(nullptr);
	}

	bool Context::is_active()
	{
		return glfwGetCurrentContext() == m_handle;
	}

	void Context::set_settings(const ContextSettings& settings)
	{
		m_settings = settings;

		glfwWindowHint(GLFW_VISIBLE, false);
		glfwWindowHint(GLFW_RESIZABLE, false);
		glfwWindowHint(GLFW_DEPTH_BITS, m_settings.depth_bits);
		glfwWindowHint(GLFW_STENCIL_BITS, m_settings.stencil_bits);
		glfwWindowHint(GLFW_SAMPLES, m_settings.antialiasing_level);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_settings.major_version);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_settings.minor_version);
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
};

#include <context.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>

namespace SOGL
{
	ContextSettings::ContextSettings(unsigned depth, unsigned stencil, unsigned antialiasing, 
									 unsigned major, unsigned minor):
		depth_bits(depth), stencil_bits(stencil), antialiasing_level(antialiasing),
		major_version(major), minor_version(minor)
	{}

	Context::Context(const ContextSettings& settings)
	{
		assert(glfwInit());

		set_settings(settings);
		assert(m_handle = glfwCreateWindow(1, 1, "", nullptr, nullptr));
		bind();

		glewExperimental = true;
		assert(glewInit() == GLEW_OK);
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

	Context::operator GLFWwindow*()
	{
		return m_handle;
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

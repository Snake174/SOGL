#include "../include/window.h"
#include <cassert>
#include <GLFW/glfw3.h>

namespace SOGL
{
	Window::Window(int width, int height, const char* title,
				   const ContextSettings & settings): m_context(settings)
	{
		assert(width > 0);
		assert(height > 0);


		glfwSetWindowSize(m_context.m_handle, width, height);
		glfwSetWindowTitle(m_context.m_handle, title);
		glfwSetWindowUserPointer(m_context.m_handle, this);
		glfwSetKeyCallback(m_context.m_handle, key_callback);
		glfwSetScrollCallback(m_context.m_handle, scroll_callback);
		glfwSetMouseButtonCallback(m_context.m_handle, mouse_button_callback);

		auto fb_size = framebuffer_size();
		glViewport(0, 0, fb_size.x, fb_size.y);

		glfwShowWindow(m_context.m_handle);
	}

	bool Window::key(const Key& key)
	{
		return m_keys[unsigned(key)];
	}

	glm::vec2 Window::mouse_position()
	{
		double x, y;
		glfwGetCursorPos(m_context.m_handle, &x, &y);
		return glm::vec2((float)x, (float)y);
	}

	glm::vec2 Window::scroll()
	{
		return m_scroll;
	}

	bool Window::mouse_button(const MouseButton& button)
	{
		return m_mouse_buttons[unsigned(button)];
	}

	glm::ivec2 Window::framebuffer_size()
	{
		glm::ivec2 size;
		glfwGetFramebufferSize(m_context.m_handle, (int*)&size[0], (int*)&size[1]);
		return size;
	}

	void Window::set_clear_color(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void Window::set_should_close(bool value)
	{
		glfwSetWindowShouldClose(m_context.m_handle, value);
	}

	glm::vec4 Window::clear_color()
	{
		glm::vec4 color;
		glGetFloatv(GL_COLOR_CLEAR_VALUE, (float*)&color[0]);
		return color;
	}

	void Window::bind()
	{
		m_context.bind();
	}

	void Window::unbind()
	{
		m_context.unbind();
	}

	bool Window::should_close()
	{
		return !!glfwWindowShouldClose(m_context.m_handle);
	}

	void Window::update()
	{
		glfwPollEvents();
	}

	void Window::swap_buffers()
	{
		glfwSwapBuffers(m_context.m_handle);
	}

	void Window::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //| GL_STENCIL_BUFFER_BIT);
	}

	Context& Window::context()
	{
		return m_context;
	}

	void Window::scroll_callback(GLFWwindow * window, double x_offset, double y_offset)
	{
		SOGL::Window* w = (SOGL::Window*)glfwGetWindowUserPointer(window);

		w->m_scroll = glm::vec2
		(
			glm::clamp((float)x_offset, -1.0f, 1.0f),
			glm::clamp((float)y_offset, -1.0f, 1.0f)
		);
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		SOGL::Window* w = (SOGL::Window*)glfwGetWindowUserPointer(window);

		w->m_keys[key] = (action != GLFW_RELEASE);
	}

	void Window::mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
	{
		SOGL::Window* w = (SOGL::Window*)glfwGetWindowUserPointer(window);

		w->m_mouse_buttons[button] = (action != GLFW_RELEASE);
	}
};
#pragma once
#include <glm.hpp>
#include "context.h"
#include "enums/key_type.h"
#include "enums/mouse_button.h"

namespace SOGL
{
	class Window
	{
	public:
		Window
		(
			int width, int height, const char* title = "Window",
			const ContextSettings& settings = ContextSettings(24, 0, 4, 4, 0)
		);

		bool key(const Key& key);

		glm::vec2 mouse_position();

		glm::vec2 scroll();

		bool mouse_button(const MouseButton& button);

		glm::ivec2 framebuffer_size();

		void set_clear_color(const glm::vec4& color);

		void set_should_close(bool value);

		glm::vec4 clear_color();

		void bind();

		void unbind();

		bool should_close();

		void update();

		void swap_buffers();

		void clear();

		Context& context();
	private:
		static void scroll_callback(GLFWwindow* window, double x_offset, double y_offset);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

		Context m_context;
		glm::vec2 m_scroll;
		bool m_keys[unsigned(Key::LastKey)]{};
		bool m_mouse_buttons[unsigned(MouseButton::LastButton)]{};
	};
};
#pragma once
#include "enums/primitive_type.h"
#include "enums/capability.h"

typedef struct GLFWwindow GLFWwindow; //"YUCK!", yeah..

namespace SOGL
{
	struct ContextSettings
	{
		ContextSettings
		(
			unsigned depth = 0,
			unsigned stencil = 0,
			unsigned antialiasing = 0, 
			unsigned major = 4,
			unsigned minor = 0
		);

		unsigned depth_bits;
		unsigned stencil_bits;
		unsigned antialiasing_level;
		unsigned major_version;
		unsigned minor_version;
	};

	class Context
	{
	public:
		Context(const ContextSettings& settings = ContextSettings());
		
		Context(unsigned depth, unsigned stencil, unsigned antialiasing, unsigned major, unsigned minor);
		
		~Context();

		Context(Context&&);

		//make shared context
		Context(Context&);

		const ContextSettings& settings();

		void enable(const Capability& capability);

		void disable(const Capability& capability);

		bool is_enabled(const Capability& capability);

		bool is_disabled(const Capability& capability);

		void draw_arrays(const PrimitiveType& mode, int first, int count);

		void bind();

		void unbind();

		bool is_active();
	private:
		void set_settings(const ContextSettings& settings);

		GLFWwindow* m_handle;
		ContextSettings m_settings;

		friend class Window;
	};
};
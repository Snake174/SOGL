#pragma once
#include "shader.h"
#include <glm.hpp>

namespace SOGL
{
	class ShaderProgram
	{
	public:
		ShaderProgram();

		~ShaderProgram();

		ShaderProgram(ShaderProgram&&);

		ShaderProgram(ShaderProgram&) = delete;

		void set_uniform(const char* name, float v);

		void set_uniform(const char* name, int v);

		void set_uniform(const char* name, glm::mat4 v);

		void attach(Shader& shader);

		bool link();

		void bind();

		void unbind();

		unsigned id();

		operator unsigned();
	private:
		unsigned m_id;
	};
};
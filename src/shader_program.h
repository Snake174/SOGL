#pragma once
#include "shader.h"

namespace SOGL
{
	class ShaderProgram
	{
	public:
		ShaderProgram();

		~ShaderProgram();

		ShaderProgram(ShaderProgram&&);

		ShaderProgram(ShaderProgram&) = delete;

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
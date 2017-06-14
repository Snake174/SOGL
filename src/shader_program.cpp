#include "shader_program.h"
#include <GL/glew.h>
#include <iostream>

namespace SOGL
{
	ShaderProgram::ShaderProgram()
	{
		m_id = glCreateProgram();
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_id);
	}

	ShaderProgram::ShaderProgram(ShaderProgram&& o)
	{
		m_id = o.m_id;

		o.m_id = 0;
	}

	void ShaderProgram::set_uniform(const char* name, float v)
	{
		auto loc = glGetUniformLocation(*this, name);
		glUniform1f(loc, v);
	}

	void ShaderProgram::set_uniform(const char* name, int v)
	{
		auto loc = glGetUniformLocation(*this, name);
		glUniform1i(loc, v);
	}

	void ShaderProgram::set_uniform(const char* name, glm::mat4 v)
	{
		auto loc = glGetUniformLocation(*this, name);
		glUniformMatrix4fv(loc, 1, GL_FALSE, &v[0][0]);
	}

	void ShaderProgram::attach(Shader& shader)
	{
		glAttachShader(m_id, shader);
	}

	bool ShaderProgram::link()
	{
		int success;
		const unsigned log_length = 1024;
		static GLchar log[log_length];

		glLinkProgram(m_id);
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if(!success)
		{
			glGetProgramInfoLog(m_id, log_length, nullptr, log);
			std::cerr << "SHADER PROGRAM LINKING ERROR\n" << log << std::endl;
			return false;
		}

		return true;
	}

	void ShaderProgram::bind()
	{
		glUseProgram(m_id);
	}

	void ShaderProgram::unbind()
	{
		glUseProgram(0);
	}

	unsigned ShaderProgram::id()
	{
		return m_id;
	}

	ShaderProgram::operator unsigned()
	{
		return id();
	}
};
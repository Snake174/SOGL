#include "shader.h"
#include <GL/glew.h>
#include <iostream>

namespace SOGL
{
	Shader::Shader(ShaderType type, const char* source): m_type(type)
	{
		m_id = glCreateShader(remap(type));

		glShaderSource(m_id, 1, &source, 0);
		glCompileShader(m_id);
		
		GLint success;
		const unsigned log_length = 1024;
		static GLchar log[log_length];
		glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
		if(!success)
		{
			glGetShaderInfoLog(m_id, log_length, nullptr, log);
			std::cerr << "SHADER COMPILATION ERROR\n" << log << std::endl;
		}
	}

	Shader::~Shader()
	{
		glDeleteShader(m_id);
	}

	Shader::Shader(Shader&& o)
	{
		m_id = o.m_id;
		m_type = o.m_type;

		m_id = 0;
	}

	ShaderType Shader::type()
	{
		return m_type;
	}

	VertexShader::VertexShader(const char* source): 
		Shader(ShaderType::Vertex, source)
	{}

	TessControlShader::TessControlShader(const char* source): 
		Shader(ShaderType::TesselationControl, source)
	{}

	TessEvaluationShader::TessEvaluationShader(const char* source): 
		Shader(ShaderType::TesselationEvaluation, source)
	{}

	GeometryShader::GeometryShader(const char* source):
		Shader(ShaderType::Geometry, source)
	{}

	FragmentShader::FragmentShader(const char* source): 
		Shader(ShaderType::Fragment, source)
	{}

	ComputeShader::ComputeShader(const char* source): 
		Shader(ShaderType::Compute, source)
	{}
}
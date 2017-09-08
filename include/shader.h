#pragma once
#include "enums/shader_type.h"

namespace SOGL
{
	class Shader
	{
	public:
		Shader(ShaderType type, const char* source);

		~Shader();

		Shader(Shader&&);

		Shader(Shader&) = delete;

		ShaderType type();
	private:
		unsigned m_id;
		ShaderType m_type;

		friend class ShaderProgram;
	};

	class VertexShader: public Shader
	{
	public:
		VertexShader(const char* source);
	};

	class TessControlShader: public Shader
	{
	public:
		TessControlShader(const char* source);
	};

	class TessEvaluationShader: public Shader
	{
	public:
		TessEvaluationShader(const char* source);
	};

	class GeometryShader: public Shader
	{
	public:
		GeometryShader(const char* source);
	};

	class FragmentShader: public Shader
	{
	public:
		FragmentShader(const char* source);
	};

	class ComputeShader: public Shader
	{
	public:
		ComputeShader(const char* source);
	};
};
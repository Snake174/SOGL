#include <enums/shader_type.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const ShaderType type)
	{
		switch(type)
		{
			case ShaderType::Vertex: return GL_VERTEX_SHADER;
			case ShaderType::TesselationControl: return GL_TESS_CONTROL_SHADER;
			case ShaderType::TesselationEvaluation: return GL_TESS_EVALUATION_SHADER;
			case ShaderType::Geometry: return GL_GEOMETRY_SHADER;
			case ShaderType::Fragment: return GL_FRAGMENT_SHADER;
			case ShaderType::Compute: return GL_COMPUTE_SHADER;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
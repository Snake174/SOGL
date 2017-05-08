#pragma once

namespace SOGL
{
	enum class ShaderType
	{
		Vertex,
		TesselationControl,
		TesselationEvaluation,
		Geometry,
		Fragment,
		Compute
	};

	unsigned remap(const ShaderType& type);
};
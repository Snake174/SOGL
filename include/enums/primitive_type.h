#pragma once

namespace SOGL
{
	enum class PrimitiveType
	{
		Points, 
		LineStrip,
		LineLoop,
		Lines, 
		LineStripAdjacency, 
		LinesAdjacency,
		TriangleStrip,
		TriangleFan, 
		Triangles, 
		TriangleStripAdjacency, 
		TrianglesAdjacency,
		Patches
	};
	
	unsigned remap(const PrimitiveType& target);
};
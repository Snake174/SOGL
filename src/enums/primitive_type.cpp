#include "../include/enums/primitive_type.h"
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const PrimitiveType& format)
	{
		switch(format)
		{
			case PrimitiveType::Points: return GL_POINTS;
			case PrimitiveType::LineStrip: return GL_LINE_STRIP;
			case PrimitiveType::LineLoop: return GL_LINE_LOOP;
			case PrimitiveType::Lines: return GL_LINES;
			case PrimitiveType::LineStripAdjacency: return GL_LINE_STRIP_ADJACENCY;
			case PrimitiveType::LinesAdjacency: return GL_LINES_ADJACENCY;
			case PrimitiveType::TriangleStrip: return GL_TRIANGLE_STRIP;
			case PrimitiveType::TriangleFan: return GL_TRIANGLE_FAN;
			case PrimitiveType::Triangles: return GL_TRIANGLES;
			case PrimitiveType::TriangleStripAdjacency: return GL_TRIANGLE_STRIP_ADJACENCY;
			case PrimitiveType::TrianglesAdjacency: return GL_TRIANGLES_ADJACENCY;
			case PrimitiveType::Patches: return GL_PATCHES;
		default:
			assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
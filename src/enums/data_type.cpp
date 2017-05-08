#include <enums/data_type.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const DataType& type)
	{
		switch(type)
		{
			case DataType::Byte: return GL_BYTE;
			case DataType::UnsignedByte: return GL_UNSIGNED_BYTE;
			case DataType::Short: return GL_SHORT;
			case DataType::UnsignedShort: return GL_UNSIGNED_SHORT;
			case DataType::Int: return GL_INT;
			case DataType::UnsignedInt: return GL_UNSIGNED_INT;
			case DataType::Fixed: return GL_FIXED;
			case DataType::HalfFloat: return GL_HALF_FLOAT;
			case DataType::Float: return GL_FLOAT;
			case DataType::Double: return GL_DOUBLE;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
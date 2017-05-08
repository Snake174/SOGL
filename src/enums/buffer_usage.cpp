#include <enums/buffer_usage.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const BufferUsage& usage)
	{
		switch(usage)
		{
			case BufferUsage::StreamDraw: return GL_STREAM_DRAW;
			case BufferUsage::StreamRead: return GL_STREAM_READ;
			case BufferUsage::StreamCopy: return GL_STREAM_COPY;
			case BufferUsage::StaticDraw: return GL_STATIC_DRAW;
			case BufferUsage::StaticRead: return GL_STATIC_READ;
			case BufferUsage::StaticCopy: return GL_STATIC_COPY;
			case BufferUsage::DynamicDraw: return GL_DYNAMIC_DRAW;
			case BufferUsage::DynamicRead: return GL_DYNAMIC_READ;
			case BufferUsage::DynamicCopy: return GL_DYNAMIC_COPY;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
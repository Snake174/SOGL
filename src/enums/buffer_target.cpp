#include <enums/buffer_target.h>
#include <GL/glew.h>
#include <cassert>

namespace SOGL
{
	unsigned SOGL::remap(const BufferTarget& target)
	{
		switch(target)
		{
			case BufferTarget::Array: return GL_ARRAY_BUFFER;
			case BufferTarget::AtomicCounter: return GL_ATOMIC_COUNTER_BUFFER;
			case BufferTarget::CopyRead: return GL_COPY_READ_BUFFER;
			case BufferTarget::CopyWrite: return GL_COPY_WRITE_BUFFER;
			case BufferTarget::DispatchIndirect: return GL_DISPATCH_INDIRECT_BUFFER;
			case BufferTarget::DrawIndirect: return GL_DRAW_INDIRECT_BUFFER;
			case BufferTarget::ElementArray: return GL_ELEMENT_ARRAY_BUFFER;
			case BufferTarget::PixelPack: return GL_PIXEL_PACK_BUFFER;
			case BufferTarget::PixelUnpack: return GL_PIXEL_UNPACK_BUFFER;
			case BufferTarget::Query: return GL_QUERY_BUFFER;
			case BufferTarget::ShaderStorage: return GL_SHADER_STORAGE_BUFFER;
			case BufferTarget::Texture: return GL_TEXTURE_BUFFER;
			case BufferTarget::TransformFeedback: return GL_TRANSFORM_FEEDBACK_BUFFER;
			case BufferTarget::Uniform: return GL_UNIFORM_BUFFER;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
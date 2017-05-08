#include <enums/texture_target.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const TextureTarget& target)
	{
		switch(target)
		{
			case TextureTarget::Texture1D: return GL_TEXTURE_1D;
			case TextureTarget::Texture2D: return GL_TEXTURE_2D;
			case TextureTarget::Texture3D: return GL_TEXTURE_3D;
			case TextureTarget::Array1D: return GL_TEXTURE_1D_ARRAY;
			case TextureTarget::Array2D: return GL_TEXTURE_2D_ARRAY;
			case TextureTarget::Rectangle: return GL_TEXTURE_RECTANGLE;
			case TextureTarget::Cubemap: return GL_TEXTURE_CUBE_MAP;
			case TextureTarget::CubemapArray: return GL_TEXTURE_CUBE_MAP_ARRAY;
			case TextureTarget::Buffer: return GL_TEXTURE_BUFFER;
			case TextureTarget::Texture2DMultisample: return GL_TEXTURE_2D_MULTISAMPLE;
			case TextureTarget::Texture2DMultisampleArray: return GL_TEXTURE_2D_MULTISAMPLE_ARRAY;
			case TextureTarget::CubemapPositiveX: return GL_TEXTURE_CUBE_MAP_POSITIVE_X;
			case TextureTarget::CubemapNegativeX: return GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
			case TextureTarget::CubemapPositiveY: return GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
			case TextureTarget::CubemapNegativeY: return GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
			case TextureTarget::CubemapPositiveZ: return GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
			case TextureTarget::CubemapNegativeZ: return GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
}
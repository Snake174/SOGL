#include <enums/texture_format.h>
#include <GL/glew.h>
#include <cassert>

namespace SOGL
{
	unsigned remap(const TextureFormat& format)
	{
		switch(format)
		{
			case TextureFormat::DepthComponent: return GL_DEPTH_COMPONENT;
			case TextureFormat::StencilIndex: return GL_STENCIL_INDEX;
			case TextureFormat::DepthStencil: return GL_DEPTH_STENCIL;
			case TextureFormat::Red: return GL_RED;
			case TextureFormat::Green: return GL_GREEN;
			case TextureFormat::Blue: return GL_BLUE;
			case TextureFormat::RG: return GL_RG;
			case TextureFormat::RGB: return GL_RGB;
			case TextureFormat::BGR: return GL_BGR;
			case TextureFormat::RGBA: return GL_RGBA;
			case TextureFormat::BGRA: return GL_BGRA;
			case TextureFormat::RedInteger: return GL_RED_INTEGER;
			case TextureFormat::GreenInteger: return GL_GREEN_INTEGER;
			case TextureFormat::BlueInteger: return GL_BLUE_INTEGER;
			case TextureFormat::RGInteger: return GL_RG_INTEGER;
			case TextureFormat::RGBInteger: return GL_RGB_INTEGER;
			case TextureFormat::BGRInteger: return GL_BGR_INTEGER;
			case TextureFormat::RGBAInteger: return GL_RGBA_INTEGER;
			case TextureFormat::BGRAInteger: return GL_BGRA_INTEGER;
			default:
				assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
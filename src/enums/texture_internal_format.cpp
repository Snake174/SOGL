#include <enums/texture_internal_format.h>
#include <GL/glew.h>
#include <cassert>

namespace SOGL
{
	unsigned remap(const TextureInternalFormat& format)
	{
		switch(format)
		{
			case TextureInternalFormat::DepthComponent: return GL_DEPTH_COMPONENT;
			case TextureInternalFormat::DepthStencil: return GL_DEPTH_STENCIL;
			case TextureInternalFormat::StencilIndex8: return GL_STENCIL_INDEX8;
			case TextureInternalFormat::Red: return GL_RED;
			case TextureInternalFormat::RG: return GL_RG;
			case TextureInternalFormat::RGB: return GL_RGB;
			case TextureInternalFormat::RGBA: return GL_RGBA;
			case TextureInternalFormat::R8: return GL_R8;
			case TextureInternalFormat::R8SNorm: return GL_R8_SNORM;
			case TextureInternalFormat::R16: return GL_R16;
			case TextureInternalFormat::R16SNorm: return GL_R16_SNORM;
			case TextureInternalFormat::RG8: return GL_RG8;
			case TextureInternalFormat::RG8SNorm: return GL_RG8_SNORM;
			case TextureInternalFormat::RG16: return GL_RG16;
			case TextureInternalFormat::RG16SNorm: return GL_RG16_SNORM;
			case TextureInternalFormat::R3G3B2: return GL_R3_G3_B2;
			case TextureInternalFormat::RGB4: return GL_RGB4;
			case TextureInternalFormat::RGB5: return GL_RGB5;
			case TextureInternalFormat::RGB8: return GL_RGB8;
			case TextureInternalFormat::RGB8SNorm: return GL_RGB8_SNORM;
			case TextureInternalFormat::RGB10: return GL_RGB10;
			case TextureInternalFormat::RGB12: return GL_RGB12;
			case TextureInternalFormat::RGB16: return GL_RGB16;
			case TextureInternalFormat::RGB16SNorm: return GL_RGB16_SNORM;
			case TextureInternalFormat::RGBA2: return GL_RGBA2;
			case TextureInternalFormat::RGBA4: return GL_RGBA4;
			case TextureInternalFormat::RGB5A1: return GL_RGB5_A1;
			case TextureInternalFormat::RGBA8: return GL_RGBA8;
			case TextureInternalFormat::RGBA8SNorm: return GL_RGBA8_SNORM;
			case TextureInternalFormat::RGB10A2: return GL_RGB10_A2;
			case TextureInternalFormat::RGB10A2UI: return GL_RGB10_A2UI;
			case TextureInternalFormat::RGBA12: return GL_RGBA12;
			case TextureInternalFormat::RGBA16: return GL_RGBA16;
			case TextureInternalFormat::RGBA16SNorm: return GL_RGBA16_SNORM;
			case TextureInternalFormat::SRGB8: return GL_SRGB;
			case TextureInternalFormat::SRGB8Alpha8: return GL_SRGB8_ALPHA8;
			case TextureInternalFormat::R16F: return GL_R16F;
			case TextureInternalFormat::RG16F: return GL_RG16F;
			case TextureInternalFormat::RGB16F: return GL_RGB16F;
			case TextureInternalFormat::RGBA16F: return GL_RGBA16F;
			case TextureInternalFormat::R32F: return GL_R32F;
			case TextureInternalFormat::RG32F: return GL_RG32F;
			case TextureInternalFormat::RGB32F: return GL_RGB32F;
			case TextureInternalFormat::RGBA32F: return GL_RGBA32F;
			case TextureInternalFormat::R11FG11FB10F: return GL_R11F_G11F_B10F;
			case TextureInternalFormat::RGB9E5: return GL_RGB9_E5;
			case TextureInternalFormat::R8I: return GL_R8I;
			case TextureInternalFormat::R8UI: return GL_R8UI;
			case TextureInternalFormat::R16I: return GL_R16I;
			case TextureInternalFormat::R16UI: return GL_R16UI;
			case TextureInternalFormat::R32I: return GL_R32I;
			case TextureInternalFormat::R32UI: return GL_R32UI;
			case TextureInternalFormat::RG8I: return GL_RG8I;
			case TextureInternalFormat::RG8UI: return GL_RG8UI;
			case TextureInternalFormat::RG16I: return GL_RG16I;
			case TextureInternalFormat::RG16UI: return GL_RG16UI;
			case TextureInternalFormat::RG32I: return GL_RG32I;
			case TextureInternalFormat::RG32UI: return GL_RG32UI;
			case TextureInternalFormat::RGB8I: return GL_RGB8I;
			case TextureInternalFormat::RGB8UI: return GL_RGB8UI;
			case TextureInternalFormat::RGB16I: return GL_RGB16I;
			case TextureInternalFormat::RGB16UI: return GL_RGB16UI;
			case TextureInternalFormat::RGB32I: return GL_RGB32I;
			case TextureInternalFormat::RGB32UI: return GL_RGB32UI;
			case TextureInternalFormat::RGBA8I: return GL_RGBA8I;
			case TextureInternalFormat::RGBA8UI: return GL_RGBA8UI;
			case TextureInternalFormat::RGBA16I: return GL_RGBA16I;
			case TextureInternalFormat::RGBA16UI: return GL_RGBA16UI;
			case TextureInternalFormat::RGBA32I: return GL_RGBA32I;
			case TextureInternalFormat::RGBA32UI: return GL_RGBA32UI;
			case TextureInternalFormat::DepthComponent16: return GL_DEPTH_COMPONENT16;
			case TextureInternalFormat::DepthComponent24: return GL_DEPTH_COMPONENT24;
			case TextureInternalFormat::DepthComponent32: return GL_DEPTH_COMPONENT32;
			case TextureInternalFormat::DepthComponent32F: return GL_DEPTH_COMPONENT32F;
			case TextureInternalFormat::Depth24Stencil8: return GL_DEPTH24_STENCIL8;
			case TextureInternalFormat::Depth32fStencil8: return GL_DEPTH32F_STENCIL8;
			case TextureInternalFormat::CompressedRed: return GL_COMPRESSED_RED;
			case TextureInternalFormat::CompressedRG: return GL_COMPRESSED_RG;
			case TextureInternalFormat::CompressedRGB: return GL_COMPRESSED_RGB;
			case TextureInternalFormat::CompressedRGBA: return GL_COMPRESSED_RGBA;
			case TextureInternalFormat::CompressedSRGB: return GL_COMPRESSED_SRGB;
			case TextureInternalFormat::CompressedSRGBAlpha: return GL_COMPRESSED_SRGB_ALPHA;
			case TextureInternalFormat::CompressedRedRGTC1: return GL_COMPRESSED_RED_RGTC1;
			case TextureInternalFormat::CompressedSignedRedRGTC1: return GL_COMPRESSED_SIGNED_RED_RGTC1;
			case TextureInternalFormat::CompressedRGRGTC2: return GL_COMPRESSED_RG_RGTC2;
			case TextureInternalFormat::CompressedSignedRGRGTC2: return GL_COMPRESSED_SIGNED_RG_RGTC2;
			case TextureInternalFormat::CompressedRGBABPTCUNorm: return GL_COMPRESSED_RGBA_BPTC_UNORM;
			case TextureInternalFormat::CompressedSRGBAlphaBPTCUNorm: return GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM;
			case TextureInternalFormat::CompressedRGBBPTCSignedFloat: return GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT;
			case TextureInternalFormat::CompressedRGBBPTCUnsignedFloat: return GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT;
			case TextureInternalFormat::CompressedRGB8ETC2: return GL_COMPRESSED_RGB8_ETC2;
			case TextureInternalFormat::CompressedSRGB8ETC2: return GL_COMPRESSED_SRGB8_ETC2;
			case TextureInternalFormat::CompressedRGB8PunchthroughAlpha1ETC2: return GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2;
			case TextureInternalFormat::CompressedSRGB8PunchthroughAlpha1ETC2: return GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2;
			case TextureInternalFormat::CompressedETC2EAC: return GL_COMPRESSED_RGBA8_ETC2_EAC;
			case TextureInternalFormat::CompressedSRGB8Alpha8ETC2EAC: return GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC;
			case TextureInternalFormat::CompressedR11EAC: return GL_COMPRESSED_R11_EAC;
			case TextureInternalFormat::CompressedSignedR11EAC: return GL_COMPRESSED_SIGNED_R11_EAC;
			case TextureInternalFormat::CompressedRG11EAC: return GL_COMPRESSED_RG11_EAC;
			case TextureInternalFormat::CompressedSignedRG11EAC: return GL_COMPRESSED_SIGNED_RG11_EAC;
		default:
			assert(false);
		}

		return 0; //to avoid stupid C4715 warning
	}
};
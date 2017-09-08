#pragma once
#include "enums/texture_target.h"
#include "enums/texture_format.h"
#include "enums/texture_internal_format.h"
#include "enums/data_type.h"
#include "image.h"

namespace SOGL
{
	class Texture
	{
	public:
		Texture(TextureTarget target);

		Texture(Image& image);

		~Texture();

		Texture(Texture&&);

		Texture(Texture&) = delete;

		void allocate(int w, int h, int level = 0, TextureFormat format = TextureFormat::RGB, 
					  TextureInternalFormat internal_format = TextureInternalFormat::RGB, 
					  DataType type = DataType::UnsignedByte);

		void allocate(int w, int h, int d, int level = 0, TextureFormat format = TextureFormat::RGB, 
					  TextureInternalFormat internal_format = TextureInternalFormat::RGB, 
					  DataType type = DataType::UnsignedByte);

		void make_mipmaps();

		TextureTarget target();

		void bind(unsigned binding);

		void unbind(unsigned binding);
	private:
		unsigned m_id;
		TextureTarget m_target;

		friend class Framebuffer;
	};
};
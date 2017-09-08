#include "texture.h"
#include <GL/glew.h>
#include <cassert>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace SOGL
{
	Texture::Texture(TextureTarget target): m_target(target)
	{
		glCreateTextures(remap(m_target), 1, &m_id);
		glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	}

	Texture::Texture(const char* filename): m_target(TextureTarget::Texture2D)
	{
		int w, h, n;

		unsigned char* data = stbi_load(filename, &w, &h, &n, 3);
		assert(data != nullptr);

		glCreateTextures(remap(m_target), 1, &m_id);
		glTextureImage2DEXT(m_id, remap(m_target), 0, GL_RGB, 
							w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		//glTexParameterf(target, pname, param);
		//glTextureParameterf(texture, pname, param);
		glTextureParameteri(m_id, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTextureParameteri(m_id, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		make_mipmaps();

		stbi_image_free(data);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_id);
	}

	Texture::Texture(Texture&& o)
	{
		m_id = o.m_id;

		o.m_id = 0;
	}

	void Texture::allocate(int w, int h, int level, TextureFormat format, 
						   TextureInternalFormat internal_format, DataType type)
	{
		glTextureImage2DEXT(m_id, remap(m_target), level, remap(internal_format), 
							w, h, 0, remap(format), remap(type), nullptr);
	}

	void Texture::allocate(int w, int h, int d, int level, TextureFormat format, TextureInternalFormat internal_format, DataType type)
	{
		glTextureImage3DEXT(m_id, remap(m_target), level, remap(internal_format), 
							w, h, d, 0, remap(format), remap(type), nullptr);
	}

	void Texture::make_mipmaps()
	{
		glGenerateTextureMipmap(m_id);
	}

	TextureTarget Texture::target()
	{
		return m_target;
	}

	void Texture::bind(unsigned binding)
	{
		glActiveTexture(GL_TEXTURE0 + binding);
		glBindTexture(remap(m_target), m_id);
	}

	void Texture::unbind(unsigned binding)
	{
		glActiveTexture(GL_TEXTURE0 + binding);
		glBindTexture(remap(m_target), 0);
	}
};
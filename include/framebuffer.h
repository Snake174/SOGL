#pragma once
#include "texture.h"
#include "enums/framebuffer_attachment.h"

namespace SOGL
{
	class Framebuffer
	{
	public:
		Framebuffer();

		~Framebuffer();

		Framebuffer(Framebuffer&&);

		Framebuffer(Framebuffer&) = delete;

		void attach
		(
			Texture& texture, 
			FramebufferAttachment attachment, 
			int level = 0
		);

		bool check();

		bool prepare();

		void bind();

		void unbind();
	private:
		unsigned m_id;
	};
};
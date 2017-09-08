#include "framebuffer.h"
#include <GL/glew.h>
#include <vector>

namespace SOGL
{
	Framebuffer::Framebuffer()
	{
		glCreateFramebuffers(1, &m_id);
	}

	Framebuffer::~Framebuffer()
	{
		glDeleteFramebuffers(1, &m_id);
	}

	Framebuffer::Framebuffer(Framebuffer&& o)
	{
		m_id = o.m_id;

		o.m_id = 0;
	}

	void Framebuffer::attach(Texture& texture, FramebufferAttachment attachment, 
							 int level)
	{
		glNamedFramebufferTexture(m_id, remap(attachment), texture.m_id, level);
	}

	bool Framebuffer::check()
	{
		return glCheckNamedFramebufferStatus(m_id, GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE;
	}

	bool Framebuffer::prepare()
	{
		std::vector<GLenum> draw_buffers;

		for(int i = 0; i < MaxColorAttachment; ++i)
		{
			int r;

			glGetNamedFramebufferAttachmentParameteriv
			(m_id, GL_COLOR_ATTACHMENT0 + i, GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE, &r);

			if(r != GL_NONE)
				draw_buffers.push_back(GL_COLOR_ATTACHMENT0 + i);
		}

		glNamedFramebufferDrawBuffers(m_id, (int)draw_buffers.size(), draw_buffers.data());
		return check();
	}

	void Framebuffer::bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, m_id);
	}

	void Framebuffer::unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}
};

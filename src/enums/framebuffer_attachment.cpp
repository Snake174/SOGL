#include <enums/framebuffer_attachment.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const FramebufferAttachment attachment)
	{
		switch(attachment)
		{
			case FramebufferAttachment::Color0: return GL_COLOR_ATTACHMENT0;
			case FramebufferAttachment::Color1: return GL_COLOR_ATTACHMENT1;
			case FramebufferAttachment::Color2: return GL_COLOR_ATTACHMENT2;
			case FramebufferAttachment::Color3: return GL_COLOR_ATTACHMENT3;
			case FramebufferAttachment::Color4: return GL_COLOR_ATTACHMENT4;
			case FramebufferAttachment::Color5: return GL_COLOR_ATTACHMENT5;
			case FramebufferAttachment::Color6: return GL_COLOR_ATTACHMENT6;
			case FramebufferAttachment::Color7: return GL_COLOR_ATTACHMENT7;
			case FramebufferAttachment::Depth: return GL_DEPTH_ATTACHMENT;
			case FramebufferAttachment::Stencil: return GL_STENCIL_ATTACHMENT;
			case FramebufferAttachment::DepthStencil: return GL_DEPTH_STENCIL_ATTACHMENT;
			default:
				assert(false);
		}
		
		return 0; //to avoid stupid C4715 warning
	}
};
#pragma once

namespace SOGL
{
	enum class FramebufferAttachment
	{
		Color0,
		Color1,
		Color2,
		Color3,
		Color4,
		Color5,
		Color6,
		Color7,
		Color8,
		Depth,
		Stencil,
		DepthStencil
	};

	const int MaxColorAttachment = 8;

	unsigned remap(const FramebufferAttachment& attachment);
};
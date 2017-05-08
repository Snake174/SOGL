#pragma once

namespace SOGL
{
	enum class TextureFormat
	{
		DepthComponent,
		StencilIndex,
		DepthStencil,
		Red,
		Green,
		Blue,
		RG,
		RGB,
		BGR,
		RGBA,
		BGRA,
		RedInteger,
		GreenInteger,
		BlueInteger,
		RGInteger,
		RGBInteger,
		BGRInteger,
		RGBAInteger,
		BGRAInteger
	};

	unsigned remap(const TextureFormat& format);
};
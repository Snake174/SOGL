#pragma once

namespace SOGL
{
	enum class TextureTarget
	{
		Texture1D,
		Texture2D,
		Texture3D,
		Array1D,
		Array2D,
		Rectangle,
		Cubemap,
		CubemapArray,
		Buffer,
		Texture2DMultisample,
		Texture2DMultisampleArray,
		CubemapPositiveX,
		CubemapNegativeX,
		CubemapPositiveY,
		CubemapNegativeY,
		CubemapPositiveZ,
		CubemapNegativeZ
	};

	unsigned remap(const TextureTarget target);
};
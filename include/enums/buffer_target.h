#pragma once

namespace SOGL
{
	enum class BufferTarget
	{
		Array,
		AtomicCounter,
		CopyRead,
		CopyWrite,
		DispatchIndirect,
		DrawIndirect,
		ElementArray,
		PixelPack,
		PixelUnpack,
		Query,
		ShaderStorage,
		Texture,
		TransformFeedback,
		Uniform,
	};

	unsigned remap(const BufferTarget& target);
};
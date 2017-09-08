#pragma once

namespace SOGL
{
	enum class Capability
	{
		Blend,
		ClipDistance0,
		ClipDistance1,
		ClipDistance2,
		ClipDistance3,
		ClipDistance4,
		ClipDistance5,
		ColorLogicOp,
		CullFace,
		DebugOutput,
		DebugOutputSynchronous,
		DepthClamp,
		DepthTest,
		Dither,
		FramebufferSRGB,
		LineSmooth,
		Multisample,
		PolygonOffsetFill,
		PolygonOffsetLine,
		PolygonOffsetPoint,
		PolygonSmooth,
		PrimitiveRestart,
		PrimitiveRestartFixedIndex,
		RasterizerDiscard,
		SampleAlphaToCoverage,
		SampleAlphaToOne,
		SampleCoverage,
		SampleShading,
		SampleMask,
		ScissorTest,
		StencilTest,
		SeamlessCubemap,
		ProgramPointSize,
	};

	unsigned remap(const Capability& usage);
};
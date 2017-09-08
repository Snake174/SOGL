#include <enums/capability.h>
#include <cassert>
#include <GL/glew.h>

namespace SOGL
{
	unsigned remap(const Capability& usage)
	{
		switch (usage)
		{
			case Capability::Blend: return GL_BLEND;
			case Capability::ClipDistance0: return GL_CLIP_DISTANCE0;
			case Capability::ClipDistance1: return GL_CLIP_DISTANCE1;
			case Capability::ClipDistance2: return GL_CLIP_DISTANCE2;
			case Capability::ClipDistance3: return GL_CLIP_DISTANCE3;
			case Capability::ClipDistance4: return GL_CLIP_DISTANCE4;
			case Capability::ClipDistance5: return GL_CLIP_DISTANCE5;
			case Capability::ColorLogicOp: return GL_COLOR_LOGIC_OP;
			case Capability::CullFace: return GL_CULL_FACE;
			case Capability::DebugOutput: return GL_DEBUG_OUTPUT;
			case Capability::DebugOutputSynchronous: return GL_DEBUG_OUTPUT_SYNCHRONOUS;
			case Capability::DepthClamp: return GL_DEPTH_CLAMP;
			case Capability::DepthTest: return GL_DEPTH_TEST;
			case Capability::Dither: return GL_DITHER;
			case Capability::FramebufferSRGB: return GL_FRAMEBUFFER_SRGB;
			case Capability::LineSmooth: return GL_LINE_SMOOTH;
			case Capability::Multisample: return GL_MULTISAMPLE;
			case Capability::PolygonOffsetFill: return GL_POLYGON_OFFSET_FILL;
			case Capability::PolygonOffsetLine: return GL_POLYGON_OFFSET_LINE;
			case Capability::PolygonOffsetPoint: return GL_POLYGON_OFFSET_POINT;
			case Capability::PolygonSmooth: return GL_POLYGON_SMOOTH;
			case Capability::PrimitiveRestart: return GL_PRIMITIVE_RESTART;
			case Capability::PrimitiveRestartFixedIndex: return GL_PRIMITIVE_RESTART_FIXED_INDEX;
			case Capability::RasterizerDiscard: return GL_RASTERIZER_DISCARD;
			case Capability::SampleAlphaToCoverage: return GL_SAMPLE_ALPHA_TO_COVERAGE;
			case Capability::SampleAlphaToOne: return GL_SAMPLE_ALPHA_TO_ONE;
			case Capability::SampleCoverage: return GL_SAMPLE_COVERAGE;
			case Capability::SampleShading: return GL_SAMPLE_SHADING;
			case Capability::SampleMask: return GL_SAMPLE_MASK;
			case Capability::ScissorTest: return GL_SCISSOR_TEST;
			case Capability::StencilTest: return GL_STENCIL_TEST;
			case Capability::SeamlessCubemap: return GL_TEXTURE_CUBE_MAP_SEAMLESS;
			case Capability::ProgramPointSize: return GL_PROGRAM_POINT_SIZE;
		default:
			assert(false);
		}
		return 0; //to avoid stupid C4715 warning
	}
};
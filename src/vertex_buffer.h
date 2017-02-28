#pragma once
#include "enums/buffer_usage.h"
#include "enums/buffer_target.h"

namespace SOGL
{
	class VertexBuffer
	{
	public:
		VertexBuffer();

		~VertexBuffer();

		VertexBuffer(VertexBuffer&&);

		VertexBuffer(VertexBuffer&) = delete;

		void allocate(unsigned count, BufferUsage usage = BufferUsage::StaticDraw);

		void allocate(const void* data, unsigned count, BufferUsage usage = BufferUsage::StaticDraw);

		void bind(BufferTarget target = BufferTarget::Array);

		void unbind(BufferTarget target = BufferTarget::Array);

		unsigned size();

		unsigned id();

		operator unsigned();
	private:
		unsigned m_id;
		unsigned m_size = 0;
	};
};
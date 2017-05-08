#pragma once
#include "vertex_buffer.h"
#include "enums/data_type.h"
#include <cstddef>

namespace SOGL
{
	class VertexArray
	{
	public:
		VertexArray();

		~VertexArray();

		VertexArray(VertexArray&&);

		VertexArray(VertexArray&) = delete;

		void attach_ebo(VertexBuffer& ebo);

		void attach_attribute(unsigned binding, VertexBuffer& vbo, int size, int element_size = 0, ptrdiff_t offset = 0,
							  DataType type = DataType::Float, bool normalized = false);

		void bind();

		void unbind();

		unsigned id();

		operator unsigned();
	private:
		unsigned m_id;
	};
};
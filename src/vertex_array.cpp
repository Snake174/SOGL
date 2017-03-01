#include "vertex_array.h"
#include <GL/glew.h>

namespace SOGL
{
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_id);
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	VertexArray::VertexArray(VertexArray&& o)
	{
		m_id = o.m_id;

		o.m_id = 0;
	}

	void VertexArray::attach_ebo(VertexBuffer& ebo)
	{
		glVertexArrayElementBuffer(m_id, ebo);
	}

	void VertexArray::attach_attribute(unsigned binding, int element_size, VertexBuffer& vbo, int size, ptrdiff_t offset, DataType type, bool normalized)
	{
		glEnableVertexArrayAttrib(m_id, binding);
		glVertexArrayVertexAttribOffsetEXT(m_id, vbo, binding, size, remap(type), 
										   normalized, element_size, offset);
	}

	void VertexArray::bind()
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}

	unsigned VertexArray::id()
	{
		return m_id;
	}

	VertexArray::operator unsigned()
	{
		return id();
	}
};

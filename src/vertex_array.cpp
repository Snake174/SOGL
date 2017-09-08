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
		glVertexArrayElementBuffer(m_id, ebo.m_id);
	}

	void VertexArray::attach_attribute(unsigned binding, VertexBuffer& vbo, int size, int element_size, ptrdiff_t offset, DataType type, bool normalized)
	{
		glEnableVertexArrayAttrib(m_id, binding);
		glVertexArrayVertexAttribOffsetEXT(m_id, vbo.m_id, binding, size, remap(type), normalized, element_size, offset);
		
		/*glVertexAttribPointer(0, 3, type, normalized, 0, offset);

		glVertexArrayVertexAttribOffsetEXT(m_id, vbo, 0, 3, remap(type), normalized, 3, 0);*/
	}
	
	void VertexArray::bind()
	{
		glBindVertexArray(m_id);
	}

	void VertexArray::unbind()
	{
		glBindVertexArray(0);
	}
};

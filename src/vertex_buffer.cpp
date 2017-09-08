#include "vertex_buffer.h"
#include <GL/glew.h>

namespace SOGL
{
	VertexBuffer::VertexBuffer()
	{
		glCreateBuffers(1, &m_id);
	}

	VertexBuffer::~VertexBuffer()
	{
		glDeleteBuffers(1, &m_id);
	}

	VertexBuffer::VertexBuffer(VertexBuffer&& o)
	{
		m_id = o.m_id;

		o.m_id =  0;
	}

	void VertexBuffer::allocate(unsigned count, BufferUsage usage)
	{
		glNamedBufferData(m_id, count, nullptr, remap(usage));
	}

	void VertexBuffer::allocate(const void * data, unsigned count, BufferUsage usage)
	{
		glNamedBufferData(m_id, count, data, remap(usage));
	}

	void VertexBuffer::bind(BufferTarget target)
	{
		glBindBuffer(remap(target), m_id);
	}

	void VertexBuffer::unbind(BufferTarget target)
	{
		glBindBuffer(remap(target), 0);
	}
};

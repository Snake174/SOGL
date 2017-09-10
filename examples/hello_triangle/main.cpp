#include <sogl.h>

const char vertex_shader_src[] = GLSL
(
	400 core,
	layout(location = 0) in vec3 position;
	layout(location = 1) in vec3 color;
	out vec3 fragment_color;
	void main()
	{
		gl_Position = vec4(position, 1.0);
		fragment_color = color;
	}
);

const char fragment_shader_src[] = GLSL
(
	400 core,
	in vec3 fragment_color;
	out vec4 output_color;
	void main()
	{
		output_color = vec4(fragment_color, 1.0);
	}
);

int main()
{
	SOGL::SOGL_init();

	SOGL::Window w(640, 480);
	auto& context = w.context();

	SOGL::VertexArray vao;
	
	glm::vec3 triangle_verts[] =
	{
		{ -1.0f, -1.0f, 0.0f },
		{  1.0f, -1.0f, 0.0f },
		{  0.0f,  1.0f, 0.0f },
	};

	glm::vec3 triangle_colors[] =
	{
		{ 1.0f,  0.0f, 0.0f },
		{ 0.0f,  1.0f, 0.0f },
		{ 0.0f,  0.0f, 1.0f },
	};

	SOGL::VertexBuffer geometry(triangle_verts, 3 * sizeof(glm::vec3));
	SOGL::VertexBuffer colors(triangle_colors, 3 * sizeof(glm::vec3));
	
	vao.attach_attribute(0, geometry, 3);
	vao.attach_attribute(1, colors, 3);

	SOGL::ShaderProgram program;
	{
		SOGL::VertexShader vert(vertex_shader_src);
		SOGL::FragmentShader frag(fragment_shader_src);

		program.attach(vert);
		program.attach(frag); 

		program.link();
	}
	program.bind();

	vao.bind();

	w.set_clear_color({1, 1, 1, 1});

	while(!w.should_close())
	{
		if(w.key(SOGL::Key::Escape))
			w.set_should_close(true);

		w.clear();

		context.draw_arrays(SOGL::PrimitiveType::Triangles, 0, 3);
		
		w.swap_buffers();
		w.update();
	}

	SOGL::SOGL_release();

	return 0;
}
#include <sogl.h>

const char vertex_shader_src[] =
"#version 400 core\n"
"layout(location = 0) in vec3 position;\n"
"layout(location = 1) in vec3 color;\n"
"out vec3 fragment_color;\n"
"void main()\n"
"{\n"
"	gl_Position = vec4(position, 1.0);\n"
"	fragment_color = color;\n"
"}\n";


const char fragment_shader_src[] =
"#version 400 core\n"
"in vec3 fragment_color;\n"
"out vec4 output_color;\n"
"void main()\n"
"{\n"
"	output_color = vec4(fragment_color, 1.0);\n"
"}\n";

int main()
{
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

	SOGL::VertexBuffer geometry;
	geometry.allocate(triangle_verts, 3 * sizeof(glm::vec3));

	SOGL::VertexBuffer colors;
	colors.allocate(triangle_colors, 3 * sizeof(glm::vec3));
	
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

	while(!w.should_close())
	{
		if(w.key(SOGL::Key::Escape))
			w.set_should_close(true);

		w.clear();

		context.draw_arrays(SOGL::PrimitiveType::Triangles, 0, 3);
		
		w.swap_buffers();
		w.update();
	}

	return 0;
}
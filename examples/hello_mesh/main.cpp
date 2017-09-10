#include <sogl.h>
#include <vector>
#include <chrono>
#include <gtc/matrix_transform.hpp>

const char vertex_shader_src[] = GLSL
(
	400 core,
	layout(location = 0) in vec3 position;
	layout(location = 1) in vec3 normal;
	layout(location = 2) in vec2 uv;

	uniform mat4 proj;
	uniform mat4 model;
	
	out vec3 fragment_position;
	out vec3 fragment_normal;
	out vec2 fragment_uv;

	void main()
	{
		gl_Position = proj * model * vec4(position, 1.0);
		fragment_position = gl_Position.xyz;
		fragment_normal = mat3(transpose(inverse(model))) * normal;
		fragment_uv = uv;
	}
);

const char fragment_shader_src[] = GLSL
(
	400 core,
	in vec3 fragment_position;
	in vec3 fragment_normal;
	in vec2 fragment_uv;
	out vec4 output_color;

	uniform sampler2D tex;

	vec3 light_pos = vec3(0, 3.f, 4);

	void main()
	{
		vec3 norm = normalize(fragment_normal);
		vec3 to_light = normalize(light_pos - fragment_position);
		float factor = max(dot(norm, to_light), 0.0f);
		
		output_color = factor * texture(tex, vec2(fragment_uv.x, 1 - fragment_uv.y));
	}
);

bool load_obj(const char* filename,
			  std::vector<glm::vec3>& verts,
			  std::vector<glm::vec2>& uvs,
			  std::vector<glm::vec3>& normals);

int main()
{
	std::vector<glm::vec3> v, n;
	std::vector<glm::vec2> u;

	if(!load_obj("foo.obj", v, u, n))
		printf("Can't load foo.obj\n");

	printf
	(
		"Verts: %i\n"
		"Normals: %i\n"
		"UVs: %i\n",
		v.size(), n.size(), u.size()
	);

	unsigned vert_count = v.size();

	using namespace SOGL;

	SOGL_init();

	Window w(640, 480, "Mesh renderer", ContextSettings(24, 0, 8));
	auto& c = w.context();

	Texture tex("tex.jpg");

	VertexBuffer verts;
	verts.allocate(v.data(), v.size() * sizeof(glm::vec3));

	VertexBuffer normals;
	normals.allocate(n.data(), n.size() * sizeof(glm::vec3));

	VertexBuffer uvs;
	uvs.allocate(u.data(), u.size() * sizeof(glm::vec2));

	v.clear();
	n.clear();
	u.clear();
	
	VertexArray vao;
	vao.attach_attribute(0, verts, 3);
	vao.attach_attribute(1, normals, 3);
	vao.attach_attribute(2, uvs, 2);
	
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

	glm::mat4 projection = glm::perspective
	(
		45.0f,
		w.framebuffer_size().x / float(w.framebuffer_size().y),
		0.1f, 10.f
	);

	glm::vec3 mesh_pos = glm::vec3(0, -0.35, -2.05);
	float mesh_rot = glm::radians(0.f);

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, mesh_pos);

	tex.bind(4);
	program.set_uniform("tex", 4);
	program.set_uniform("proj", projection);
	program.set_uniform("model", model);

	auto last = std::chrono::high_resolution_clock::now();

	w.set_clear_color({1, 1, 1, 1});

	while(!w.should_close())
	{
		using namespace std::chrono;

		auto now = high_resolution_clock::now();
		float dt = duration<float>(now - last).count();
		last = now;

		w.clear();

		if(w.key(Key::Escape))
			w.set_should_close(true);

		if(w.key(Key::A))
		{
			mesh_rot -= glm::radians(45.f) * dt;

			model = glm::mat4(1.0f);
			model = glm::translate(model, mesh_pos);
			model = glm::rotate(model, mesh_rot, glm::vec3(0, 1, 0));
	
			program.set_uniform("model", model);
		}

		if(w.key(Key::D))
		{
			mesh_rot += glm::radians(45.f) * dt;

			model = glm::mat4(1.0f);
			model = glm::translate(model, mesh_pos);
			model = glm::rotate(model, mesh_rot, glm::vec3(0, 1, 0));
	
			program.set_uniform("model", model);
		}

		c.draw_arrays(PrimitiveType::Triangles, 0, vert_count);

		w.swap_buffers();
		w.update();
	}

	SOGL_release();

	return 0;
}

bool load_obj(const char* filename,
			  std::vector<glm::vec3>& verts,
			  std::vector<glm::vec2>& uvs,
			  std::vector<glm::vec3>& normals)
{
	std::vector<unsigned> vertexIndices, uvIndices, normalIndices;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;

	float norm_factor = 1.0f;

	FILE * file = fopen(filename, "r");
	if(!file)
	{
		printf("Impossible to open the file !\n");
		return false;
	}

	while(true)
	{
		char line_header[128];

		if(fscanf(file, "%s", line_header) == EOF)
			break;

		if(strcmp(line_header, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);

			float d = glm::distance(glm::vec3(0, 0, 0), vertex);
			if(d > 1.0f)
				norm_factor = glm::max(norm_factor, d - 1.0f);


			temp_vertices.push_back(vertex);
		}
		else if(strcmp(line_header, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if(strcmp(line_header, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(glm::normalize(normal));
		}
		else if(strcmp(line_header, "f") == 0)
		{
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", 
								 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
								 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
								 &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
			if(matches != 9)
			{
				printf("File can't be read by our simple parser : ( Try exporting with other options\n");
				return false;
			}

			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);

			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
	}

	for(unsigned i: vertexIndices)
		verts.push_back(temp_vertices[i - 1] / norm_factor);

	for(unsigned i: normalIndices)
		normals.push_back(temp_normals[i - 1]);

	for(unsigned i: uvIndices)
		uvs.push_back(temp_uvs[i - 1]);

	fclose(file);
	return true;
}
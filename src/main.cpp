#include "sogl.h"

int main(void)
{
	SOGL::Context context;
	SOGL::Context shared_context(context);
	SOGL::VertexArray vao;
	vao.bind();

    return 0;
}
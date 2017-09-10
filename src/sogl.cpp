#include "sogl.h"
#include <GLFW/glfw3.h>

namespace SOGL
{
	bool SOGL_init()
	{
		return glfwInit() != GLFW_FALSE;
	}

	void SOGL_release()
	{
		glfwTerminate();
	}
};
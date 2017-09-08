#include <image.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>


namespace SOGL
{
	Image::Image(const char* filename)
	{
		int n;

		data = stbi_load(filename, &width, &height, &n, 3);
	}

	bool Image::is_valid() const
	{
		return data != nullptr;
	}

	Image::~Image()
	{
		stbi_image_free(data);
	}
};
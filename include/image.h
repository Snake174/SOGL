#pragma once

namespace SOGL
{
	class Image
	{
	public:
		Image(const char* filename);

		Image(Image&) = delete;

		bool is_valid() const;

		~Image();
	private:
		int width, height;
		unsigned char* data = nullptr;

		friend class Texture;
	};
};
#pragma once

#include <string>

class Texture
{
private:
	unsigned int renderer_id;
	std::string filePath;
	unsigned char* localBuffer;
	int width, height, bytesPerPixel;
public:
	Texture(const std::string& path);
	~Texture();

	void Bind(unsigned int slot = 0) const;
	void UnBind() const;
};


#include "Texture.h"


Texture::Texture(const GLchar* imagePath)
{
	glGenTextures(1, &this->ID);

	// 加载并生成纹理
	stbi_set_flip_vertically_on_load_thread(true);
	unsigned char *data = stbi_load(imagePath, &this->width, &this->height, &this->channels, 0);
	if (data)
	{
		GLenum format;
		if (this->channels == 3)
			format = GL_RGB;
		else if (this->channels == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, this->ID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void Texture::use()
{		
	glBindTexture(GL_TEXTURE_2D, this->ID);
}


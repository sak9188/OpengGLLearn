#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h> // ����glad����ȡ���еı���OpenGLͷ�ļ�

#include <string>
#include <iostream>

#include "stb_image.h"

class Texture
{
public:
	// ����ID
	unsigned int ID;

	int width, height, channels;

	// ��������ȡ��������ɫ��
	Texture(const GLchar* imagePath);
	// ʹ��/�������
	void use();
	// uniform���ߺ���
	//void setBool(const std::string &name, bool value) const;
	//void setInt(const std::string &name, int value) const;
	//void setFloat(const std::string &name, float value) const;

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	// void checkCompileErrors(unsigned int shader, std::string type);
};

#endif

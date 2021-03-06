#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h> // 包含glad来获取所有的必须OpenGL头文件

#include <string>
#include <iostream>

#include "stb_image.h"

class cTexture
{
public:
	// 程序ID
	unsigned int ID;

	int width, height, channels;

	// 构造器读取并构建着色器
	cTexture(const GLchar* imagePath);
	// 使用/激活程序
	void use();
	// uniform工具函数
	//void setBool(const std::string &name, bool value) const;
	//void setInt(const std::string &name, int value) const;
	//void setFloat(const std::string &name, float value) const;

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	// void checkCompileErrors(unsigned int shader, std::string type);
};

#endif

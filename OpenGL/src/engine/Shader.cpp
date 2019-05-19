#include <fstream>
#include <sstream>
#include <iostream>

#include "Shader.h"
#include "Renderer.h"


struct ShaderProgramSource
{
	std::string VertexShader;
	std::string FragmentShader;
};

static ShaderProgramSource ParseShader(const std::string& filePath) {

	std::ifstream stream(filePath);

	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;
	while (getline(stream, line))
	{
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos) {
				type = ShaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos) {
				type = ShaderType::FRAGMENT;
			}
		}
		else if (type != ShaderType::NONE) {
			ss[(int)type] << line << '\n';
		}
	}
	return { ss[0].str(), ss[1].str() };
}

unsigned int CompileShader(unsigned int type, std::string source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)_malloca(sizeof(char) * length);
		glGetShaderInfoLog(id, length, &length, msg);
		std::cout << msg << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

unsigned int CreateShader(const std::string & vertex, const std::string & fragment) {

	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertex);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragment);

	glAttachShader(program, vs);
	glAttachShader(program, fs);

	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

Shader::Shader(const std::string & filename)
	: filePath(filename), renderer_id(0)
{
	ShaderProgramSource src = ParseShader(filePath);
	renderer_id = CreateShader(src.VertexShader, src.FragmentShader);
}

unsigned int Shader::CompileShader(unsigned int type, std::string source) {
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* msg = (char*)_malloca(sizeof(char) * length);
		glGetShaderInfoLog(id, length, &length, msg);
		std::cout << msg << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}

void Shader::Bind() const
{
	GLCall(glUseProgram(renderer_id));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string & name, float v0, float v1, float v2, float v3)
{
	GLCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniform1i(const std::string & name, int value)
{
	GLCall(glUniform1i(GetUniformLocation(name), value));
}

Shader::~Shader()
{
	GLCall(glDeleteProgram(renderer_id));
}

int Shader::GetUniformLocation(const std::string & name)
{
	if (locations.find(name) != locations.end()) {
		return locations[name];
	}

	GLCall(int location = glGetUniformLocation(renderer_id, name.c_str()));
	if (location == -1) {
		std::cout << "Warning uniform " << name << " does not exist!" << std::endl;
	}
	return locations[name] = location;
}

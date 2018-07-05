#include "Program.h"

Program::Program(const std::string& vertexShader, const std::string& fragmentShader)
	: m_program(vfl::loadProgram(vertexShader, fragmentShader))
{
	bind();
	registerUniforms();
	std::cout << "Program compiled and linked successfully. ID [" << m_program << "]" << std::endl;
}

Program::Program(const std::string& computeShader)
	: m_program(vfl::loadProgram(computeShader))
{
	bind();
	registerUniforms();
	std::cout << "Program compiled and linked successfully. ID [" << m_program << "]" << std::endl;
}

Program::~Program()
{
	glDeleteProgram(m_program);
}

void Program::bind()
{
	glUseProgram(m_program);
}

void Program::unbind()
{
	glUseProgram(0);
}

GLuint Program::getID() const
{
	return m_program;
}

void Program::loadInt(const std::string& location, int value)
{
	glUniform1i(isInMap(location), value);
}

void Program::loadFloat(const std::string& location, float value)
{
	glUniform1f(isInMap(location), value);
}

void Program::loadVector2f(const std::string& location, vfm::vec2 vector)
{
	glUniform2f(isInMap(location), vector.x, vector.y);
}

void Program::loadVector3f(const std::string& location, vfm::vec3 vector)
{
	glUniform3f(isInMap(location), vector.x, vector.y, vector.z);
}

void Program::loadMatrix4f(const std::string& location, vfm::mat4 matrix)
{
	glUniformMatrix4fv(isInMap(location), 1, GL_FALSE, &matrix[0][0]);
}

void Program::registerUniforms()
{
	GLint count;
	GLsizei length;
	GLint size;
	GLenum type;
	GLchar name[16];

	glGetProgramiv(m_program, GL_ACTIVE_UNIFORMS, &count);
	std::cout << "Found " << count << " uniforms on program. ID [" << m_program << "]" << std::endl;

	for (int i = 0; i < count; i++)
	{
		glGetActiveUniform(m_program, (GLuint)i, 16, &length, &size, &type, name);

		GLuint loc = glGetUniformLocation(m_program, name);
		ulHashmap.emplace(name, loc);

		std::cout << "Uniform #" << i << " Type: " << type << " Name: " << name << " || Emplaced in hashmap." << std::endl;
	}
}

GLint Program::isInMap(const std::string& location)
{
	std::unordered_map<std::string, GLuint>::iterator it = ulHashmap.find(location);
	if (it != ulHashmap.end())
	{
		return it->second;
	}
	return -1;
}
#include "common.h"

const std::string getSource(const std::string& sourceFile, const std::string& type)
{
	std::ifstream infile("Resources/Shaders/" + sourceFile + "." + type);
	std::string source;
	std::stringstream stringStream;

	if (!infile.is_open())
	{
		throw std::runtime_error("Couldn't open shader source: " + sourceFile);
	}

	stringStream << infile.rdbuf();
	source = stringStream.str();

	return source;
}

GLuint compileShader(const GLchar* source, GLenum type)
{
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	GLint status;
	GLchar infolog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		glGetShaderInfoLog(shader, 512, nullptr, infolog);
		throw std::runtime_error("Error compiling shader: " + std::string(infolog));
	}

	return shader;
}

GLuint createProgram(GLuint vertexShader, GLuint fragmentShader)
{
	GLuint program = glCreateProgram();

	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);

	glLinkProgram(program);

	GLint status;
	GLchar infolog[512];

	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (!status)
	{
		glGetProgramInfoLog(program, 512, nullptr, infolog);
		throw std::runtime_error("Error linking program: " + std::string(infolog));
	}

	return program;
}

GLuint createProgram(GLuint computeShader)
{
	GLuint program = glCreateProgram();

	glAttachShader(program, computeShader);

	glLinkProgram(program);

	GLint status;
	GLchar infolog[512];

	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (!status)
	{
		glGetProgramInfoLog(program, 512, nullptr, infolog);
		throw std::runtime_error("Error linking program: " + std::string(infolog));
	}

	return program;
}

GLuint vfl::loadProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
	GLuint programID;
	std::string vSource, fSource;
	try
	{
		vSource = getSource(vertexShader.c_str(), "vs");
		fSource = getSource(fragmentShader.c_str(), "fs");
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	GLuint vsID, fsID;
	try
	{
		vsID = compileShader(vSource.c_str(), GL_VERTEX_SHADER);
		fsID = compileShader(fSource.c_str(), GL_FRAGMENT_SHADER);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		programID = createProgram(vsID, fsID);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	glDeleteShader(vsID);
	glDeleteShader(fsID);

	return programID;
}

GLuint vfl::loadProgram(const std::string & computeShader)
{
	GLuint programID;
	std::string vSource, fSource;
	try
	{
		vSource = getSource(computeShader.c_str(), "cs");
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	GLuint csID;
	try
	{
		csID = compileShader(vSource.c_str(), GL_COMPUTE_SHADER);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		programID = createProgram(csID);
	}
	catch (std::runtime_error& e)
	{
		std::cout << e.what() << std::endl;
	}

	glDeleteShader(csID);

	return programID;
}

template <class T>
constexpr std::string_view vfc::type_name()
{
	using namespace std;
#ifdef __clang__
	string_view p = __PRETTY_FUNCTION__;
	return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
	string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
	return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
	return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
	string_view p = __FUNCSIG__;
	return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}
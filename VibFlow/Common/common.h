#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <map>
#include <vector>
#include <GL\glew.h>

namespace vfl
{
	GLuint loadProgram(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint loadProgram(const std::string& computeShader);
}
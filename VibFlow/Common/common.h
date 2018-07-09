#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <exception>
#include <map>
#include <vector>
#include <cstddef>
#include <cstring>
#include <ostream>
#include <string_view>
#include <GL\glew.h>

namespace vfl
{
	GLuint loadProgram(const std::string& vertexShader, const std::string& fragmentShader);
	GLuint loadProgram(const std::string& computeShader);
}

namespace vfc
{
	template <class T>
	constexpr std::string_view type_name();
}
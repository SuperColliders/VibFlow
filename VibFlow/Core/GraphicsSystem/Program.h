#pragma once
#include <iostream>
#include <unordered_map>
#include <GL/glew.h>
#include "../../vibdec.h"
#include "../../Common/common.h"

class Program
{
public:
	Program(const std::string& vertexShader, const std::string& fragmentShader);
	Program(const std::string& computeShader);
	virtual ~Program();

	void bind();
	void unbind();
	GLuint getID() const;

	void loadInt(const std::string& location, int value);
	void loadFloat(const std::string& location, float value);
	void loadVector2f(const std::string& location, vfm::vec2 vector);
	void loadVector3f(const std::string& location, vfm::vec3 vector);
	void loadMatrix4f(const std::string& location, vfm::mat4 matrix);


private:
	GLuint m_program;
	std::unordered_map<std::string, GLuint> ulHashmap;

	GLint isInMap(const std::string& location);
	void registerUniforms();
};


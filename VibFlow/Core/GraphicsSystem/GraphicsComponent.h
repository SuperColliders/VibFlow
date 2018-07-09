#pragma once
#include <unordered_map>
#include <GL\glew.h>
#include "../../vibdec.h"
#include "../Component.h"

class GraphicsComponent : public Component
{
public:
	friend class GraphicsSystem;
	GraphicsComponent();
	~GraphicsComponent();

	vfm::mat4 getModelMatrix() const;

private:
	std::unordered_map<std::string, GLuint> buffers;
	vfm::mat4 modelMatrix;
};


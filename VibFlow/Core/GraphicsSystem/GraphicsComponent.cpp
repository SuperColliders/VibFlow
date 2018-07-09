#include "GraphicsComponent.h"



GraphicsComponent::GraphicsComponent()
{
	//Create the Vertex Array Object - Always Required
	GLuint vao;
	glGenVertexArrays(1, &vao);
	buffers.emplace("VAO", vao);

	//Create the Vertex Position Buffer - Always Required
	GLuint vbo;
	glGenBuffers(1, &vbo);
	buffers.emplace("VBO", vbo);

	//Create the Vertex Color Buffer - Always Required (since we are not using textures) (?)
	GLuint cbo;
	glGenBuffers(1, &cbo);
	buffers.emplace("CBO", cbo);
}


GraphicsComponent::~GraphicsComponent()
{
}

vfm::mat4 GraphicsComponent::getModelMatrix() const
{
	return modelMatrix;
}

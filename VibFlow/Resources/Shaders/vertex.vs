#version 450 core

layout (location = 0) in vec4 inPos;

out vec4 outPos;

void main()
{
	outPos = inPos;
	gl_Position = inPos;
}

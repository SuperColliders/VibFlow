#version 450 core

in vec4 outPos;

uniform float time;

out vec4 outColor;

void main()
{
	outColor = vec4(abs(cos(time)), abs(cos(time - 1)), abs(cos(time - 2)), 1.0);
}

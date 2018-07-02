#pragma once
#include <iostream>
#include "vibdec.h"

int main(int argc, char** argv)
{
	vfm::vec3 vec3f;
	vec3f = vfm::vec3(1.0f, 1.0f, 1.0f);
	vec3f.x = 3.0f;
	std::cout << vec3f.x << vec3f.y << vec3f.z << std::endl;
	system("pause");
	return 0;
}

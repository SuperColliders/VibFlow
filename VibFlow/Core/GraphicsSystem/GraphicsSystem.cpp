#include "GraphicsSystem.h"

GraphicsSystem GraphicsSystem::GSystem;

GraphicsSystem::GraphicsSystem()
{
	canvas.push(new Canvas()); //Push the default canvas (Should it be mixed?)
}

void GraphicsSystem::createNewCanvas()
{

}

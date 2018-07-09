#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include "Component.h"
#include "../Common/common.h"

class Entity
{
public:
	Entity();
	~Entity();

	template<typename C> void addComponent(Component* component);
	template<typename C> bool delComponent();

	template<typename C> inline C* getComponent() const;

private:
	std::map<std::string, Component*> components;
};

template<typename C>
inline C * Entity::getComponent() const
{
	return static_cast<C*>(components[vfc::type_name<C>()]);
}

template<typename C>
void Entity::addComponent(Component * component)
{
	if (components.find(component) == components.end())
	{
		components.emplace(vfc::type_name<C>(), component);
	}
}

template<typename C>
bool Entity::delComponent()
{
	if (components.find(component) != components.end())
	{
		components.erase(vfc::type_name<C>());
		return true;
	}
	return false;
}

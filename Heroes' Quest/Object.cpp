#include "Object.h"

Object::Object()
{
}


Object::~Object()
{
}

int Object::getDamage() const
{
	return damage;
}

std::string Object::describe() const
{

	return description;

}

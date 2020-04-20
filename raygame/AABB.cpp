#include "AABB.h"
float AABB::top()
{
	return m_position.y - Height / 2;
}
float AABB::left()
{
	return m_position.x - Width / 2;
}
AABB::AABB(float height, float width, Agent* parent)
{
	Width = width;
	Height = height;
	Parent = parent;
	bottom = m_position.y + Height / 2;
	right = m_position.x + Width / 2;
}


void AABB::update(float deltaTime)
{
	m_position = Parent->getPosition();
}

void AABB::draw()
{
	Rectangle* rec = new Rectangle{ left(),top(),Width,Height};
	DrawRectangleLinesEx(*rec, 5, color);
}



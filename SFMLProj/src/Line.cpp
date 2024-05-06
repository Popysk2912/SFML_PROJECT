#include "Line.h"


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||LineClass|||||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
Line::Line(sf::Vertex start, sf::Vertex end)
{
	this->setPrimitiveType(sf::Lines);
	this->append(start);
	this->append(end);
}

sf::Vector2f Line::getStartPoint()
{
	return (*this)[0].position;
}
sf::Vector2f Line::getEndPoint()
{
	return (*this)[1].position;
}
sf::Color Line::getStartColor()
{
	return (*this)[0].color;
}
sf::Color Line::getEndColor()
{
	return (*this)[1].color;
}

void Line::setStartPoint(sf::Vector2f p)
{
	(*this)[0].position = p;
}
void Line::setEndPoint(sf::Vector2f p)
{
	(*this)[1].position = p;
}
void Line::setStartColor(sf::Color c)
{
	(*this)[0].color = c;
}
void Line::setEndColor(sf::Color c)
{
	(*this)[1].color = c;
}

void Line::setColor(sf::Color c)
{
	(*this)[0].color = c;
	(*this)[1].color = c;
}


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||
|||||||||||||||||||||LineOverride||||||||||||||||||||||
|||||||||||||||||||||||||||||||||||||||||||||||||||||*/
LineOverride::LineOverride(sf::Vertex start, float rad, float ang) :
	Line(start, start),
	radius(rad),
	angle(ang)
{
	this->recalculateLine();
}
void LineOverride::recalculateLine()
{
	float angle_rad = degToRad(angle);
	(*this)[1] = sf::Vertex(sf::Vector2f((*this)[0].position.x + radius * sinf(angle_rad),
										 (*this)[0].position.y + radius * cosf(angle_rad)));
}

float LineOverride::getAngle()
{
	return angle;
}

void LineOverride::setStartPoint(sf::Vector2f p)
{
	Line::setStartPoint(p);
	this->recalculateLine();
}
void LineOverride::setAngle(float a)
{
	angle = a;
}
void LineOverride::setRadius(float r)
{
	radius = r;
}


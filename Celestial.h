#pragma once
#include "Utilities.h"
using namespace sf;

class Celestial
{
protected:
	b2BodyDef Celestial_Def;
	b2Body* Celestial_Body;
	b2CircleShape Celestial_Geometry;
	b2FixtureDef Celestial_Fixture;
	CircleShape Celestial_Shape;
public:
	Celestial(const b2Vec2 Position, b2World& world,
		   const float Radius, const float Density);
	~Celestial();
	b2Vec2 GetPosition();
	virtual void Draw(RenderWindow& window);
};
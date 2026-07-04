#pragma once
#include "Celestial.h"

class Planet : public Celestial {
	const float G = 32.0f;
public:
	Planet(b2Vec2 Position, b2World& world, const float Radius, const float Density, const int random, const float E);
	~Planet();
	void Update();
	Color GetColor();
	void Draw(RenderWindow& window) override;
};
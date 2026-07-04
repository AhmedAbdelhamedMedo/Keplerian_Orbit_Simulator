#pragma once
#include "Planet.h"

using namespace std;

class Orbit {
	RenderTexture OrbitLayer;
	RectangleShape Orbit_LayerFade;
	vector<Vector2f> Planets_Previous_Position;
	Vector2f Planet_Current_Position;
	Vertex Orbit_line[2];

public:
	Orbit();
	~Orbit();
	void Add(const Vector2f Mouse_Position);
	void Update(const Vector2f Planet_Current_Position, const int index, const Color Planet_Color);
	void Fade();
	void Draw(RenderWindow& window);
};
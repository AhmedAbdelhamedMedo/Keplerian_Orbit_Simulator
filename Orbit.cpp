#include "Orbit.h"

Orbit::Orbit() {
    OrbitLayer.create(Utilities::WINDOW_WIDTH, Utilities::WINDOW_HEIGHT);
    OrbitLayer.clear(Color::Transparent);
    Orbit_LayerFade.setSize((Vector2f)OrbitLayer.getSize());
    Orbit_LayerFade.setFillColor(Color(0, 0, 0, 7));
}

Orbit::~Orbit() {}

void Orbit::Add(const Vector2f Mouse_Position) {
    Planets_Previous_Position.push_back(Mouse_Position);
}

void Orbit::Update(const Vector2f Planet_Current_Position, const int index, const Color Planet_Color) {
    Orbit_line[0] = Vertex(Planets_Previous_Position[index], Planet_Color);
    Orbit_line[1] = Vertex(Planet_Current_Position, Planet_Color);
    Planets_Previous_Position[index] = Planet_Current_Position;
    OrbitLayer.draw(Orbit_line, 2, Lines);
    OrbitLayer.display();
}

void Orbit::Fade() {
    OrbitLayer.draw(Orbit_LayerFade, BlendAlpha);
}

void Orbit::Draw(RenderWindow& window) {
    window.draw(Sprite(OrbitLayer.getTexture()));
}
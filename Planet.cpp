#include "Planet.h"

Planet::Planet(b2Vec2 Position, b2World& world, const float Radius,
               const float Density, const int random, const float E) :
               Celestial(Position, world, Radius, Density) {
    Celestial_Fixture.filter.categoryBits = 0x0002;

    Celestial_Shape.setFillColor(Utilities::HSV_to_RGB(random % 360));

    float a = Position.Length();
    Position.Normalize();
    b2Vec2 tangent(-Position.y, Position.x);
    float speed = sqrt(G * ((2.0f / (a * E)) - (1.0f / a)));
    b2Vec2 initialVelocity = 2.0f * speed  * tangent;
    int Rotation_Direction = (((rand() % 2) * 2) - 1);
    Celestial_Body->SetLinearVelocity(Rotation_Direction * initialVelocity);
}

Planet::~Planet() {}

void Planet::Update() {
    b2Vec2 direction = - Celestial_Body->GetPosition();
    float distance = direction.Length();
    direction.Normalize();

    //const float a = 2.0f;
    //b2Vec2 gravitationalForce = ((6.28 * 6.28 * a * a * a) / (distance * distance)) * direction;
    b2Vec2 gravitationalForce = ((G * Celestial_Geometry.m_radius)/ (distance * distance)) * direction;

    Celestial_Body->ApplyForceToCenter(gravitationalForce, true);
    Celestial_Shape.setPosition(Utilities::Convert_Box2D_SFML_Space(Celestial_Body->GetPosition()));
}

Color Planet::GetColor() {
    return Celestial_Shape.getFillColor();
}

void Planet::Draw(RenderWindow& window) {
    window.draw(Celestial_Shape);
}
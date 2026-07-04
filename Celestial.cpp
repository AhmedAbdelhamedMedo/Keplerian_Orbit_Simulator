#include "Celestial.h"

Celestial::Celestial(const b2Vec2 Position, b2World& world,
                     const float Radius, const float Density) {
    Celestial_Def.type = b2_dynamicBody;
    Celestial_Def.position.Set(Position.x, Position.y);
    Celestial_Body = world.CreateBody(&Celestial_Def);

    Celestial_Geometry.m_p.Set(Position.x, Position.y);
    Celestial_Geometry.m_radius = Radius;

    Celestial_Fixture.shape = &Celestial_Geometry;
    Celestial_Fixture.density = Density;
    Celestial_Fixture.filter.categoryBits = 0x0002;
    Celestial_Fixture.filter.maskBits = 0x0008;

    Celestial_Body->CreateFixture(&Celestial_Fixture);
    Celestial_Body->SetLinearDamping(0.0f);
    Celestial_Body->SetAngularDamping(0.0f);

    Celestial_Shape.setRadius(Radius * Utilities::PIXELS_PER_UNIT);
    Celestial_Shape.setOrigin(Vector2f(Radius * Utilities::PIXELS_PER_UNIT, Radius * Utilities::PIXELS_PER_UNIT));
    Celestial_Shape.setPosition(Utilities::Convert_Box2D_SFML_Space(Position));
    Celestial_Shape.setFillColor(Color::Yellow);
}

Celestial::~Celestial() {}

b2Vec2 Celestial::GetPosition() {
    return Celestial_Body->GetPosition();
}

void Celestial::Draw(RenderWindow &window) {
    window.draw(Celestial_Shape);
}
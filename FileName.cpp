#include "Orbit.h"

int main() {
    srand(time(0));

    b2World* Solar_System = new b2World(b2Vec2(0, 0));

    Celestial* Sun = new Celestial(b2Vec2(0, 0), *Solar_System, 2.0f, 0.1f);

    vector<Planet*> planets;

    Orbit* Orbits = new Orbit();

    float timeStep = 1.0f / (float)Utilities::FPS;

    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    Clock clock;
    float time = 0;

    RenderWindow window(VideoMode(Utilities::WINDOW_WIDTH, Utilities::WINDOW_HEIGHT), "SFML Box2D Physics!");
    window.setFramerateLimit(Utilities::FPS * 2);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case Event::Closed: {
                    window.close();
                    break;
                }
                case Event::MouseButtonPressed: {
                    if (Mouse::isButtonPressed(Mouse::Left)) {
                        float randomRadius = 0.3f + ((float)rand() / (float)RAND_MAX) * (0.7f - 0.3f);
                        planets.push_back(new Planet(Utilities::Convert_SFML_Box2D_Space((Vector2f)Mouse::getPosition(window)),
                        *Solar_System, randomRadius, 0.05f, rand(), 0.7f));
                        Orbits->Add((Vector2f)Mouse::getPosition(window));
                    }
                    break;
                }
            }
        }

        if (clock.getElapsedTime().asSeconds() > timeStep) {
            Solar_System->Step(timeStep, velocityIterations, positionIterations);
            if (time > 0.5f) {
                for (int i = 0; i < planets.size(); i++) {
                    planets[i]->Update();
                    Orbits->Update(Utilities::Convert_Box2D_SFML_Space(planets[i]->GetPosition()), i, planets[i]->GetColor());
                }
                Orbits->Fade();
            }
            time += clock.restart().asSeconds();
        }

        window.clear();

        Orbits->Draw(window);
        Sun->Draw(window);

        for (int i = 0; i < planets.size(); i++) {
            planets[i]->Draw(window);
        }

        window.display();
    }
    return 0;
}
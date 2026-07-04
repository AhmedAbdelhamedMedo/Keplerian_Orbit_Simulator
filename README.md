# Keplerian Orbit Simulator

<img width="500" height="500" alt="KeplerianOrbitSimulator_Gameplay" src="https://github.com/user-attachments/assets/c9e807ee-03df-4892-a5e2-87e303c22448" />

## Detailed Description
This project is a 2D planetary physics sandbox built in C++ that simulates Kepler orbits in real-time. The application utilizes **SFML** for rendering minimalist, high-contrast graphics and smooth orbital trails, alongside **Box2D** to handle underlying physics, mass allocation, and custom gravitational forces. 

Users can interactively spawn planets with a simple mouse click. The system dynamically calculates the required orbital velocities and trajectories based on the planet's generated mass (size) and its initial distance from the central celestial body (the sun). This creates an interactive playground to observe gravitational stability, orbital decay, and complex multi-body behaviors.

---

## Features

* **Dynamic Gravity Simulation:** Planets are pulled toward the central sun based on accurate gravitational calculations handled via custom Box2D force applications.
* **Kepler Orbits:** Planetary speed and orbital paths differ dynamically according to the spawned planet's mass and its distance from the sun.
* **Interactive Spawning:** Responsive click-to-spawn mechanics allow for the real-time creation of complex, multi-planet solar systems.
* **Orbital Trails:** Visual tracing of planetary paths over time makes it easy to observe orbital stability, eccentricity.

---

## Tech Stack

* **Language:** C++17 / C++20
* **Rendering Engine:** SFML (Simple and Fast Multimedia Library)
* **Physics Engine:** Box2D

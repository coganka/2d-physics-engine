#include "./Force.h"
#include <iostream>
#include <algorithm>

Vec2 Force::GenerateDragForce(const Body& body, float k) {
    Vec2 dragForce = Vec2(0,0);
    if (body.velocity.MagnitudeSquared() > 0) {

        // calculate drag direction: inverse of velocity unit vector
        Vec2 dragDirection = body.velocity.UnitVector() * -1.0;

        // calculate drag magnitude: k * ||v||^2
        float dragMagnitude = k * body.velocity.MagnitudeSquared();

        // Generate the final drag force
        dragForce = dragDirection * dragMagnitude;
    }
    return dragForce;
}

// Generate Friction Force
Vec2 Force::GenerateFrictionForce(const Body& body, float k) {
    Vec2 frictionForce = Vec2(0,0);

    // inverse of velocity 
    Vec2 frictionDirection = body.velocity.UnitVector() * -1.0;

    // k = Friction coefficent * ||Fn||
    float frictionMagnitude = k;

    // F = -v^ (unit vector) * k
    frictionForce = frictionDirection * frictionMagnitude;

    return frictionForce;
}

// generate grav. force
Vec2 Force::GenerateGravitationalForce(const Body& a, Body& b, float G, float minDistance, float maxDistance) {
    Vec2 d = (b.position - a.position);

    // ||d||^2
    float distanceSquared = d.MagnitudeSquared();

    // clamp the values to see some action
    distanceSquared = std::clamp(distanceSquared, minDistance, maxDistance);

    // d^
    Vec2 attractDirection = d.UnitVector();

    // G * (Ma * Mb) / ||d||^2
    float attractionMagnitude = G * (a.mass * b.mass) / distanceSquared;

    Vec2 attractionForce = attractDirection * attractionMagnitude;

    return attractionForce;
}

// spring force
Vec2 Force::GenerateSpringForce(const Body& body, Vec2 anchor, float restLength, float k) {
    Vec2 d = body.position - anchor;

    // delta l
    float displacement = d.Magnitude() - restLength;

    Vec2 springDirection = d.UnitVector();

    // Fspring = -k * delta l
    float springMagnitude = -k * displacement;

    // force with direction vector
    Vec2 springForce = springDirection * springMagnitude;

    return springForce;
}

// spring force between bodies
Vec2 Force::GenerateSpringForce(const Body& a, const Body& b, float restLength, float k) {
    Vec2 d = a.position - b.position;

    // delta l
    float displacement = d.Magnitude() - restLength;

    Vec2 springDirection = d.UnitVector();

    // Fspring = -k * delta l
    float springMagnitude = -k * displacement;

    // force with direction vector
    Vec2 springForce = springDirection * springMagnitude;

    return springForce;
}
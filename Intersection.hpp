

#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP
#include "Vector3.hpp"


struct Intersection {
    vec3 _color;  // The color of the object that is hit by a Ray
    vec3 _normal; // The surface normal of the object that is hit by a ray
    //definition:the normal line to a plane curve at a given point is the line perpendicular to the tangent line to the curve at the point.
    //For a sphere, the normal is the vector from the sphere’s center to the intersection point, normalized to unit length.

    double _t; // t is distance from origin to the point of intersection, The distance along the ray's direction where the intersection occurs
    // A ray has an origin and a direction. If intersection = t * direction + origin, at which t did the ray hit the object?
    Intersection(vec3 color, vec3 normal, double t);
};

#endif //INTERSECTION_HPP

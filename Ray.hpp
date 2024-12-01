

#ifndef RAY_HPP
#define RAY_HPP
#include <optional>
#include "Intersection.hpp"
#include "Sphere.hpp"
#include "Vector3.hpp"


//A Ray object was used inside YourRayTracer::render, also note that ray object was passed as argument in Scene::intersect & Scene::traceRay
struct Ray {
    vec3 _origin;
    vec3 _direction;

    Ray(vec3 origin, vec3 direction);
    std::optional<Intersection> intersects(const Sphere& ray) const;
    vec3 point_at(float t) const;
};



#endif //RAY_HPP

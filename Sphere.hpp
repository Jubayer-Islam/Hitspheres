

#ifndef SPHERE_HPP
#define SPHERE_HPP
#include "Vector3.hpp"

struct Sphere {
    double _radius;
    double _radius_squared; //squared distances are often used in calculations like collision detection or ray-sphere intersection
    vec3 _center;
    vec3 _color;
    explicit Sphere(double radius, vec3 center, vec3 color); //explicit keyword prevents unintended object creation such as: Sphere s = 5.0;
};




#endif //SPHERE_HPP

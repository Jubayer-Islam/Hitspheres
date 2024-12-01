
#ifndef SCENE_HPP
#define SCENE_HPP

#include "Vector3.hpp"
#include "Sphere.hpp"
#include "Intersection.hpp"
#include "Ray.hpp"
#include <vector>
struct Scene{

    // Vector<Sphere> is a dynamically growable list containing Spheres. It behaves like an array that can change its size.
    std::vector<Sphere> _spheres; //scene structure has it's first vector element named _spheres which follows the structure of struct Sphere data type
    vec3 _backgroundColor;          //another element called _backgroundColor which is of vec3 data type
    // epsilon is used to counteract float/double imprecisions
    double _epsilon = 0.000000001;

    explicit Scene(vec3 backgroundColor):_backgroundColor(backgroundColor){}
    Scene():_backgroundColor(vec3(0,0,0)){}  //we make sure bg color is black by default and also to make sure that we pass a vector we use explicit keyword above

    void addSphere(Sphere object);
    const vec3 getBackgroundColor() const;
    std::optional<Intersection> intersect(const Ray& ray) const; //definition: Intersection(vec3 color, vec3 normal, double t)
    vec3 traceRay(const Ray& ray) const;
};

#endif //SCENE_HPP

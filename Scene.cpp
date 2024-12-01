


#include "Scene.hpp"

void Scene::addSphere(Sphere object){
    _spheres.push_back(object); //scene structure has it's first element named _spheres(a dynamic array) which follows the structure of struct Sphere data type
}


const vec3 Scene::getBackgroundColor() const{
    return _backgroundColor;
}


//Scene::intersect is used by the Scene::traceRay below
std::optional<Intersection> Scene::intersect(const Ray& ray) const{

    std::optional<Intersection> result = {};

    for(auto& object: _spheres){
        std::optional<Intersection> i = ray.intersects(object);
        if( !i.has_value()){
            continue;
        }

        if(!result.has_value() || i->_t < result->_t){
            result = i;
        }
    }

    return result;
}


vec3 Scene::traceRay(const Ray& ray) const {

    std::optional<Intersection> intersection = intersect(ray); //uses the intersect function above
    //Nothing hit
    if (!intersection.has_value()) {
        return _backgroundColor;
    }
    return intersection->_color;
}
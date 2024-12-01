

#ifndef YOURRAYTRACER_HPP
#define YOURRAYTRACER_HPP
#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Screen.hpp"

struct RaySetup{
    vec3 _topLeft;
    vec3 _rayOrigin;
    vec3 _directionX;
    vec3 _directionY;
};

struct YourRayTracer{
    Camera _camera;
    Scene _scene;
    RaySetup _raySetup;

    RaySetup computeRaySetup(Screen screen); //we pass screen object which has width, height, and a vec3 array

    YourRayTracer();

    void setCamera(Camera& camera); //called in main
    void setScene(Scene& scene); //called in main
    void render(Screen& screen); //called in main
    vec3 traceRay(const Ray& r); //called in scene
    Ray computeRay(double x, double y, const RaySetup& rs);


};


#endif //YOURRAYTRACER_HPP

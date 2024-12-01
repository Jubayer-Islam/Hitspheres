#include <iostream>
#include <fstream>

#include "Camera.hpp"
#include "Ray.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Vector3.hpp"
#include "Screen.hpp"
#include "YourRayTracer.hpp"


int main() {
    const unsigned int width = 2560;    //width and height are set first, might need to be readjusted below 254 later on to avoid stack overflow error
    const unsigned int height = 1600 ;
    Screen screen(width, height);       //an array to hold the values of pixels was created

    // A camera that is slightly behind and above the center point, but looks at 0,0,0
    Camera camera; //a camera object was created which has the default values for eyePoint, viewDir, upDir, field_of_view
    camera.setEyePoint(vec3(0.0,1.0,-5.0));
    camera.setLookAt(vec3(0.0,0.0,0.0)); //using this function call, we set viewdir value as ~(0, -0.2, 1) by subtracting eyepoint value from lookat value

    // Black background color scene
    Scene scene(vec3(0.0,0.0,0.0));

    Sphere s1 = Sphere(0.5, vec3{2,-1,2.5},  vec3{1,1,1});  // sphere structure: explicit Sphere(double radius, vec3 center, vec3 color);
    Sphere s2 = Sphere(1.0, vec3{-5, -1, 6.2},  vec3{1,0,0});
    Sphere s3 = Sphere(1.0, vec3{7, -1, 8},  vec3{0,1,1});
    Sphere s4 = Sphere(1.0, vec3{-12.9, -1, 25.2}, vec3{1,1,0});
    Sphere s5 = Sphere(1.0, vec3{2.9, -1, 15.2},  vec3{0,1,0});

    Sphere spheres[5] = {s1, s2, s3, s4, s5}; //all the 5 sphere objects we created above are added to an array of Spheres called spheres of size 5


    //range-based for loop in C++ that iterates over each element in the spheres array from above.
    for(auto sphere: spheres) {
        scene.addSphere(sphere);  //scene structure has it's first element which is a dynamic array named _spheres, we add
                                    //and basically scene's first element is an array that can contain arbitrary sphere objects
    }

    // After we created a scene, camera, screen, we create a ray tracer that puts it all together and renders the scene
    YourRayTracer renderer;
    renderer.setCamera(camera);
    renderer.setScene(scene);
    renderer.render(screen);

    // I've included a simple way to create png images instead of PPM as PPM takes a lot of space
    screen.saveAsPNG("screen.png");
    return 0;
}

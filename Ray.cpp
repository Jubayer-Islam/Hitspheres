
#include "Ray.hpp"

#include "Intersection.hpp"
#include "Sphere.hpp"

Ray::Ray(vec3 origin, vec3 direction) : _origin(origin), _direction(direction) {}

/* This is the task. Fill in the intersects method. A ray has an origin point and a direction.
 * A sphere has a center point and a radius, a radius_squared (hint), as well as a colour.
 * If the ray hits no object, return a {} (which indicates that there was no intersection).
 * If the ray hits an object, return a intersection.
 * To find out if a ray hits a sphere, you may (and should) use your math skills.
 * An intersection consists of the colour of the object hit by a ray, the surface normal (a unit_vector pointing from
 * the sphere center to the intersection point) as well as a "_t".
 * If you have an intersection, then _t solves the following:
 *  intersection_point = t * direction + origin
 *
 */


//generally we need: a function which will take a ray and a sphere, and return both if the they intersect, and if so, the location of the intersection(s).
//here we need: method, which either returns an Intersection if a sphere was hit, otherwise only {}
//note: this method was used in Scene::intersect
std::optional<Intersection> Ray::intersects(const Sphere& sphere) const {

    //first we get the distance vector from the ray origin to the sphere center
    vec3 dist= sphere._center - this->_origin;  // note: this refers to our ray object we pass in Scene::intersect method, we use ray.intersects(object: _spheres) inside that method

    double d_projection=dot(dist,this->_direction);        // Projection of dist onto the ray's direction

    if (d_projection < 0) {
        return {};            // The sphere is behind the ray, no intersection  //alt: if (t_projection<0) return std::nullopt;
    }


   //now we try to compute the distance from the closest approach to the sphere's surface by using:
    double dist2 = dist.length_squared() - d_projection*d_projection;     // Perpendicular distance squared

    double radius2= sphere._radius * sphere._radius;
    if (dist2>radius2) {
        return {}; //no intersection, the ray misses the sphere
    }


    double d_close = sqrt(radius2 - dist2);  // Distance from the closest point to intersection points
    double t_0 = d_projection - d_close;  // First intersection point
    double t_1 = d_projection + d_close;  // Second intersection point

    //we try to get the nearest positive t which is the first intersection point for our ray
    double t = (t_0 > 0) ? t_0 : t_1;
    if (t < 0) {
        return {};  // The intersection is behind the ray origin
    }


    //vec3 intersection_point = this->_origin + this->_direction * t;
    vec3 intersection_point = point_at(t);
    vec3 normal = unit_vector(intersection_point - sphere._center);


    // Create the Intersection object and return it
    Intersection intersection(sphere._color, normal, t);


    return intersection;


}

vec3 Ray::point_at(float t) const {
    return _origin + t * _direction;
}


/* details:
0 Points: No Intersection (No Hit)

    What happens: The line passes entirely outside the sphere and doesn’t touch it.

    Visual:
    Imagine a straight line that misses the sphere completely. There’s no overlap or contact between the two.

    Condition:
    The perpendicular distance from the sphere’s center to the line is greater than the sphere's radius.
    Mathematically, this happens when the discriminant in the sphere-line intersection equation (derived from the quadratic formula) is negative.

2. 1 Point: Tangential Intersection (Tangent)

    What happens: The line grazes the sphere, touching it at exactly one point.

    Visual:
    Think of a line just "kissing" the surface of the sphere at one specific point.

    Condition:
    The perpendicular distance from the sphere’s center to the line is exactly equal to the sphere's radius.
    Mathematically, this happens when the discriminant in the intersection equation is zero, meaning the line just touches the sphere.

3. 2 Points: Full Intersection

    What happens: The line enters the sphere at one point, passes through, and exits at another point.

    Visual:
    Imagine a line that goes through the sphere, creating two distinct intersection points where it enters and exits the sphere.

    Condition:
    The perpendicular distance from the sphere’s center to the line is less than the sphere's radius.
    Mathematically, this occurs when the discriminant in the intersection equation is positive, yielding two distinct solutions.

 */


#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <cstdint>
#include <vector>
#include "Vector3.hpp"



using color = vec3;

struct Screen{
    uint64_t _width; // uint64_t is an unsigned long long integer which is guaranteed to be exactly 8 bytes=64 bits in size
    uint64_t _height;
    std::vector<color> _data;  // creating an array element of screen named "_data" which is of data type color, color is again alias of Vec3, vec3 stores 3 doubles

    Screen():_width(1024), _height(1024){       //the vector named data is resized by default values if no arguments were passed
        _data.resize(_width*_height);       //resize is a function of vector library which can resize the vector object using width & height
    }
    Screen(uint64_t  width, uint64_t  height):_width(width), _height(height){
        _data.resize(width * height);       //Resizes the _data vector to hold width * height elements
    }

    void setPixel(uint64_t  x, uint64_t  y, vec3 c); //used in YourRayTracer::render
    uint64_t getWidth() const;
    uint64_t getHeight() const;

    void clear();

    void saveAsPPM(const char *filename);
    void saveAsPNG(const char *filename);
};

#endif //SCREEN_HPP

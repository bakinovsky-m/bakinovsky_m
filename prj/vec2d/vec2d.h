#ifndef HG_VEC2D_H
#define HG_VEC2D_H

#include <iostream>
#include <string>
#include <cmath>

class Vec2d {
public:
    Vec2d();
    Vec2d(const double x_, const double y_);
    Vec2d(const double b_x, const double b_y, const double e_x, const double e_y);
    
    bool operator== (const Vec2d v);
    bool operator!= (const Vec2d v);

    Vec2d operator+ (const Vec2d v);
    Vec2d operator- (const Vec2d v);
    Vec2d operator* (const double d);
    Vec2d operator* (const Vec2d v);
    Vec2d& operator= (const Vec2d& v) = default;

    double operator[] (const int ind);

    std::string toString();
    double length();
private:
    double x = 0.0;
    double y = 0.0;
    const double EPSILON = 0.000000000001;
};

#endif
#include <iostream>

class Point3D {
public:
    Point3D(double x, double y, double z): x_(x), y_(y), z_(z) {
    }

    Point3D() : x_(0), y_(0), z_(0) {
    } 

    friend std::ostream& operator<< (std::ostream& out, const Point3D& point);

private:
    double x_;
    double y_;
    double z_;
};


class Vector3D {
public:
    Vector3D(double x, double y, double z): x_(x), y_(y), z_(z) {
    }

    Vector3D() : x_(0), y_(0), z_(0) {
    } 

    friend std::ostream& operator<< (std::ostream& out, const Vector3D& point);

private:
    double x_;
    double y_;
    double z_;
};
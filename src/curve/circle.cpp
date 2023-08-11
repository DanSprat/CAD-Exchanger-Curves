#include "circle.h"
#include <cmath>

Circle::Circle(double radius): radius_(radius) {
    
}

Point3D Circle::getPoint(double t) const {
    return Point3D(radius_ * cos(t), radius_ * sin(t), 0.0);
}

Vector3D Circle::getDerivative(double t) const {
    return Vector3D(-radius_ * sin(t), radius_ * cos(t), 0.0);
}

const double& Circle::getRadius() const {
    return radius_;
}
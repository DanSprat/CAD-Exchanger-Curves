#include "helix.h"
#include <cmath>

Helix::Helix(double radius, double pitch) : radius_(radius), pitch_(pitch) {
}

Point3D Helix::getPoint(double t) const {
    return Point3D(radius_ * cos(t), radius_ * sin(t), pitch_ * t);
}

Vector3D Helix::getDerivative(double t) const {
    return Vector3D(-radius_ * sin(t), radius_ * cos(t), pitch_);
}

const double& Helix::getRadius() const {
    return radius_; 
}

const double& Helix::getPitch() const {
    return pitch_;
}
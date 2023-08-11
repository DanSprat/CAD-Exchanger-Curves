#include "ellipse.h"

#include <cmath>

Ellipse::Ellipse(double x_radius, double y_radius)
    : x_radius_(x_radius), y_radius_(y_radius) {
}

Point3D Ellipse::getPoint(double t) const {
    return Point3D(x_radius_ * cos(t), y_radius_ * sin(t), 0.0);
}

Vector3D Ellipse::getDerivative(double t) const {
    return Vector3D(-x_radius_ * sin(t), y_radius_ * cos(t), 0.0);
}

const double& Ellipse::getXRadius() const {
    return x_radius_;
}

const double& Ellipse::getYRadius() const {
    return y_radius_;
}

#include "utils.h"

std::ostream& operator<<(std::ostream& out, const Point3D& point) {
    out << "{"
        << "x: " << point.x_ << "; "
        << "y: " << point.y_ << "; z: " << point.z_ << "}";
    return out;
}

std::ostream& operator<<(std::ostream& out, const Vector3D& point) {
    out << "{"
        << "x: " << point.x_ << "; "
        << "y: " << point.y_ << "; z: " << point.z_ << "}";
    return out;
}
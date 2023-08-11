#pragma once
#include "utils.h"

class Curve3D {

public:
    virtual Point3D getPoint(double t) const = 0;
    virtual Vector3D getDerivative(double t) const = 0;
};

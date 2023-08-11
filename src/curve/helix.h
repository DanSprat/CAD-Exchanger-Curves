#pragma once
#include "curve.h"

class Helix : public Curve3D {

public:
    Helix(double, double);
    Point3D getPoint(double) const override;
    Vector3D getDerivative(double) const override;
    const double& getRadius() const;
    const double& getPitch() const;

private:
    double radius_;
    double pitch_;
};
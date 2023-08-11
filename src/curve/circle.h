#pragma once
#include "curve.h"

class Circle : public Curve3D {

public:
    explicit Circle(double);
    Point3D getPoint(double) const override;
    Vector3D getDerivative(double) const override;
    const double& getRadius() const;

private:
    double radius_;
};
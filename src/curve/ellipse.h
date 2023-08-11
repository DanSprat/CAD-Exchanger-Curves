#pragma once
#include "curve.h"

class Ellipse : public Curve3D {
    
public:
    Ellipse(double, double);
    Point3D getPoint(double) const override;
    Vector3D getDerivative(double) const override;
    const double& getXRadius() const;
    const double& getYRadius() const;

private:
    double x_radius_;
    double y_radius_;
};
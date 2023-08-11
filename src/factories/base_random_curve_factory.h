#pragma once
#include "../curve/circle.h"
#include "../curve/helix.h"
#include "../curve/ellipse.h"

#include <memory>
#include <random>

class BaseRandomCurveFactory {

public:
    BaseRandomCurveFactory() : rng_(dev_()), radius_dist_(kEPSILON, kMAX_RADIUS) { }
    virtual std::unique_ptr<Curve3D> getRandomCurve() const = 0;

protected:
    static constexpr double kEPSILON = 10e-6;
    static constexpr double kMAX_RADIUS = 100.0;

    std::random_device dev_;
    mutable std::mt19937 rng_;
    mutable std::uniform_real_distribution<> radius_dist_;
};


#include "random_factories.h"

RandomCircleFactory::RandomCircleFactory() : BaseRandomCurveFactory() {
}
std::unique_ptr<Curve3D> RandomCircleFactory::getRandomCurve() const {
    return std::make_unique<Circle>(radius_dist_(rng_));
}

BaseRandomCurveFactory* RandomCircleFactory::getInstance() {
    static RandomCircleFactory circle_factory;
    return &circle_factory;
}

RandomEllipseFactory::RandomEllipseFactory() : BaseRandomCurveFactory() {
}
std::unique_ptr<Curve3D> RandomEllipseFactory::getRandomCurve() const {
    return std::make_unique<Ellipse>(radius_dist_(rng_), radius_dist_(rng_));
}

BaseRandomCurveFactory* RandomEllipseFactory::getInstance() {
    static RandomEllipseFactory ellipse_factory;
    return &ellipse_factory;
}

RandomHelixFactory::RandomHelixFactory()
    : BaseRandomCurveFactory(), pitch_dist_(kEPSILON, kMAX_PITCH) {
}
std::unique_ptr<Curve3D> RandomHelixFactory::getRandomCurve() const {
    return std::make_unique<Helix>(radius_dist_(rng_), radius_dist_(rng_));
}

BaseRandomCurveFactory* RandomHelixFactory::getInstance() {
    static RandomHelixFactory helix_factory;
    return &helix_factory;
}

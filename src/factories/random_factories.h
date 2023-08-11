#include "base_random_curve_factory.h"

class RandomCircleFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();
    RandomCircleFactory(const RandomCircleFactory&) = delete;

private:
    RandomCircleFactory();
};

class RandomEllipseFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();
    RandomEllipseFactory(const RandomEllipseFactory&) = delete;

private:
    RandomEllipseFactory();
};

class RandomHelixFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();
    RandomHelixFactory(const RandomHelixFactory&) = delete;

private:
    RandomHelixFactory();
    static constexpr double kMAX_PITCH = 20.0;
    mutable std::uniform_real_distribution<> pitch_dist_;
};
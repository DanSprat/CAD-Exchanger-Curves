#include "base_random_curve_factory.h"

class RandomCircleFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();

private:
    RandomCircleFactory();
};

class RandomEllipseFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();

private:
    RandomEllipseFactory();
};

class RandomHelixFactory : public BaseRandomCurveFactory {

public:
    std::unique_ptr<Curve3D> getRandomCurve() const override;
    static BaseRandomCurveFactory* getInstance();

private:
    RandomHelixFactory();
    static constexpr double kMAX_PITCH = 20.0;
    mutable std::uniform_real_distribution<> pitch_dist_;
};
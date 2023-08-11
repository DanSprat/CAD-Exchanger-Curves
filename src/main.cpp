#include "factories/random_factories.h"

#include <algorithm>
#include <iostream> 
#include <memory>
#include <omp.h>
#include <vector>
#include <cmath>

using UniqueCurve = std::unique_ptr<Curve3D>;

std::random_device rd;
std::mt19937 rng(rd());

UniqueCurve getRandomCurve() {
    std::uniform_int_distribution<> dist(1,3);
    int type = dist(rng);
    
    switch(type) {
        case 1: {
            return RandomCircleFactory::getInstance()->getRandomCurve();
        }
        case 2: {
            return RandomEllipseFactory::getInstance()->getRandomCurve();
        }
        case 3: {
            return RandomHelixFactory::getInstance()->getRandomCurve();
        }
        default: throw std::runtime_error("Unknown type of curve");
    }
}

int main() {
    std::uniform_int_distribution<> dist(10, 11);
    size_t size = dist(rng);
    std::vector<UniqueCurve> curves;
    curves.reserve(size);

    for (size_t idx = 0; idx < size; ++idx) {
        curves.push_back(getRandomCurve());
    }

    constexpr double kT = M_PI / 4;

    for (auto& curve: curves) {
        std::cout<< "Point: "<< curve->getPoint(kT)<<std::endl;
        std::cout<< "Derivative: "<< curve->getDerivative(kT)<<std::endl;
    }

    std::vector<Circle*> circles;
    for (auto& curve: curves) {
        if (auto* ptr = dynamic_cast<Circle*>(curve.get()); ptr) {
            circles.push_back(ptr);
        } 
    }

    constexpr double kEPSILON = 10e-10;
    auto circle_cmp = [&kEPSILON] (Circle* lhs, Circle* rhs) -> bool {
        if (abs(lhs->getRadius() - rhs->getRadius()) < kEPSILON) {
          return false;  
        }
        return lhs->getRadius() < rhs->getRadius();
    };

    std::sort(circles.begin(), circles.end(), circle_cmp);
    for (auto* circle: circles) {
        std::cout<<circle-> getRadius()<<" ";
    }
    std::cout<<std::endl;

    double total_sum = 0.0;
    #pragma omp parallel for reduction(+:total_sum)
    for (auto* circle: circles) {
        total_sum += circle-> getRadius();
    }
    std::cout<<"Total sum of radii of all circles is: " << total_sum <<std::endl;
}
//
// Created by PC on 2026/4/22.
//

#ifndef GAMES101_TRANSFORM2D_H
#define GAMES101_TRANSFORM2D_H
#include <Eigen/Core>

class Transform2d {
public:
    Transform2d();
    Transform2d& Translate(const Eigen::Vector2d& delta);
    Transform2d& Rotate(double rad);
    Eigen::Vector3d Apply(const Eigen::Vector3d& vec) const {
        return transform_ * vec;
    }
private:
    Eigen::Matrix3d transform_;
};

#endif //GAMES101_TRANSFORM2D_H

//
// Created by PC on 2026/4/22.
//

#ifndef GAMES101_TRANSFORM2D_H
#define GAMES101_TRANSFORM2D_H
#include<Eigen/Core>

class Transform2d {
public:
    explicit Transform2d(Eigen::Vector3d vec);
    Transform2d& translate(const Eigen::Vector2d& delta);
    Transform2d& rotate(double rad);
    const Eigen::Vector3d& vec() const {
        return vec_;
    }
private:
    Eigen::Vector3d vec_;
};

#endif //GAMES101_TRANSFORM2D_H

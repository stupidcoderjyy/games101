//
// Created by PC on 2026/4/22.
//

#include "Transform2d.h"

Transform2d::Transform2d(Eigen::Vector3d vec): vec_(std::move(vec)) {
}

Transform2d& Transform2d::translate(const Eigen::Vector2d &delta) {
    Eigen::Matrix3d matrix;
    matrix << 1, 0, delta.x(),
              0, 1, delta.y(),
              0, 0, 1;
    vec_ = matrix * vec_;
    return *this;
}

Transform2d& Transform2d::rotate(double rad) {
    double c = std::cos(rad), s = std::sin(rad);
    Eigen::Matrix3d matrix;
    matrix << c, -s, 0,
              s, c, 0,
              0, 0, 1;
    vec_ = matrix * vec_;
    return *this;
}
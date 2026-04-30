//
// Created by PC on 2026/4/22.
//
#include <gtest/gtest.h>
#include <cmath>
#include "Transform2d.h"

constexpr double EPS = 1e-5;

Eigen::Vector3d Point(double x, double y) {
    return {x, y, 1.0};
}

// Tests default construction.
TEST(Transform2dTest, Constructor) {
    Transform2d transform;
    const auto result = transform.Apply(Point(1.0, 2.0));

    EXPECT_DOUBLE_EQ(result.x(), 1.0);
    EXPECT_DOUBLE_EQ(result.y(), 2.0);
    EXPECT_DOUBLE_EQ(result.z(), 1.0);
}

// Tests translation.
TEST(Transform2dTest, Translate) {
    Transform2d transform;

    transform.Translate(Eigen::Vector2d(3.0, 4.0));
    const auto result = transform.Apply(Point(1.0, 2.0));

    EXPECT_NEAR(result.x(), 4.0, EPS);
    EXPECT_NEAR(result.y(), 6.0, EPS);
    EXPECT_NEAR(result.z(), 1.0, EPS);
}

// Tests rotation.
TEST(Transform2dTest, Rotate) {
    Transform2d transform;

    transform.Rotate(M_PI / 2.0);
    const auto result = transform.Apply(Point(1.0, 0.0));

    EXPECT_NEAR(result.x(), 0.0, EPS);
    EXPECT_NEAR(result.y(), 1.0, EPS);
    EXPECT_NEAR(result.z(), 1.0, EPS);
}

// Tests chained transforms.
TEST(Transform2dTest, Chaining) {
    Transform2d transform;

    transform.Rotate(M_PI / 2.0).Translate({1, 2});
    const auto result = transform.Apply(Point(1.0, 0.0));

    EXPECT_NEAR(result.x(), 1.0, EPS);
    EXPECT_NEAR(result.y(), 3.0, EPS);
    EXPECT_NEAR(result.z(), 1.0, EPS);
}

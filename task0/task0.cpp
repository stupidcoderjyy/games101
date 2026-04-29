//
// Created by PC on 2026/4/22.
//
#include <gtest/gtest.h>
#include <cmath>
#include "Transform2d.h"

constexpr double EPS = 1e-5;

// 测试构造函数
TEST(Transform2dTest, Constructor) {
    Transform2d transform({1.0, 2.0, 1.0});

    EXPECT_FLOAT_EQ(transform.vec().x(), 1.0);
    EXPECT_FLOAT_EQ(transform.vec().y(), 2.0);
    EXPECT_FLOAT_EQ(transform.vec().z(), 1.0);
}

// 测试平移
TEST(Transform2dTest, Translate) {
    Transform2d transform({1.0, 2.0, 1.0});

    transform.Translate(Eigen::Vector2d(3.0, 4.0));

    EXPECT_NEAR(transform.vec().x(), 4.0, EPS);
    EXPECT_NEAR(transform.vec().y(), 6.0, EPS);
    EXPECT_NEAR(transform.vec().z(), 1.0, EPS);
}

// 测试旋转
TEST(Transform2dTest, Rotate) {
    Transform2d transform({1.0, 0.0, 1.0});

    transform.Rotate(M_PI / 2.0);

    EXPECT_NEAR(transform.vec().x(), 0.0, EPS);
    EXPECT_NEAR(transform.vec().y(), 1.0, EPS);
    EXPECT_NEAR(transform.vec().z(), 1.0, EPS);
}

// 测试链式调用
TEST(Transform2dTest, Chaining) {
    Transform2d transform({1.0, 0.0, 1.0});

    transform.Translate({1.0, 1.0})
             .Rotate(M_PI / 2.0);

    EXPECT_NEAR(transform.vec().x(), -1.0, EPS);
    EXPECT_NEAR(transform.vec().y(), 2.0, EPS);
}
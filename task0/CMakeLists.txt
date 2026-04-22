set(TARGET task0)

project(${TARGET})

add_executable(${TARGET}
        task0.cpp
        Transform2d.h
        Transform2d.cpp
)

target_link_libraries(${TARGET} PRIVATE
        Eigen3::Eigen
        GTest::gtest_main
)

gtest_discover_tests(${TARGET})
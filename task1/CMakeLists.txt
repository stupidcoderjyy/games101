set(TARGET task1)

project(${TARGET})

add_executable(${TARGET}
        main.cpp
        rasterizer.hpp
        rasterizer.cpp
        Triangle.hpp
        Triangle.cpp
)

target_link_libraries(${TARGET} PRIVATE
        Eigen3::Eigen
        ${OpenCV_LIBS}
)
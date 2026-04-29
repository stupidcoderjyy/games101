cmake_minimum_required(VERSION 4.0)

project(games101)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MINGW_DIR "C:/msys64/mingw64")
set(OPENCV_DIR "${MINGW_DIR}/lib/cmake/opencv4")

list(APPEND CMAKE_PREFIX_PATH
        "${MINGW_DIR}"
        "${OPENCV_DIR}"
)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)

# gtest
include(FetchContent)
FetchContent_Declare(
        googletest
        SOURCE_DIR "${PROJECT_SOURCE_DIR}/thirdparty/googletest-1.17.0"
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_subdirectory(task0)
add_subdirectory(task1)

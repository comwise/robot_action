cmake_minimum_required(VERSION 3.2) 

project(robot_action)

set(CMAKE_CXX_FLAGS "-g -std=c++17")

# 查找依赖
find_package(Python 3.8 REQUIRED COMPONENTS Development)
find_package(V8 REQUIRED)

# 包含第三方库
include_directories(${CMAKE_SOURCE_DIR}/thirdparty/pybind11/include)

include_directories(${PROJECT_SOURCE_DIR}/include/robot_action)
include_directories(${PROJECT_SOURCE_DIR}/src)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

link_directories(${PROJECT_SOURCE_DIR}/lib)

#enable_testing()
add_subdirectory(src)
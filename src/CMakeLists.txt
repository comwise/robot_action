cmake_minimum_required(VERSION 3.2)

add_subdirectory(test)

add_library(robot_action SHARED
    src/scheduler.cpp
    src/python_action.cpp
    #src/js_action.cpp
)

target_include_directories(robot_action PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${Python_INCLUDE_DIRS}
    #${V8_INCLUDE_DIR}
)

target_link_libraries(robot_action
    ${Python_LIBRARIES}
    #${V8_LIBRARIES}
    pthread
)

# 可执行文件
#add_executable(robot_action src/main.cpp)
#target_link_libraries(robot_action robot_action)
cmake_minimum_required(VERSION 3.0.0)
project(Correction)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB SRC_FILES
    "${PROJECT_SOURCE_DIR}/*.cpp"
"${PROJECT_SOURCE_DIR}/*.c"
    "${PROJECT_SOURCE_DIR}/*.h"
    
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES})




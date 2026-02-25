cmake_minimum_required(VERSION 3.10)
project(AlgorithmCollection)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build/bin)


# add_subdirectory(${PROJECT_SOURCE_DIR}/hot100)
add_subdirectory(${PROJECT_SOURCE_DIR}/01_backTracking)
add_subdirectory(${PROJECT_SOURCE_DIR}/03_linkedList)
add_subdirectory(${PROJECT_SOURCE_DIR}/05_dynamicProgramming)
add_subdirectory(${PROJECT_SOURCE_DIR}/06_doublePointer)
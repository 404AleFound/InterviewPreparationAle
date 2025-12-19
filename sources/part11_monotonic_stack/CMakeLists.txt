# part11_monotonic_stack 
add_library(part11_monotonic_stack STATIC)

target_sources(part11_monotonic_stack PRIVATE
    dailyTemperatures739.cpp
    largestRectangleArea84.cpp
    nextGreaterElement496.cpp
    nextGreaterElements503.cpp
    trap42.cpp
)

target_include_directories(part11_monotonic_stack PUBLIC ${PROJECT_SOURCE_DIR}/include)
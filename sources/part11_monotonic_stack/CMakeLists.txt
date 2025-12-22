# part11_monotonic_stack 
add_library(part11_monotonic_stack STATIC)

file(GLOB SOURCES "*.cpp")

target_sources(part11_monotonic_stack PRIVATE ${SOURCES})

target_include_directories(part11_monotonic_stack PUBLIC ${PROJECT_SOURCE_DIR}/include)
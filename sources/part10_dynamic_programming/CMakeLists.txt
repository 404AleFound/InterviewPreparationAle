# part10_dynamic_programing
add_library(part10_dynamic_programming STATIC)

file(GLOB SOURCES "*.cpp")

target_sources(part10_dynamic_programming PRIVATE ${SOURCES})

target_include_directories(part10_dynamic_programming PUBLIC ${PROJECT_SOURCE_DIR}/include )
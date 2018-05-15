
project(algo)

set(HEDEAR_FILES Algo.h)
set(SOURCE_FILES Algo.cpp)

add_library(libalgotest STATIC ${SOURCE_FILES})
target_include_directories(libalgotest PUBLIC .)

add_executable(algo ${SOURCE_FILES} main.cpp)

target_link_libraries(algo libalgotest)


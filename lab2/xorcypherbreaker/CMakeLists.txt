
project(xorcypherbreaker)

set(HEDEAR_FILES XORCypherBreaker.h)
set(SOURCE_FILES XORCypherBreaker.cpp)

add_library(libxorcypherbreaker STATIC ${SOURCE_FILES})
target_include_directories(libxorcypherbreaker PUBLIC .)

add_executable(xorcypherbreaker ${SOURCE_FILES} main.cpp)

target_link_libraries(xorcypherbreaker libxorcypherbreaker)


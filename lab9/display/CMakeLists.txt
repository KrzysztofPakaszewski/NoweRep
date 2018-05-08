
project(display)

set(HEDEAR_FILES Display.h)
set(SOURCE_FILES Display.cpp)

add_library(libdisplay STATIC ${SOURCE_FILES})
target_include_directories(libdisplay PUBLIC .)

add_executable(display ${SOURCE_FILES} main.cpp)

target_link_libraries(display libdisplay)


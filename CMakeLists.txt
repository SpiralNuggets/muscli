cmake_minimum_required(VERSION 3.0.0)
project(muscli VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(muscli sdl.c)
include_directories(${CMAKE_SOURCE_DIR/include})
link_directories(${CMAKE_SOURCE_DIR}/lib)
target_link_libraries(muscli SDL2_mixer)
target_link_libraries(muscli SDL2)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
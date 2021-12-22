cmake_minimum_required(VERSION 3.0.0)
project(muscli VERSION 0.2.0)

include(CTest)
enable_testing()
include_directories(include)

add_executable(muscli main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

target_include_directories(muscli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_directories(muscli PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(muscli raylib)
target_link_libraries(muscli winmm.lib)

include(CPack)

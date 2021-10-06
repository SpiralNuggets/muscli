 cmake_minimum_required(VERSION 3.20)
 project(project)

 set(CMAKE_CXX_STANDARD 14)
 link_libraries("winmm.lib")

 add_executable(project mainau.cpp)
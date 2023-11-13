cmake_minimum_required(VERSION 3.20)

project(
  macos_vtk
  VERSION 0.1.0
  LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)

find_package(VTK REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PUBLIC
  VTK::CommonDataModel VTK::IOCore
  VTK::IOXML VTK::FiltersCore)

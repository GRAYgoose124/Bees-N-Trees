cmake_minimum_required(VERSION 2.8)
project(BeesNTrees)

set(EXECUTABLE_NAME "BnT")
set(BeesNTrees_VERSION_MAJOR 0)
set(BeesNTrees_VERSION_MINOR 01)

set(CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}/build)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.hpp.in"
  "${PROJECT_SOURCE_DIR}/config.hpp"
  )

set(SRC_CPP BnT.cpp 
App.cpp
Game.cpp
EventHandler.cpp
ResourceManager.cpp
PhysicsEngine.cpp
AIEngine.cpp
)
set(HDR_CPP
App.hpp
Game.hpp
EventHandler.hpp
ResourceManager.hpp
PhysicsEngine.hpp
AIEngine.hpp
)

add_executable(${EXECUTABLE_NAME} ${SRC_CPP} ${HDR_CPP})

add_definitions(-std=c++11)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

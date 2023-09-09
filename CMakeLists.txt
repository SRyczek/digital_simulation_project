cmake_minimum_required(VERSION 3.15)
#project name
project(SimulationProject)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Weverything -gcc ")

#add folder with files
add_subdirectory(include)               
add_subdirectory(src)
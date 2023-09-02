cmake_minimum_required(VERSION 3.15)
#project name
project(SimulationProject)

#reading the CC environment variable 
#if(DEFINED ENV{CC})
#    set(CMAKE_CPP_COMPILER $ENV{CC})
#endif()

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#ind_package(Threads REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Weverything -g -pthread")

#add folder with files
add_subdirectory(include)               
add_subdirectory(src)
project(SimulationProject)  #the same name as root project

add_executable(main main.cpp)

add_library(include user.cpp base.cpp) 

target_link_libraries(main PUBLIC include)

target_include_directories(
   include
   PUBLIC      
   ${CAKE_CURRENT_SOURCE_DIR}/..
)
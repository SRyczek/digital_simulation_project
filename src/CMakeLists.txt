project(SimulationProject)  #the same name as root project

add_executable(main main.cpp)

add_library(include SHARED user.cpp base.cpp simulator.cpp network.cpp logger.cpp) 

target_include_directories(include
   PUBLIC      
      ${CAKE_CURRENT_SOURCE_DIR}/..
)

target_link_libraries(main 
   PUBLIC 
      include)
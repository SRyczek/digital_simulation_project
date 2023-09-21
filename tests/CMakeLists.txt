
# main code
add_executable(bufferTest test1.cpp)
target_link_libraries(bufferTest PRIVATE include)

add_test(Test1 bufferTest test1)
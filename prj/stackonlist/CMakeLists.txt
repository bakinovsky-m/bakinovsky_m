project(stackonlist)
add_definitions(-std=c++11)
add_executable(${PROJECT_NAME} stackonlist.cpp node/node.cpp test.cpp)
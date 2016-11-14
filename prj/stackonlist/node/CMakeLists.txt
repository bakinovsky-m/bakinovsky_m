project(node)
add_definitions(-std=c++11)
add_executable(${PROJECT_NAME} node.cpp test.cpp)
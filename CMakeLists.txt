cmake_minimum_required(VERSION 3.17)
project(Calendar-Event-Management)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp Event.cpp Event.h Todo.cpp Todo.h Functions.h)

#include_directories(C:/sqlite)
#link_directories(C:/sqlite)
#target_link_libraries(${PROJECT_NAME} sqlite3)
cmake_minimum_required(VERSION 3.17)
project(CalendarEventManagement)

set(CMAKE_CXX_STANDARD 20)

add_executable(CalendarEventManagement main.cpp Event.cpp Event.h Todo.cpp Todo.h Functions.cpp)

#include_directories(C:/sqlite)
#link_directories(C:/sqlite)
#target_link_libraries(${PROJECT_NAME} sqlite3)
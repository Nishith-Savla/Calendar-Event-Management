cmake_minimum_required(VERSION 3.17)
project(CalendarEventManagement)

set(INCLUDE_DIRS "C:/sqlite/")
set(LIBRARIES sqlite3.dll)
set(CMAKE_CXX_STANDARD 20)

add_executable(CalendarEventManagement main.cpp Event.cpp Event.h Todo.cpp Todo.h)
# For compiler warnings
target_compile_options(${PROJECT_NAME} PUBLIC -Wall)
# Including SQLite3's headers
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS})
# Linking against sqlite3.dll
find_file(SQLITE3_LIBRARY NAMES sqlite3.dll PATHS "C:/sqlite")
find_library(SQLITE3_LIBRARY NAMES sqlite3)
target_link_libraries(${PROJECT_NAME} ${SQLITE3_LIBRARY})

#include_directories(C:/sqlite)
#link_directories(C:/sqlite)
#target_link_libraries(${PROJECT_NAME} sqlite3)

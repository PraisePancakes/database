cmake_minimum_required(VERSION 3.28.0)

set(PROJECT_NAME DB)

project(${PROJECT_NAME} VERSION 0.0.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME} src/main.cpp src/user.cpp src/database.cpp src/utils/stringify.cpp src/schema.cpp src/hashtable.cpp)



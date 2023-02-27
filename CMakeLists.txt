cmake_minimum_required (VERSION 3.5)

set(PROJECT_NAME SaberTest)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCES 
	main.cpp 
	src/Constants.h 
	src/ListNode.h 
	src/ListRand.h 
	src/ListRand.cpp)

project(${PROJECT_NAME} CXX)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)

message(STATUS "\nUse C++20")
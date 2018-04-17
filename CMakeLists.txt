project(robotics_algos)
cmake_minimum_required(VERSION 3.1)
add_definitions(-Wall -Wpedantic -Wextra -Werror "-std=c++1z")
find_package( Boost 1.40 COMPONENTS program_options REQUIRED )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories( ${Boost_INCLUDE_DIR} )

add_library(${PROJECT_NAME} SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Kalman_filter/kalman_filter.cpp
)

install(DIRECTORY include/${PROJECT_NAME} DESTINATION include
	FILES_MATCHING PATTERN "*.h")
	
add_executable(kalman_filter ${CMAKE_CURRENT_SOURCE_DIR}/src/Kalman_filter/kalman_filter_test.cpp)
target_link_libraries(kalman_filter ${PROJECT_NAME} ${Boost_LIBRARIES})


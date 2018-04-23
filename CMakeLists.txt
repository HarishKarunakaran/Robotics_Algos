project(robotics_algos)
cmake_minimum_required(VERSION 3.1)
add_definitions(-Wall -Wpedantic -Werror "-std=c++1y")
find_package( Boost 1.40 COMPONENTS program_options REQUIRED )

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
    execute_process(
        COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
    if (NOT (GCC_VERSION VERSION_GREATER 6.3 OR GCC_VERSION VERSION_EQUAL 6.3))
        message(FATAL_ERROR "${PROJECT_NAME} requires g++ 6.3 or greater.")
    endif ()
elseif ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
else ()
    message(FATAL_ERROR "Your C++ compiler does not support C++14.")
endif ()


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories( ${Boost_INCLUDE_DIR} )

add_library(${PROJECT_NAME} SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Kalman_filter/kalman_filter.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/A*/astar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ARA*/arastar.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ANA*/anastar.cpp
)

install(DIRECTORY include/${PROJECT_NAME} DESTINATION include
	FILES_MATCHING PATTERN "*.h")
	
add_executable(kalman_filter ${CMAKE_CURRENT_SOURCE_DIR}/src/Kalman_filter/kalman_filter_test.cpp)
add_executable(astar ${CMAKE_CURRENT_SOURCE_DIR}/src/A*/astar_test.cpp)
add_executable(arastar ${CMAKE_CURRENT_SOURCE_DIR}/src/ARA*/arastar_test.cpp)
add_executable(anastar ${CMAKE_CURRENT_SOURCE_DIR}/src/ANA*/anastar_test.cpp)
target_link_libraries(kalman_filter ${PROJECT_NAME} ${Boost_LIBRARIES})
target_link_libraries(astar ${PROJECT_NAME})
target_link_libraries(arastar ${PROJECT_NAME})
target_link_libraries(anastar ${PROJECT_NAME})


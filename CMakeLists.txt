cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")

include("cmake/HunterGate.cmake")
HunterGate(
        URL "https://github.com/cpp-pm/hunter/archive/v0.23.297.tar.gz"
        SHA1 "3319fe6a3b08090df7df98dee75134d68e2ef5a3"
        #        LOCAL
)
SET(HUNTER_STATUS_DEBUG ON)

project(pool-stratum)

hunter_add_package(nlohmann_json)
find_package(nlohmann_json CONFIG REQUIRED)

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.71.0 REQUIRED)
if(Boost_FOUND)
    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${BOOST_LIBRARYDIR}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()
include_directories(${Boost_INCLUDE_DIRS})

find_package(nlohmann_json REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main jsonrpccxx stratum)
include_directories(include/jsonrpccxx)
#target_include_directories(main PRIVATE include/jsonrpccxx)

add_subdirectory(include)
add_subdirectory(stratum)
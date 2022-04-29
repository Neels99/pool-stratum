project(stratum)

SET(SOURCE stratum_protocol.h stratum_protocol.cpp stratum.h stratum.cpp)

add_library(stratum ${SOURCE})
target_include_directories(stratum PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(stratum jsonrpccxx)